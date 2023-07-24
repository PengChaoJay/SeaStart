// Fill out your copyright notice in the Description page of Project Settings.


#include "TreasureChest.h"

// Sets default values
ATreasureChest::ATreasureChest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	StopLooping = true;

	//设置箱子开速度
	speed = 1.0f;

	//设置箱子开的角度
	Roll=90;

	// 创建可附加内容的虚拟根组件。
	//RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	//创建actor
	Box = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Box"));
	BoxTop = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BoxTop"));
	Box->SetupAttachment(RootComponent);
	BoxTop->SetupAttachment(Box);


	//设置相对位置
	Box->SetRelativeLocation(FVector(0.0f,0.0f,0.0f));
	BoxTop->SetRelativeLocation(FVector(0.0f,-23.0f,50.0f));

}

// Called when the game starts or when spawned
void ATreasureChest::BeginPlay()
{
	Super::BeginPlay();
	//OpenTreasureChest();
	
}

// Called every frame
void ATreasureChest::Tick(float DeltaTime)
{
	//Super::Tick(DeltaTime);

}

//打开箱子的操作
void ATreasureChest::OpenTreasureChest()
{
	if (this->getStatus())
	{
		GetWorldTimerManager().SetTimer(MyHandle, this, &ATreasureChest::playOpenAnimation, 0.03f, true);
	}
	//else {
	//	GetWorldTimerManager().SetTimer(MyHandle, this, &ATreasureChest::playCloseAnimation, 0.03f, true);
	//}
	
	//this->StopLooping = false;
}

void  ATreasureChest::playOpenAnimation()
{
	    //FRotator 类的几个参数
		//Pitch:俯仰角，即绕Y轴旋转；
		//Yaw：偏角，即绕Z轴旋转；
		//Roll : 滚角，即绕X轴旋转
		//FRotator rotator(90, 0, 0);
		//if (MyHandle.IsValid())
		//{
		//	GetWorldTimerManager().ClearTimer(MyHandle);
		//}
		////获得基础的旋转体
		FRotator rotator = BoxTop->GetComponentRotation();
		rotator.Roll -= speed;
		//rotator.Roll = rotator.Roll-speed>0?:
		if (rotator.Roll>-Roll)
		{
			BoxTop->SetWorldRotation(rotator);
		}else {
			GetWorldTimerManager().ClearTimer(MyHandle);
		}
}

void ATreasureChest::CloseTreasureChest()
{
	//FRotator 类的几个参数
	//Pitch:俯仰角，即绕Y轴旋转；
	//Yaw：偏角，即绕Z轴旋转；
	//Roll : 滚角，即绕X轴旋转
	GetWorldTimerManager().SetTimer(MyHandle, this, &ATreasureChest::playCloseAnimation, 0.03f, true);
}

void  ATreasureChest::playCloseAnimation() {
	//if (MyHandle.IsValid())
	//{
	//	GetWorldTimerManager().ClearTimer(MyHandle);
	//}

	////获得基础的旋转体
	FRotator rotator = BoxTop->GetComponentRotation();
	rotator.Roll += speed;
	rotator.Roll = rotator.Roll >= 0 ? 0 : rotator.Roll;
	if (rotator.Roll <=0)
	{
		BoxTop->SetWorldRotation(rotator);
	}else {
		GetWorldTimerManager().ClearTimer(MyHandle);
	}
}

bool ATreasureChest::getStatus()
{
	return this->StopLooping;
}

void ATreasureChest::OperatorOpenAndClose()
{
	if (this->getStatus())
	{
		OpenTreasureChest();
		this->StopLooping = false;
	}
	else {
		CloseTreasureChest();
		this->StopLooping = true;
	}
}

