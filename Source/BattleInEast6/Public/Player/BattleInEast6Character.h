// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"


#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

#include "BattleInEast6Character.generated.h"

UCLASS()
class BATTLEINEAST6_API ABattleInEast6Character : public ACharacter
{
	GENERATED_BODY()

private:
	// * CameraBoom
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent * CameraBoom;

	// * Follow camera
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* FollowCamera;
public:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Property, meta = (AllowPrivateAccess = "true"))
		float HealthPoint;
private:
	//max speed
	float m_MaxSpeed;
	float m_DeltaTime;
public:
	// Sets default values for this character's properties
	ABattleInEast6Character();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
	
};
