// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TreasureChest.generated.h"


UCLASS()
class HOMEWORK_API ATreasureChest : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATreasureChest();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	UFUNCTION(BlueprintCallable, Category = "Open")
	void OpenTreasureChest();
	
	
	UFUNCTION(BlueprintCallable, Category = "Close")
	void CloseTreasureChest();

	UFUNCTION(BlueprintCallable, Category = "Close")
	bool getStatus();

	UFUNCTION(BlueprintCallable, Category = "OperatorTest")
	void OperatorOpenAndClose();



public:
	FTimerHandle MyHandle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool StopLooping;

	void playOpenAnimation();
	void playCloseAnimation();


public:

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Box;

	//������ٶ�
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (UIMin = 0.1, UIMax = 5))
	float speed;

	//���ÿ���ĽǶȣ���Ҫ��Z������ݣ��������еĴ�Сֵ,Ҫȡ��
	UPROPERTY(EditAnywhere, BlueprintReadWrite,meta=(UIMin=0,UIMax=179))
	float Roll;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* BoxTop;
};
