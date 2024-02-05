// Fill out your copyright notice in the Description page of Project Settings.


#include "Mover.h"

#include "Math/UnrealMathUtility.h"

// Sets default values for this component's properties
UMover::UMover()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMover::BeginPlay()
{
	Super::BeginPlay();

	OriginalLocation = GetOwner()->GetActorLocation();
	
}


// Called every frame
void UMover::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (bShouldMove == true) {
		FVector CurrentLocation = GetOwner()->GetActorLocation();
		FVector TargetLocation = OriginalLocation + MoveOffset;
		float MoveSpeed = FVector::Distance(OriginalLocation, TargetLocation) / MoveTime;

		FVector NewLocation = FMath::VInterpConstantTo(CurrentLocation, TargetLocation, DeltaTime, MoveSpeed);
		GetOwner()->SetActorLocation(NewLocation);
	};

	if (bShouldRotate == true) {
		FRotator CurrentRotation = GetOwner()->GetActorRotation();
		FRotator TargetRotation = OriginalRotation + RotationOffset;
		float RotationSpeed = RotationTime;

		FRotator NewRotation = FMath::RInterpConstantTo(CurrentRotation, TargetRotation, DeltaTime, RotationSpeed);
		GetOwner()->SetActorRotation(NewRotation);
	};
}
