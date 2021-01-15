// Property of 2POW6 Games. All rights reserved.


#include "ElectricCounter.h"

AElectricCounter::AElectricCounter()
{

}


// Called when the game starts or when spawned
void AElectricCounter::BeginPlay()
{
	Super::BeginPlay();

	SetReplicates(true);
}