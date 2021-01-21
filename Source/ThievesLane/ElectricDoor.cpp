// Property of 2POW6 Games. All rights reserved.


#include "ElectricDoor.h"

AElectricDoor::AElectricDoor() 
{

}


// Called when the game starts or when spawned
void AElectricDoor::BeginPlay()
{
	Super::BeginPlay();

	SetReplicates(true);
	SetReplicateMovement(true);

	GlobalStartLocation = GetActorLocation();
	GlobalTargetLocation = GlobalStartLocation + TargetLocation;
}

void AElectricDoor::MoveDoor(float DeltaTime)
{
	if (bIsMoving && HasAuthority())
	{
		/*FVector Location = GetActorLocation();
		FVector Direction = (GlobalTargetLocation - GlobalStartLocation).GetSafeNormal();
		Location += Speed * DeltaTime * Direction;
		SetActorLocation(Location);*/

		SetActorLocation(FMath::VInterpTo(GetActorLocation(), GlobalTargetLocation, DeltaTime, Speed));

		StopDoorCheck();
	}
}

void AElectricDoor::StopDoorCheck()
{
	if (GetActorLocation().Equals(GlobalTargetLocation, 0.1f) && HasAuthority())
	{
		//bIsMoving = false;
		GlobalTargetLocation = GlobalStartLocation;
		GlobalStartLocation = GetActorLocation();
	}
}

//Called every frame
void AElectricDoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MoveDoor(DeltaTime);
	
}