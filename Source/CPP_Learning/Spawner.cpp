// Fill out your copyright notice in the Description page of Project Settings.


//#define print(text) if(GEngine) GEnginge->AddOnScreenDebugMessage(-1, 1.5, FColor::Green, text)
//#define printFString(text, fstring) if(GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green, FString::Printf(text(text), fstring))

#include "Spawner.h"
#include "GameFramework/Actor.h"
#include "DrawDebugHelpers.h"
#include "Math/Box.h"
#include "Kismet/KismetSystemLibrary.h"


// Sets default values
ASpawner::ASpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
}

// Called when the game starts or when spawned
void ASpawner::BeginPlay()
{
	Super::BeginPlay();
	
	//DrawDebugBox(GetWorld(), GetActorLocation(), GetComponentsBoundingBox().GetExtent(), FColor::Purple, true, -1, 0, 5);

	FTimerHandle UnusedHandle;
	GetWorldTimerManager().SetTimer(
		UnusedHandle, this, &ASpawner::SpawnPlayerRecharge,
		FMath::RandRange(3, 5), true);

}

// Called every frame
void ASpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASpawner::SpawnPlayerRecharge()
{

	FVector VectorBox = GetComponentsBoundingBox().FBox::GetExtent();
	FVector VectorCenter = GetComponentsBoundingBox().FBox::GetCenter();
	Spawn_X_Max = VectorBox.X + VectorCenter.X;
	Spawn_X_Min = VectorCenter.X - VectorBox.X;
	Spawn_Y_Max = VectorBox.Y + VectorCenter.Y;
	Spawn_Y_Min = VectorCenter.Y - VectorBox.Y;




	float RandX = FMath::RandRange(Spawn_X_Min, Spawn_X_Max);
	float RandY = FMath::RandRange(Spawn_Y_Min, Spawn_Y_Max);

	FVector SpawnPosition = FVector(RandX, RandY, Spawn_Z);
	FRotator SpawnRotation = FRotator(0.0f, 0.0f, 0.0f);

	


		
		
		
		//GetComponentsBoundingBox(bool bNonColliding,
		//bool bIncludeFromChildActors) const;

	GetWorld()->SpawnActor(PlayerRecharge, &SpawnPosition, &SpawnRotation);

	

	



}
