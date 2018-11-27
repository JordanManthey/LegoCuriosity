#pragma once

#include "AvatarSamples.h"
#include "GameFramework/Pawn.h"
#include "OVR_Avatar.h"
#include "RemoteAvatar.generated.h"

class UOvrAvatar;

UCLASS()
class AVATARSAMPLES_API ARemoteAvatar : public APawn
{
	GENERATED_BODY()
public:
	ARemoteAvatar();

	void BeginPlay() override;
	void BeginDestroy() override;
	void Tick(float DeltaSeconds) override;

private:
	UOvrAvatar* AvatarComponent = nullptr;
	ovrAvatarPacket* CurrentPacket = nullptr;

	float CurrentPacketTime = 0.f;
	float FakeLatency = 0.5f;
	float LatencyTick = 0.f;

	FString PacketKey;
};
