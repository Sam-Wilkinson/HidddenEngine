#include "LoseLifeCommand.h"
#include "HealthComponent.h"
int LoseLifeCommand::execute(std::shared_ptr<Hidden::GameObject> pGameObject)
{
	auto pHealthComponent = pGameObject->GetComponent<HealthComponent>();

	if (pHealthComponent->GetHealth() > 0)
	{
		pHealthComponent->DecrementHealth();
	}

	return 1;
}
