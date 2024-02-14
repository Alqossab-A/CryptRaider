#include "Grabber.h"

#include "Engine/World.h"
#include "DrawDebugHelpers.h"

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();
}

 // Called every frame 
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) 
{ 
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	FVector Start = GetComponentLocation();
	FVector End = Start + GetForwardVector() * MaxGrabDistance;
	DrawDebugLine(GetWorld(), Start, End, FColor::Red);

	float Damage = 5;
	PrintDamage(Damage);
	HasDamage(Damage);
}

void UGrabber::PrintDamage(const float& Damage)
{
	UE_LOG(LogTemp, Display, TEXT("Damage: %f"), Damage);
}

bool UGrabber::HasDamage(float& Damage)
{
	if (Damage > 0) {
		UE_LOG(LogTemp, Display, TEXT("higher then 0"));
		return true;
	}
	else {
		UE_LOG(LogTemp, Display, TEXT("lower then 0"));
		return false;
	}
}
