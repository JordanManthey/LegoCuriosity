// Fill out your copyright notice in the Description page of Project Settings.

#include "AvatarSamples.h"
#include "LocalAvatar.h"
#include "OvrAvatarManager.h"
#include "RemoteAvatar.h"
#include "Object.h"

static const uint32_t HAND_JOINTS = 25;

ovrAvatarTransform gAvatarLeftHandTrans[] =
{
	{ { 0.0000f,0.0000f,0.0000f },{ 0.0000f, 0.0000f, 0.0000f, 1.0000f },{ 1.0000f,1.0000f,1.0000f } },
	{ { -0.0400f,-0.0250f,0.1091f },{ -0.6825f, 0.1749f, 0.7085f, 0.0411f },{ 1.0000f,1.0000f,1.0000f } },
	{ { 0.0735f,-0.0140f,-0.0240f },{ -0.3899f, 0.7092f, -0.1519f, 0.5674f },{ 1.0000f,1.0000f,1.0000f } },
	{ { 0.1361f,0.0000f,-0.0000f },{ -0.2270f, 0.0000f, -0.0000f, 0.9739f },{ 1.0000f,1.0000f,1.0000f } },

	{ { 0.0871f,-0.0351f,0.0068f },{ -0.3804f, 0.6000f, -0.5778f, -0.4017f },{ 1.0000f,1.0000f,1.0000f } }, //Index
	{ { -0.0416f,-0.0000f,-0.0000f },{ -0.0000f, 0.0000f, -0.0000f, 1.0000f },{ 1.0000f,1.0000f,1.0000f } },
	{ { -0.0222f,0.0000f,0.0000f },{ -0.0000f, 0.0000f, -0.0000f, 1.0000f },{ 1.0000f,1.0000f,1.0000f } },
	{ { -0.0291f,0.0000f,0.0000f },{ 0.0000f, 0.0000f, 0.0000f, 1.0000f },{ 1.0000f,1.0000f,1.0000f } },

	{ { 0.0914f,-0.0095f,0.0108f },{ 0.4631f, -0.4423f, 0.5945f, 0.4863f },{ 1.0000f,1.0000f,1.0000f } }, //Middle
	{ { -0.0460f,-0.0000f,-0.0000f },{ 0.0000f, -0.0000f, -0.8362f, 0.5484f },{ 1.0000f,1.0000f,1.0000f } },
	{ { -0.0296f,0.0000f,0.0000f },{ -0.0000f, -0.0000f, -0.7300f, 0.6834f },{ 1.0000f,1.0000f,1.0000f } },
	{ { -0.0265f,0.0000f,-0.0000f },{ -0.0000f, 0.0000f, -0.0000f, 1.0000f },{ 1.0000f,1.0000f,1.0000f } },

	{ { 0.0313f,0.0191f,-0.0115f },{ 0.4713f, 0.0618f, 0.0753f, 0.8766f },{ 1.0000f,1.0000f,1.0000f } }, //Pinky
	{ { 0.0536f,0.0024f,0.0015f },{ 0.1300f, 0.0348f, 0.6327f, 0.7626f },{ 1.0000f,1.0000f,1.0000f } },
	{ { -0.0334f,0.0000f,-0.0000f },{ 0.0000f, 0.0000f, 0.0000f, 1.0000f },{ 1.0000f,1.0000f,1.0000f } },
	{ { -0.0174f,-0.0000f,0.0000f },{ 0.0000f, 0.0000f, 0.0000f, 1.0000f },{ 1.0000f,1.0000f,1.0000f } },
	{ { -0.0194f,0.0000f,0.0000f },{ 0.0000f, 0.0000f, 0.0000f, 1.0000f },{ 1.0000f,1.0000f,1.0000f } },

	{ { 0.0895f,0.0127f,0.0019f },{ 0.4589f, -0.3678f, 0.6193f, 0.5203f },{ 1.0000f,1.0000f,1.0000f } }, //Ring
	{ { -0.0386f,0.0000f,-0.0000f },{ -0.0000f, -0.0000f, -0.8446f, 0.5354f },{ 1.0000f,1.0000f,1.0000f } },
	{ { -0.0258f,-0.0000f,0.0000f },{ 0.0000f, -0.0000f, -0.7372f, 0.6757f },{ 1.0000f,1.0000f,1.0000f } },
	{ { -0.0242f,-0.0000f,0.0000f },{ -0.0000f, -0.0000f, -0.0000f, 1.0000f },{ 1.0000f,1.0000f,1.0000f } },

	{ { 0.0309f,-0.0415f,-0.0206f },{ 0.1999f, 0.9526f, 0.0626f, -0.2205f },{ 1.0000f,1.0000f,1.0000f } }, //Thumb
	{ { -0.0326f,0.0000f,-0.0000f },{ -0.0087f, 0.0964f, -0.2674f, 0.9587f },{ 1.0000f,1.0000f,1.0000f } },
	{ { -0.0264f,0.0000f,-0.0000f },{ -0.0000f, 0.0000f, -0.5985f, 0.8011f },{ 1.0000f,1.0000f,1.0000f } },
	{ { -0.0341f,0.0000f,0.0000f },{ -0.0000f, -0.0000f, 0.0000f, 1.0000f },{ 1.0000f,1.0000f,1.0000f } },
};

