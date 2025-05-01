// GAS

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerStart.h"
#include "GASLearning/GASLearning.h"
#include "Interaction/HighlightInterface.h"
#include "Interaction/SaveInterface.h"
#include "CheckPoint.generated.h"

class USphereComponent;
/**
 * 
 */
UCLASS()
class GASLEARNING_API ACheckPoint : public APlayerStart, public ISaveInterface, public IHighlightInterface
{
	GENERATED_BODY()

public:
	ACheckPoint(const FObjectInitializer& ObjectInitializer);

	/*Save Interface*/
	virtual bool ShouldLoadTransform_Implementation() override { return false; };
	virtual void LoadActor_Implementation() override;
	//

	UPROPERTY(BlueprintReadWrite, SaveGame)
	bool bReached = false;

	UPROPERTY(EditAnywhere)
	bool bBindOverlapCallback = true;

protected:
	UFUNCTION()
	virtual void OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFormSweep, const FHitResult& SweepResult);

	virtual void BeginPlay() override;

	/* Highlight Interface*/
	virtual void SetMoveToLocation_Implementation(FVector& OutDestination) override;
	virtual void HighlightActor_Implementation() override;
	virtual void UnHighlightActor_Implementation() override;
	//

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USceneComponent> MoveToComponent;
	
	UPROPERTY(EditDefaultsOnly)
	int32 CustomDepthStencilOverride = CUSTOM_DEPTH_TAN;

	UFUNCTION(BlueprintImplementableEvent)
	void CheckPointReached(UMaterialInstanceDynamic* DynamicMaterialInstance);

	UFUNCTION(BlueprintCallable)
	void HandleGlowEffects();
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<UStaticMeshComponent> CheckPointMesh;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USphereComponent> Sphere;

private:
};
