// Property of 2POW6 Games. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseItem.generated.h"

UCLASS()
class THIEVESLANE_API ABaseItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseItem();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "ItemProperties")
		float BaseValue;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "ItemProperties")
		float BaseWeight;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "ItemProperties")
		float EstimatedQuality;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
