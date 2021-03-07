#include "DeathCommand.h"
#include "GameObject.h"

int DeathCommand::execute(std::shared_ptr<Hidden::GameObject> pGameObject)
{
	auto pHealthComponent = pGameObject->GetComponent<HealthComponent>();

	if (pHealthComponent->GetHealth() > 0)
	{
		pHealthComponent->SetHealth(0);
	}

	return 1;
}
