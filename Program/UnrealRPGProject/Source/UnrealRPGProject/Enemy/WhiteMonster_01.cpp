// Fill out your copyright notice in the Description page of Project Settings.


#include "WhiteMonster_01.h"

AWhiteMonster_01::AWhiteMonster_01()
{
    PrimaryActorTick.bCanEverTick = true;
}

void AWhiteMonster_01::BeginPlay()
{
    Super::BeginPlay();
}

void AWhiteMonster_01::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}
void AWhiteMonster_01::HandlePatrol()
{
    MoveToRandomLocation(); // 걷는 순찰자
}
void AWhiteMonster_01 :: MoveToRandomLocation() {

}

