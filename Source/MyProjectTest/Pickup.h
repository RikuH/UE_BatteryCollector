// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Pickup.generated.h"

UCLASS()
class MYPROJECTTEST_API APickup : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickup();

	FORCEINLINE class UStaticMeshComponent* GetMesh() const { return PickupMesh; }

	UFUNCTION(BlueprintCallable, Category = "Pickup")
	void SetActive(bool newState);

	UFUNCTION(BlueprintPure, Category = "Pickup")
	bool IsActive();

	UFUNCTION(BlueprintNativeEvent)
	void OnCollected();
	virtual void OnCollected_Implementation();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	bool bIsActive;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pickup", meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* PickupMesh;

};