ovrAvatarTransform gAvatarRightHandTrans[] =
{
	{ { 0.0000f,0.0000f,0.0000f },{ 0.0000f, 0.0000f, 0.0000f, 1.0000f },{ 1.0000f,1.0000f,1.0000f } },
	{ { 0.0400f,-0.0250f,0.1091f },{ 0.0411f, -0.7085f, 0.1749f, 0.6825f },{ 1.0000f,1.0000f,1.0000f } },
	{ { -0.0735f,0.0140f,0.0240f },{ -0.5702f, -0.0164f, 0.8065f, -0.1554f },{ 1.0000f,1.0000f,1.0000f } },
	{ { -0.1361f,0.0000f,-0.0000f },{ -0.2270f, -0.0000f, 0.0000f, 0.9739f },{ 1.0000f,1.0000f,1.0000f } },

	{ { -0.0871f,0.0351f,-0.0068f },{ -0.3804f, 0.6000f, -0.5778f, -0.4017f },{ 1.0000f,1.0000f,1.0000f } },
	{ { 0.0416f,-0.0000f,0.0000f },{ 0.0000f, 0.0000f, 0.0000f, 1.0000f },{ 1.0000f,1.0000f,1.0000f } },
	{ { 0.0222f,-0.0000f,0.0000f },{ 0.0000f, 0.0000f, 0.0000f, 1.0000f },{ 1.0000f,1.0000f,1.0000f } },
	{ { 0.0291f,0.0000f,-0.0000f },{ -0.0000f, -0.0000f, -0.0000f, 1.0000f },{ 1.0000f,1.0000f,1.0000f } },

	{ { -0.0914f,0.0095f,-0.0108f },{ 0.4631f, -0.4423f, 0.5945f, 0.4863f },{ 1.0000f,1.0000f,1.0000f } },
	{ { 0.0460f,0.0000f,0.0000f },{ 0.0000f, -0.0000f, -0.8362f, 0.5484f },{ 1.0000f,1.0000f,1.0000f } },
	{ { 0.0296f,-0.0000f,0.0000f },{ 0.0000f, -0.0000f, -0.7300f, 0.6834f },{ 1.0000f,1.0000f,1.0000f } },
	{ { 0.0265f,0.0000f,-0.0000f },{ 0.0000f, -0.0000f, 0.0000f, 1.0000f },{ 1.0000f,1.0000f,1.0000f } },

	{ { -0.0313f,-0.0191f,0.0115f },{ 0.4713f, 0.0618f, 0.0753f, 0.8766f },{ 1.0000f,1.0000f,1.0000f } },
	{ { -0.0536f,-0.0024f,-0.0015f },{ 0.1300f, 0.0348f, 0.6327f, 0.7626f },{ 1.0000f,1.0000f,1.0000f } },
	{ { 0.0334f,0.0000f,-0.0000f },{ 0.0000f, 0.0000f, 0.0000f, 1.0000f },{ 1.0000f,1.0000f,1.0000f } },
	{ { 0.0174f,-0.0000f,0.0000f },{ 0.0000f, 0.0000f, 0.0000f, 1.0000f },{ 1.0000f,1.0000f,1.0000f } },
	{ { 0.0194f,0.0000f,-0.0000f },{ 0.0000f, 0.0000f, 0.0000f, 1.0000f },{ 1.0000f,1.0000f,1.0000f } },

	{ { -0.0895f,-0.0127f,-0.0019f },{ 0.4589f, -0.3678f, 0.6193f, 0.5203f },{ 1.0000f,1.0000f,1.0000f } },
	{ { 0.0386f,0.0000f,0.0000f },{ -0.0000f, -0.0000f, -0.8446f, 0.5354f },{ 1.0000f,1.0000f,1.0000f } },
	{ { 0.0258f,0.0000f,-0.0000f },{ -0.0000f, 0.0000f, -0.7372f, 0.6757f },{ 1.0000f,1.0000f,1.0000f } },
	{ { 0.0242f,-0.0000f,-0.0000f },{ 0.0000f, 0.0000f, -0.0000f, 1.0000f },{ 1.0000f,1.0000f,1.0000f } },

	{ { -0.0309f,0.0415f,0.0206f },{ 0.1999f, 0.9526f, 0.0626f, -0.2205f },{ 1.0000f,1.0000f,1.0000f } },
	{ { 0.0326f,0.0000f,0.0000f },{ -0.0087f, 0.0964f, -0.2674f, 0.9587f },{ 1.0000f,1.0000f,1.0000f } },
	{ { 0.0264f,-0.0000f,-0.0000f },{ 0.0000f, -0.0000f, -0.5985f, 0.8011f },{ 1.0000f,1.0000f,1.0000f } },
	{ { 0.0341f,0.0000f,-0.0000f },{ 0.0000f, -0.0000f, -0.0000f, 1.0000f },{ 1.0000f,1.0000f,1.0000f } },
};

