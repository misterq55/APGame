// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Combatabt.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UCombatabt : public UInterface
{
	GENERATED_BODY()
};

/**
 * Combat state enum and interface for actors that can perform attacks/guards.
 */
UENUM(BlueprintType)
enum class ECombatState : uint8
{
	Idle            UMETA(DisplayName = "Idle"),
	WeakAttacking   UMETA(DisplayName = "Weak Attacking"),
	StrongAttacking UMETA(DisplayName = "Strong Attacking"),
	Guarding        UMETA(DisplayName = "Guarding"),
	Dodging         UMETA(DisplayName = "Dodging"),
	Stunned         UMETA(DisplayName = "Stunned"),
	Max             UMETA(Hidden)
};

/**
 * 
 */
class APGAME_API ICombatabt
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	// State-based accessors (preferred for extensibility)
	virtual ECombatState GetCombatState() const = 0;
	virtual void SetCombatState(ECombatState NewState) = 0;

	// Attacks
	virtual void WeakAttack() = 0;
	virtual void StrongAttack() = 0;

	// Convenience helpers that use the state accessors. Implementing classes may override if needed.
	virtual bool IsGuarded() const { return GetCombatState() == ECombatState::Guarding; }
	virtual void Guard() { SetCombatState(ECombatState::Guarding); }
};
