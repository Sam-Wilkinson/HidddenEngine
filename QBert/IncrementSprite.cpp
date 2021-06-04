#include "QBertPCH.h"
#include "IncrementSprite.h"
#include "GameObject.h"
#include "SpriteComponent.h"

int IncrementSprite::execute(std::shared_ptr<Hidden::GameObject> pGameObject)
{
	auto pSprite = pGameObject->GetComponent<SpriteComponent>();

	pSprite->IncrementRow();

	return 0;
}
