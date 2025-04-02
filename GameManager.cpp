#include "GameManager.h"

//Definition of the static member variable
std::vector<GameObject*> GameManager::GameObjectsVector;

void GameManager::AddGameObject(GameObject* gameObject)
{
	GetGameObjectVector().push_back(gameObject);
}

std::vector<GameObject*>& GameManager::GetGameObjectVector()
{
	return GameObjectsVector;
}

void GameManager::getGameObjectNames(std::vector<GameObject*> GameObjectsVector)
{

}

void GameManager::clearGameObjectVector()
{
	GameObjectsVector.clear();
}