#pragma once
#include<SFML/Graphics.hpp>
#include "Input.h"

class Shapes
{
public:
	Shapes(unsigned int width, unsigned int height);
	~Shapes();
	void Run();

private:
	unsigned int width;
	unsigned int height;
	sf::RenderWindow* window;
	sf::CircleShape circle;
	Input input;
	float speed = 5.0f;

	void MoveShape(sf::Keyboard::Key key);
};

