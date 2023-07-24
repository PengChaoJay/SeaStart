// Fill out your copyright notice in the Description page of Project Settings.


#include "GetTheClosetBox.h"


//��ȡ�����λ��
TArray<AActor*> UGetTheClosetBox::getMyCloseActor(AActor* ActorObject, TArray<AActor*> outActors)
{
	outActors.Sort([ActorObject](const AActor& a, const AActor& b)
			{return a.GetDistanceTo(ActorObject) > b.GetDistanceTo(ActorObject); });
	return outActors;
}
