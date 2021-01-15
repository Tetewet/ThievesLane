// Property of 2POW6 Games. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "BaseAppliance.h"
#include "ElectricDoor.generated.h"

/**
 * 
 */
UCLASS()
class THIEVESLANE_API AElectricDoor : public ABaseAppliance
{
	GENERATED_BODY()
	
public:
	AElectricDoor();

protected:
	virtual void BeginPlay() override;
};
