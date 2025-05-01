// GAS

#pragma once

#include "CoreMinimal.h"
#include "CheckPoint/CheckPoint.h"
#include "MapEntrance.generated.h"

/**
 * 
 */
UCLASS()
class GASLEARNING_API AMapEntrance : public ACheckPoint
{
	GENERATED_BODY()

public:
	AMapEntrance(const FObjectInitializer& ObjectInitializer);
	
	/* Highlight Interface*/
	virtual void HighlightActor_Implementation() override;
	//

	/*Save Interface*/
	virtual void LoadActor_Implementation() override;
	//

	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<UWorld> DestinationMap;

	UPROPERTY(EditAnywhere)
	FName DestinationPlayerStartTag;

protected:
	virtual void OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFormSweep, const FHitResult& SweepResult) override;

};
