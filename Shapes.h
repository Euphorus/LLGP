#pragma once
#include<SFML/Graphics.hpp>

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
};

