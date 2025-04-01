#pragma once
#include<vector>
#include "GameObject.h"

class GameManager : public Object
{
public:
	static void AddGameObject(GameObject* gameObject);

	static std::vector<GameObject*>& GetGameObjectVector();

	static 
};

