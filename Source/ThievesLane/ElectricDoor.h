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

	UPROPERTY(EditAnywhere, Meta = (MakeEditWidget = true))
		FVector TargetLocation;
	UPROPERTY(EditAnywhere)
		float Speed = 5.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bIsMoving = false;

	UFUNCTION(BlueprintCallable)
		void MoveDoor(float DeltaTime);
	UFUNCTION(BlueprintCallable)
		void StopDoorCheck();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	FVector GlobalTargetLocation;
	FVector GlobalStartLocation;

protected:
	virtual void BeginPlay() override;
};
