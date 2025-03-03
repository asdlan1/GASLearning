// GAS

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "Interaction/EnemyInterface.h"
#include "AuraEnemy.generated.h"

/**
 * 
 */
UCLASS()
class GASLEARNING_API AAuraEnemy : public AAuraCharacterBase, public IEnemyInterface
{
	GENERATED_BODY()

public:
	AAuraEnemy();
	//继承实现接口的两个方法
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;
	//

protected:
	virtual void BeginPlay() override;
};