ALocalAvatar::ALocalAvatar()
{
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("LocalAvatarRoot"));

	PrimaryActorTick.bCanEverTick = true;
	AutoPossessPlayer = EAutoReceiveInput::Player0;

	// TODO SW: Fetch Player Height from Oculus Platform?
	BaseEyeHeight = 170.f;

	AvatarComponent = CreateDefaultSubobject<UOvrAvatar>(TEXT("LocalAvatar"));
	AvatarComponent->SetVisibilityType(ovrAvatarVisibilityFlag_FirstPerson);
	AvatarComponent->SetPlayerHeightOffset(BaseEyeHeight / 100.f);
}

void ALocalAvatar::BeginPlay()
{
	Super::BeginPlay();

	IOnlineIdentityPtr IdentityInterface = Online::GetIdentityInterface();
	if (IdentityInterface.IsValid())
	{
		OnLoginCompleteDelegateHandle = IdentityInterface->AddOnLoginCompleteDelegate_Handle(0, FOnLoginCompleteDelegate::CreateUObject(this, &ALocalAvatar::OnLoginComplete));
		IdentityInterface->AutoLogin(0);
	}

	AvatarHands[UOvrAvatar::HandType_Left] = nullptr;
	AvatarHands[UOvrAvatar::HandType_Right] = nullptr;
}

void ALocalAvatar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	DriveHand(UOvrAvatar::HandType_Left, DeltaTime);
	DriveHand(UOvrAvatar::HandType_Right, DeltaTime);

	UpdatePacketRecording(DeltaTime);
}

void ALocalAvatar::OnLoginComplete(int32 LocalUserNum, bool bWasSuccessful, const FUniqueNetId& UserId, const FString& Error)
{
	IOnlineIdentityPtr OculusIdentityInterface = Online::GetIdentityInterface();
	OculusIdentityInterface->ClearOnLoginCompleteDelegate_Handle(0, OnLoginCompleteDelegateHandle);

	// TODO SW: Check bWasSuccessful and get proper login flow/user IDs working.
	if (AvatarComponent)
	{
		AvatarComponent->RequestAvatar(10150022857753417);
	}
}

