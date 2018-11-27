#include "AvatarSamples.h"
#include "RemoteAvatar.h"
#include "OvrAvatarManager.h"
#include "Object.h"
#include "OvrAvatar.h"

uint32_t gIDIndex = 0;
uint64_t OnlineID[] = { 10150022857785745, 10150022857770130, 10150022857753417, 10150022857731826, 10150022857785745 };

ARemoteAvatar::ARemoteAvatar()
{
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RemoteAvatarRoot"));
	AvatarComponent = CreateDefaultSubobject<UOvrAvatar>(TEXT("RemoteAvatar"));

	AvatarComponent->SetVisibilityType(ovrAvatarVisibilityFlag_ThirdPerson);
	AvatarComponent->SetPlayerType(UOvrAvatar::ePlayerType::Remote);

	PrimaryActorTick.bCanEverTick = true;
	PacketKey = GetName();
}

void ARemoteAvatar::BeginPlay()
{
	Super::BeginPlay();

	const uint64_t LoginID = OnlineID[gIDIndex > 4 ? gIDIndex = 0 : gIDIndex++];
	AvatarComponent->RequestAvatar(LoginID);

	FOvrAvatarManager::Get().RegisterRemoteAvatar(PacketKey);

	SetActorHiddenInGame(true);
}

void ARemoteAvatar::BeginDestroy()
{
	Super::BeginDestroy();

	FOvrAvatarManager::Get().UnregisterRemoteAvatar(PacketKey);
}

void ARemoteAvatar::Tick(float DeltaSeconds)
{
	LatencyTick += DeltaSeconds;

	if (!CurrentPacket && LatencyTick > FakeLatency)
	{
		CurrentPacket = FOvrAvatarManager::Get().RequestAvatarPacket(PacketKey);
		SetActorHiddenInGame(false);
	}

	if (CurrentPacket)
	{
		const float PacketLength = ovrAvatarPacket_GetDurationSeconds(CurrentPacket);
		AvatarComponent->UpdateFromPacket(CurrentPacket, FMath::Min(PacketLength, CurrentPacketTime));
		CurrentPacketTime += DeltaSeconds;

		if (CurrentPacketTime > PacketLength)
		{
			ovrAvatarPacket_Free(CurrentPacket);
			CurrentPacket = nullptr;
			CurrentPacketTime = CurrentPacketTime - PacketLength;
		}
	}
}

