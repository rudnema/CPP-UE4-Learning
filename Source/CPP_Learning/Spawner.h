// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "Spawner.generated.h"


UCLASS()
class CPP_LEARNING_API ASpawner : public ATriggerBox
{


	GENERATED_BODY()

		ASpawner();

	UPROPERTY(EditAnywhere)
		TSubclassOf<APawn> PlayerRecharge;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		float Spawn_Z = 500.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		float Spawn_X_Min;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		float Spawn_X_Max;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		float Spawn_Y_Min;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		float Spawn_Y_Max;

	void SpawnPlayerRecharge();
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
