// Property of 2POW6 Games. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "BaseAppliance.h"
#include "ElectricCounter.generated.h"

/**
 * 
 */
UCLASS()
class THIEVESLANE_API AElectricCounter : public ABaseAppliance
{
	GENERATED_BODY()

public:
	AElectricCounter();

protected:
	virtual void BeginPlay() override;
};
