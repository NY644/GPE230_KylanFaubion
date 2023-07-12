// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "Engine/SkeletalMesh.h"
#include "Camera/CameraComponent.h"

#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"

#include "MazeCharacter.generated.h"

UCLASS()
class GPE230_KYLANFAUBION_API AMazeCharacter : public ACharacter
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere)
		UFUNCTION(BlueprintCallable)
		float moveSpeed;
	UPROPERTY(EditAnywhere)
		float rotationSpeed;
	UPROPERTY(EditAnywhere)
	UAnimSequence* _deathAnim;
	UPROPERTY(EditAnywhere)
		bool _isDead = false;
	UPROPERTY(EditAnywhere)
		UNiagaraSystem* _stunSystem;

protected:
	/// <summary>
	/// The current health of the character.
	/// </summary>
	float _currentHealth;

public:
	/// <summary>
	/// The max and starting health for the character.
	/// </summary>
	UPROPERTY(EditAnywhere)
	float maxHealth;

public:
	// Sets default values for this character's properties
	AMazeCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UFUNCTION(BlueprintCallable)
	virtual float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator,
		AActor* DamageCause) override;
	virtual void Die();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;



private:
	void MoveFB(float value);
	void MoveLR(float value);
	void Rotate(float value);
	UFUNCTION(BlueprintCallable)
	void ActivateStunParticleSystem();

};
