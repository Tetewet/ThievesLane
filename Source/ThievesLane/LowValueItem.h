// Property of 2POW6 Games. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "BaseItem.h"
#include "GameFramework/Actor.h"
#include "LowValueItem.generated.h"

UCLASS()
class THIEVESLANE_API ALowValueItem : public ABaseItem
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALowValueItem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
