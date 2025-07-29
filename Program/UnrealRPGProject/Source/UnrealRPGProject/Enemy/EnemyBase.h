// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnemyBase.generated.h"

UENUM(BlueprintType)
enum class EEnemyState : uint8
{
	Idle, //대기
	Patrol, //순찰
	Chase, //추적
	Attack, // 공격
	Hurt, //맞음
	Die // 죽음
};

UCLASS(Abstract)
class UNREALRPGPROJECT_API AEnemyBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemyBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void ChangeState(EEnemyState NewState);

protected:
	virtual void HandleIdle();
	virtual void HandlePatrol();
	virtual void HandleChase();
	virtual void HandleAttack();
	virtual void HandleHurt();
	virtual void HandleDie();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "FSM")
	EEnemyState CurrentState;

	/** 기본 스탯 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stat")
	float MaxHP;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Stat")
	float CurrentHP;

	/** 타겟 (플레이어 등) */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Target")
	AActor* TargetActor;

	/** 상태 업데이트 주기 */
	virtual void UpdateState(float DeltaTime);

};
