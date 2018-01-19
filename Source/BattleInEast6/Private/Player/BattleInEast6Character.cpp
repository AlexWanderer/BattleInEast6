// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleInEast6Character.h"

#include "GameFramework/CharacterMovementComponent.h"

#include "Engine.h"
// Sets default values
ABattleInEast6Character::ABattleInEast6Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;


	HealthPoint = 100.f;
	//set CameraBoom
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("Cameraboom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.f;  // the camera follows distance to the character
	CameraBoom->bUsePawnControlRotation = true;  // Rotate the arm based on the controller

	//Follow Camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false;  // Camera does not rotate relative to arm
}

// Called when the game starts or when spawned
void ABattleInEast6Character::BeginPlay()
{
	Super::BeginPlay();

	//set Max Speed
	
	m_MaxSpeed = GetMovementComponent()->GetMaxSpeed();
}

void ABattleInEast6Character::MoveForward(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
		
		
	}
}

void ABattleInEast6Character::MoveRight(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value);
	}
}


// Called every frame
void ABattleInEast6Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	m_DeltaTime = DeltaTime;

}

// Called to bind functionality to input
void ABattleInEast6Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	check(PlayerInputComponent);
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	//move
	PlayerInputComponent->BindAxis("MoveForward", this, &ABattleInEast6Character::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ABattleInEast6Character::MoveRight);

	//Jump
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	//turn and lookup
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);

}

