// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Targetable.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UTargetable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
UENUM(BlueprintType)
enum class EAPTargetState : uint8
{
	None        UMETA(DisplayName = "Not Targeted"),
	Targeted    UMETA(DisplayName = "Targeted"),
	Max         UMETA(Hidden)
};

class APGAME_API ITargetable
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	// Get Target Location
	virtual FVector GetTargetLocation() const = 0;
	virtual EAPTargetState GetCombatState() const = 0;
	virtual void SetCombatState(EAPTargetState newState) = 0;
};
