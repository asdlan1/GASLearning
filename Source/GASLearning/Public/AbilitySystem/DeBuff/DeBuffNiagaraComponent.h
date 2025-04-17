// GAS

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "NiagaraComponent.h"
#include "DeBuffNiagaraComponent.generated.h"

/**
 * 
 */
UCLASS()
class GASLEARNING_API UDeBuffNiagaraComponent : public UNiagaraComponent
{
	GENERATED_BODY()

public:
	UDeBuffNiagaraComponent();
	
	UPROPERTY(VisibleAnywhere)
	FGameplayTag DeBuffTag;

protected:
	virtual void BeginPlay() override;
	void DeBuffTagChanged(const FGameplayTag CallBackTag, int32 NewCount);
};
