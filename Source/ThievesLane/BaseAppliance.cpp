// Property of 2POW6 Games. All rights reserved.


#include "BaseAppliance.h"

// Sets default values
ABaseAppliance::ABaseAppliance()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABaseAppliance::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseAppliance::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

