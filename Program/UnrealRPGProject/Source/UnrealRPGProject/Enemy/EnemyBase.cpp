// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyBase.h"

// Sets default values
AEnemyBase::AEnemyBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MaxHP = 100.f;
	CurrentHP = MaxHP;
	CurrentState = EEnemyState::Idle;
	TargetActor = nullptr;
}

// Called when the game starts or when spawned
void AEnemyBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemyBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UpdateState(DeltaTime);
}

void AEnemyBase::UpdateState(float DeltaTime)
{
    switch (CurrentState)
    {
    case EEnemyState::Idle:
        HandleIdle();
        break;
    case EEnemyState::Patrol:
        HandlePatrol();
        break;
    case EEnemyState::Chase:
        HandleChase();
        break;
    case EEnemyState::Attack:
        HandleAttack();
        break;
    case EEnemyState::Hurt:
        HandleHurt();
        break;
    case EEnemyState::Die:
        HandleDie();
        break;
    default:
        break;
    }
}

void AEnemyBase::ChangeState(EEnemyState NewState) {
    if (CurrentState == NewState) return;

    // 상태변경 확인
    UE_LOG(LogTemp, Log, TEXT("Enemy State Changed: %d -> %d"), (int32)CurrentState, (int32)NewState);

    CurrentState = NewState;
}

//오버라이딩 용
void AEnemyBase::HandleIdle() {}
void AEnemyBase::HandlePatrol() {}
void AEnemyBase::HandleChase() {}
void AEnemyBase::HandleAttack() {}
void AEnemyBase::HandleHurt() {}
void AEnemyBase::HandleDie() {}





