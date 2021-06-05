#include "QBertPCH.h"
#include "MoveDownRightCommand.h"
#include "GameObject.h"
#include "MovementComponent.h"
#include "ServiceLocator.h"

int MoveDownRightCommand::execute(std::shared_ptr<Hidden::GameObject> pGameObject)
{
	auto movementComponent = pGameObject->GetComponent<MovementComponent>();

	if (movementComponent)
	{
		movementComponent->MoveDownRight();
		return 1;
	}

	ServiceLocator::GetLoggerSystem().LogError("int MoveUpLeftCommand::execute(std::shared_ptr<Hidden::GameObject> pGameObject) - Movement component not found on game object!");

	return 0;
}