void ALocalAvatar::SetupPlayerInputComponent(UInputComponent* Input)
{
	Super::SetupPlayerInputComponent(Input);

	Input->BindAction("AvatarToggleRecordPackets", IE_Pressed, this, &ALocalAvatar::ToggleRecordPackets);
	Input->BindAction("AvatarSpawnRemoteAvatar", IE_Pressed, this, &ALocalAvatar::SpawnNewRemoteAvatar);
	Input->BindAction("AvatarDestroyRemoteAvatar", IE_Pressed, this, &ALocalAvatar::DestroyRemoteAvatar);
	Input->BindAction("AvatarCycleLeftHandAttach", IE_Pressed, this, &ALocalAvatar::CycleLeftHandAttach);
	Input->BindAction("AvatarCycleRightHandAttach", IE_Pressed, this, &ALocalAvatar::CycleRightHandAttach);
	Input->BindAction("AvatarCycleRightHandPose", IE_Pressed, this, &ALocalAvatar::CycleRightHandPose);
	Input->BindAction("AvatarCycleLeftHandPose", IE_Pressed, this, &ALocalAvatar::CycleLeftHandPose);

	Input->BindAxis("AvatarLeftThumbstickX", this, &ALocalAvatar::LeftThumbstickX_Value);
	Input->BindAxis("AvatarLeftThumbstickY", this, &ALocalAvatar::LeftThumbstickY_Value);
	Input->BindAxis("AvatarRightThumbstickX", this, &ALocalAvatar::RightThumbstickX_Value);
	Input->BindAxis("AvatarRightThumbstickY", this, &ALocalAvatar::RightThumbstickY_Value);
}

void ALocalAvatar::ToggleRecordPackets()
{
	if (!AvatarComponent)
		return;

	if (PacketSettings.RecordingFrames)
	{
		FOvrAvatarManager::Get().QueueAvatarPacket(AvatarComponent->EndPacketRecording());
	}
	else
	{
		AvatarComponent->StartPacketRecording();
	}

	PacketSettings.AccumulatedTime = 0.f;
	PacketSettings.RecordingFrames = !PacketSettings.RecordingFrames;
}

static float gDegreeOffset = 60.f;
void ALocalAvatar::SpawnNewRemoteAvatar()
{
	uint32_t RemoteCount = 0;
	for (TActorIterator<ARemoteAvatar> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		RemoteCount++;
	}

	if (RemoteCount < 6)
	{
		FRotator SpawnRotate(0.f, gDegreeOffset * RemoteCount, 0.f);
		FVector Forward = SpawnRotate.RotateVector(GetActorForwardVector());
		FVector Location = GetActorLocation() + Forward * 100.f;
		GetWorld()->SpawnActor<ARemoteAvatar>(Location, FRotator(0.f, 180.f, 0.f));
	}
}

void ALocalAvatar::DestroyRemoteAvatar()
{
	ARemoteAvatar* victim = nullptr;
	for (TActorIterator<ARemoteAvatar> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		victim = *ActorItr;
	}

	if (victim)
	{
		victim->Destroy();
	}

}

void ALocalAvatar::CycleRightHandPose()
{
	switch (RightHandPoseIndex)
	{
	case eHandPoseState::Default:
		RightHandPoseIndex = eHandPoseState::Sphere;
		AvatarComponent->SetRightHandPose(ovrAvatarHandGesture_GripSphere);
		break;
	case eHandPoseState::Sphere:
		RightHandPoseIndex = eHandPoseState::Cube;
		AvatarComponent->SetRightHandPose(ovrAvatarHandGesture_GripCube);
		break;
	case eHandPoseState::Cube:
		RightHandPoseIndex = eHandPoseState::Custom;
		AvatarComponent->SetCustomGesture(UOvrAvatar::HandType_Right, gAvatarRightHandTrans, HAND_JOINTS);
		break;
	case eHandPoseState::Custom:
		AvatarComponent->SetRightHandPose(ovrAvatarHandGesture_Default);
		AvatarComponent->SetControllerVisibility(UOvrAvatar::HandType_Right, true);
		RightHandPoseIndex = eHandPoseState::Controller;
		break;
	case eHandPoseState::Controller:
		RightHandPoseIndex = eHandPoseState::Default;
		AvatarComponent->SetControllerVisibility(UOvrAvatar::HandType_Right, false);
		break;
	case eHandPoseState::Detached:
		break;
	default:
		break;
	}
}

