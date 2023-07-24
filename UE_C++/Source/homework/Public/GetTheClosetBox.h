// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GetTheClosetBox.generated.h"

/**
 * 
 */
UCLASS()
class HOMEWORK_API UGetTheClosetBox : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()


	//�����б�
	// FVector local  ĳһ��Ʒ�ĵ�ǰ��λ��
	// box
	UFUNCTION(BlueprintCallable)
	static TArray<AActor*> getMyCloseActor(AActor* WorldContextObject, TArray<AActor*> outActors);

};
