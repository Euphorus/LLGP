#pragma once
#include<vector>
#include "GameObject.h"

class GameManager : public Object
{
public:
	static void AddGameObject(GameObject* gameObject);

	static std::vector<GameObject*>& GetGameObjectVector();

	//static 
	static void getGameObjectNames(std::vector<GameObject*> GameObjectsVector);

	static void clearGameObjectVector();

private:
	//Vector that stores all the created gameObjects
	static std::vector<GameObject*> GameObjectsVector;
};

