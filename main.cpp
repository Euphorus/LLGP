#include <iostream>
#include <chrono>
#include "Vector2.h"
#include "Event.h"
#include "GameObject.h"

#define FIXEDFRAMERATE 0.025f
/*
    This version of the SFML "hello world" is statically linked, you may wish to try the dynamically linked version as well.
*/
#ifdef _DEBUG
int main()
#else
int WinMain()
#endif
{
	GameObject* Player = new GameObject();
	GameObject* Enemy = new GameObject();

	std::array<GameObject*, 4> walls;

	for (int i = 0; i < 4; ++i)
	{
		walls[i] = new GameObject();
	}

	//put newly made gameObjects on the vector
	GameManager::AddGameObject(Player);
	GameManager::AddGameObject(Enemy);

	for (int i = 0; i < 4; ++i)
	{
		GameManager::AddGameObject(walls[i]);
	}

	Player->SetName("Player");
	Enemy->SetName("Enemy");
	std::array<std::string, 4> wallNames = { "TopWall", "LeftWall", "BottomWal", "RightWall" };

	for (int i = 0; i < walls.size(); ++i)
	{
		walls[i]->SetName(wallNames[i]);
	}

	GameManager::getGameObjectNames(GameManager::GetGameObjectVector());

	Player->AddComponent<PlayerComponent>();
	Player->AddComponent<BoxCollider>();
	Player->GetComponent<BoxCollider>()->DrawOutlines(Player->GetRectangleShape());

	Enemy->AddComponent<BoxCollider>();
	Enemy->AddComponent<EnemyComponent>();
	Enemy->GetComponent<BoxCollider>()->DrawOutlines(Enemy->GetRectangleShape());

	for (int i = 0; i < 4; ++i)
	{
		walls[i]->AddComponent<BoxCollider>();
	}


	//Create window of resolutoin
	sf::RenderWindow window(sf::VideoMode({ 1000, 1000 }), "SFML is SHIT!!!!");



#pragma region Walls

	float TopPadding = 20.f;
	float LeftPadding = 20.f;
	float BottomPadding = 960.f;
	float RightPadding = 960.f;

	//Define the size and locations of the wall
	LLGP::Vector2<float> VerticalWallSize = LLGP::Vector2<float>(15, 1000);
	LLGP::Vector2<float> HorizontalWallSize = LLGP::Vector2<float>(1000, 15);

	LLGP::Vector2<float> TopWallPos = LLGP::Vector2<float>(0.0f, TopPadding);
	LLGP::Vector2<float> LeftWallPos = LLGP::Vector2<float>(LeftPadding, 0.0f);
	LLGP::Vector2<float> BottomWallPos = LLGP::Vector2<float>(0.0f, BottomPadding);
	LLGP::Vector2<float> RightWallPos = LLGP::Vector2<float>(RightPadding, 0.0f);

	//Create a rectangle
	sf::RectangleShape TopWallShape(HorizontalWallSize);
	sf::RectangleShape LeftWallShape(VerticalWallSize);
	sf::RectangleShape BottomWallShape(HorizontalWallSize);
	sf::RectangleShape RightWallShape(VerticalWallSize);

	TopWallShape.setFillColor(sf::Color::Green);
	LeftWallShape.setFillColor(sf::Color::Blue);
	BottomWallShape.setFillColor(sf::Color::Magenta);
	RightWallShape.setFillColor(sf::Color::Yellow);

	TopWallShape.setPosition(TopWallPos);
	LeftWallShape.setPosition(LeftWallPos);
	BottomWallShape.setPosition(BottomWallPos);
	RightWallShape.setPosition(RightWallPos);

	TopWallShape.setOutlineThickness(3);
	LeftWallShape.setOutlineThickness(3);
	BottomWallShape.setOutlineThickness(3);
	RightWallShape.setOutlineThickness(3);

	TopWallShape.setOutlineColor(sf::Color(255, 255, 255));
	LeftWallShape.setOutlineColor(sf::Color(255, 255, 255));
	BottomWallShape.setOutlineColor(sf::Color(255, 255, 255));
	RightWallShape.setOutlineColor(sf::Color(255, 255, 255));

	walls[0]->SetRectangleShape(TopWallShape);
	walls[1]->SetRectangleShape(LeftWallShape);
	walls[2]->SetRectangleShape(BottomWallShape);
	walls[3]->SetRectangleShape(RightWallShape);

	for (int i = 0; i < 4; ++i)
	{
		walls[i]->SetIsWall(true);
	}

#pragma endregion


	//Get the time before getting into the loop
	std::chrono::steady_clock::time_point lastTime = std::chrono::steady_clock::now();
	float deltaTime = 0.0f;
	float timeSincePhysicsStep = 0.0f;

	//Test shape thats squished
	sf::RectangleShape testShape(sf::Vector2f(100, 50));
	testShape.setFillColor(sf::Color::Green);
	testShape.setPosition({200, 200});

	while (window.isOpen())
	{
		while (const std::optional event = window.pollEvent())
		{
			//Close window: exit
			if (event->is<sf::Event::Closed>())
				window.close();


			//Check for left mouse button press event
			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
			{
				Player->SetIsShooting(true);
			}

			//check for left mouse button release event
			if (!(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)))
			{
				Player->SetIsShooting(false);
			}
		}

		std::chrono::steady_clock::time_point now = std::chrono::steady_clock::now();
		deltaTime = std::chrono::duration_cast<std::chrono::microseconds>(now - lastTime).count() / 100000.0f;
		lastTime = now;

		Player->GetComponent<PlayerComponent>()->Move(deltaTime);

		if (Player->GetIsShooting())
		{
			Player->GetComponent<PlayerComponent>()->Shooting();
		}

		Enemy->GetComponent<EnemyComponent>()->Move();

		//Retrieve the vector of GameObjects from the GameManager
		std::vector<GameObject*>& gameObjects = GameManager::GetGameObjectVector();

		//Check for collision between game objects
		for (int i = 0; i < gameObjects.size(); ++i)
		{
			for (int j = 1 + i; j < gameObjects.size(); ++j)
			{
				GameObject* objectA = gameObjects[i];
				GameObject* objectB = gameObjects[j];

				//skip collision checks if both the objects are walls
				if (objectA->GetIsWall() && objectB->GetIsWall())
				{
					continue;
				}

				if (objectA->HasBoxCollider(objectA) && objectB->HasBoxCollider(objectB))
				{
					BoxCollider* colliderA = objectA->GetComponent<BoxCollider>();
					BoxCollider* colliderB = objectB->GetComponent<BoxCollider>();

					//ensure both colliders are valid before checking collision
					if (colliderA && colliderB && colliderA->CheckCollision(objectA, objectB))
					{
						//Wall Detection
						if (objectA->GetIsWall() || objectB->GetIsWall())
						{
							std::cout << "Wall Collision detected between objects " << objectA->GetName() << " and " << objectB->GetName() << std::endl;


							for (GameObject* wall : walls)
							{
								BoxCollider::WallCollision(objectA, objectB);
							}
						}

						//Detection between none walls
						else
						{
							std::cout << "Collision detected between objects " << objectA->GetName() << " and " << objectB->GetName() << std::endl;
						}
					}
				}
			}
		}




		timeSincePhysicsStep += deltaTime;
		while (timeSincePhysicsStep > FIXEDFRAMERATE)
		{
			timeSincePhysicsStep -= FIXEDFRAMERATE;
		}

		window.clear();

		//loop through each gameobject in the vector
		for (GameObject* gameObject : gameObjects)
		{
			window.draw(gameObject->GetRectangleShape());
		}


		window.display();
	}


	//Memory cleanup
	ResourceManager::ClearTextureMap();
	GameManager::clearGameObjectVector();


	return 0;
}