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
}