void ALocalAvatar::CycleLeftHandPose()
{
	switch (LeftHandPoseIndex)
	{
	case eHandPoseState::Default:
		LeftHandPoseIndex = eHandPoseState::Sphere;
		AvatarComponent->SetLeftHandPose(ovrAvatarHandGesture_GripSphere);
		break;
	case eHandPoseState::Sphere:
		LeftHandPoseIndex = eHandPoseState::Cube;
		AvatarComponent->SetLeftHandPose(ovrAvatarHandGesture_GripCube);
		break;
	case eHandPoseState::Cube:
		LeftHandPoseIndex = eHandPoseState::Custom;
		AvatarComponent->SetCustomGesture(UOvrAvatar::HandType_Left, gAvatarLeftHandTrans, HAND_JOINTS);
		break;
	case eHandPoseState::Custom:
		AvatarComponent->SetLeftHandPose(ovrAvatarHandGesture_Default);
		AvatarComponent->SetControllerVisibility(UOvrAvatar::HandType_Left, true);
		LeftHandPoseIndex = eHandPoseState::Controller;
		break;
	case eHandPoseState::Controller:
		LeftHandPoseIndex = eHandPoseState::Default;
		AvatarComponent->SetControllerVisibility(UOvrAvatar::HandType_Left, false);
		break;
	case eHandPoseState::Detached:
		break;
	default:
		break;
	}
}

void ALocalAvatar::CycleRightHandAttach()
{
	if (RightHandPoseIndex == eHandPoseState::Default)
	{
		AvatarHands[UOvrAvatar::HandType_Right] = AvatarComponent->DetachHand(UOvrAvatar::HandType_Right);
		RightHandPoseIndex = eHandPoseState::Detached;
	}
	else if (RightHandPoseIndex == eHandPoseState::Detached)
	{
		AvatarHands[UOvrAvatar::HandType_Right] = nullptr;
		RightHandPoseIndex = eHandPoseState::Default;
		AvatarComponent->ReAttachHand(UOvrAvatar::HandType_Right);
	}
}

void ALocalAvatar::CycleLeftHandAttach()
{
	if (LeftHandPoseIndex == eHandPoseState::Default)
	{
		AvatarHands[UOvrAvatar::HandType_Left] = AvatarComponent->DetachHand(UOvrAvatar::HandType_Left);
		LeftHandPoseIndex = eHandPoseState::Detached;
	}
	else if (LeftHandPoseIndex == eHandPoseState::Detached)
	{
		AvatarHands[UOvrAvatar::HandType_Left] = nullptr;
		LeftHandPoseIndex = eHandPoseState::Default;
		AvatarComponent->ReAttachHand(UOvrAvatar::HandType_Left);
	}
}

void ALocalAvatar::LeftThumbstickX_Value(float value)
{
	StickPosition[UOvrAvatar::HandType_Left].X = value;
}

void ALocalAvatar::LeftThumbstickY_Value(float value)
{
	StickPosition[UOvrAvatar::HandType_Left].Y = -value;
}

void ALocalAvatar::RightThumbstickX_Value(float value)
{
	StickPosition[UOvrAvatar::HandType_Right].X = value;
}

void ALocalAvatar::RightThumbstickY_Value(float value)
{
	StickPosition[UOvrAvatar::HandType_Right].Y = -value;
}

void ALocalAvatar::UpdatePacketRecording(float DeltaTime)
{
	if (!AvatarComponent)
		return;

	if (!PacketSettings.Initialized)
	{
		AvatarComponent->StartPacketRecording();
		PacketSettings.AccumulatedTime = 0.f;
		PacketSettings.RecordingFrames = true;
		PacketSettings.Initialized = true;
	}

	if (PacketSettings.RecordingFrames)
	{
		PacketSettings.AccumulatedTime += DeltaTime;

		if (PacketSettings.AccumulatedTime >= PacketSettings.UpdateRate)
		{
			PacketSettings.AccumulatedTime = 0.f;
			FOvrAvatarManager::Get().QueueAvatarPacket(AvatarComponent->EndPacketRecording());
			AvatarComponent->StartPacketRecording();
		}
	}
}

void ALocalAvatar::DriveHand(UOvrAvatar::HandType hand, float DeltaTime)
{
	const float HandSpeed = 50.f; // m/s hand speed
	const float Threshold = 0.5f*0.5f;

	if (AvatarHands[hand].IsValid() && StickPosition[hand].SizeSquared() > Threshold)
	{
		AvatarHands[hand]->MoveComponent(FVector(StickPosition[hand].Y, StickPosition[hand].X, 0.f) * HandSpeed * DeltaTime, AvatarHands[hand]->GetComponentRotation(), false);
	}
}


