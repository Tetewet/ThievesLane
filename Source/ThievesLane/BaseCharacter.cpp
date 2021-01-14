// Property of 2POW6 Games. All rights reserved.


#include "BaseCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/InputSettings.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "MotionControllerComponent.h"
#include "XRMotionControllerBase.h" // for FXRMotionControllerBase::RightHandSourceId

// Sets default values
ABaseCharacter::ABaseCharacter()
{
	//set collision capsule
	GetCapsuleComponent()->InitCapsuleSize(66.f, 96.0f);

	//set turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	//create camera component
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("BaseCharacterCamera"));
	FirstPersonCameraComponent->SetupAttachment(GetCapsuleComponent());
	FirstPersonCameraComponent->SetRelativeLocation(FVector(-39.56f, 1.75f, 64.f));
	FirstPersonCameraComponent->bUsePawnControlRotation = true;

	// Create VR Controllers.
	R_MotionController = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("R_MotionController"));
	R_MotionController->MotionSource = FXRMotionControllerBase::RightHandSourceId;
	R_MotionController->SetupAttachment(RootComponent);
	L_MotionController = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("L_MotionController"));
	L_MotionController->SetupAttachment(RootComponent);

 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	//initialize the crosshair
	CameraManager = UGameplayStatics::GetPlayerController(GetWorld(), 0)->PlayerCameraManager;
	BeginCrosshair = CameraManager->GetCameraLocation();
	EndCrosshair = CameraManager->GetCameraLocation() + CameraManager->GetCameraRotation().Vector() * CrosshairLength;
	QueryParams.AddIgnoredActor(this);
	QueryParams.bTraceComplex = true;
}

//Input
void ABaseCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	check(PlayerInputComponent);

	//jumping
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	//action events
	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &ABaseCharacter::OnAction);

	//resetVR
	PlayerInputComponent->BindAction("ResetVR", IE_Pressed, this, &ABaseCharacter::OnResetVR);

	//movement
	PlayerInputComponent->BindAxis("MoveForward", this, &ABaseCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ABaseCharacter::MoveRight);

	//turnrate
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &ABaseCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUpRate", this, &ABaseCharacter::LookUpAtRate);

}

void ABaseCharacter::OnAction()
{
	//do an action with the item equipped

}

void ABaseCharacter::OnResetVR()
{
	UHeadMountedDisplayFunctionLibrary::ResetOrientationAndPosition();
}

void ABaseCharacter::OnCrosshair()
{
	//this is called per frame : crosshair shoots forward from the camera
	BeginCrosshair = CameraManager->GetCameraLocation();
	EndCrosshair = CameraManager->GetCameraLocation() + CameraManager->GetCameraRotation().Vector() * CrosshairLength;

	if (GetWorld()->LineTraceSingleByChannel(Hit, BeginCrosshair, EndCrosshair, ECC_Visibility, QueryParams))
	{
		//ligne de deboguage
		DrawDebugLine(GetWorld(), BeginCrosshair, EndCrosshair, FColor::Blue, false, 1.0f, 0, 1.0f);

		if (Cast<ABaseItem>(Hit.GetActor()))
		{
			//if it is a base item, then we can pick it up : show HUD pickup-able info
			DrawDebugLine(GetWorld(), BeginCrosshair, EndCrosshair, FColor::Red, false, 1.0f, 0, 1.0f);


			//if pick up the item, add it in the inventory (+ stop showing related HUD)

		}
	}
}

void ABaseCharacter::MoveForward(float Value)
{
	if (Value != 0.0f)
	{
		//add movement in direction
		AddMovementInput(GetActorForwardVector(), Value);
	}
}

void ABaseCharacter::MoveRight(float Value)
{
	if (Value != 0.0f)
	{
		//add movement in that direction
		AddMovementInput(GetActorRightVector(), Value);
	}
}

void ABaseCharacter::TurnAtRate(float Rate)
{
	//calculate delta for this frame for the rate info
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void ABaseCharacter::LookUpAtRate(float Rate)
{
	//calculate delta for this frame for the rate info
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

// Called every frame
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	OnCrosshair();
	
}


