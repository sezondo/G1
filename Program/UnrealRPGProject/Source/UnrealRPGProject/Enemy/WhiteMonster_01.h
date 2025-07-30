// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemyBase.h"
#include "WhiteMonster_01.generated.h"

/**
 * 
 */
UCLASS()
class UNREALRPGPROJECT_API AWhiteMonster_01 : public AEnemyBase
{
	GENERATED_BODY()
public:
	AWhiteMonster_01();

protected:
	// EnemyBase.h
	virtual void BeginPlay() override;
public:
	virtual void Tick(float DeltaTime) override;
	

	virtual void HandleIdle()override;
	virtual void HandlePatrol()override;
	virtual void HandleChase()override;
	virtual void HandleAttack()override;
	virtual void HandleHurt()override;
	virtual void HandleDie()override;

	void MoveToRandomLocation();
};
