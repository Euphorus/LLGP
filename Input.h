#pragma once
#include <SFML/Graphics.hpp>
#include "Event.h"

class Input
{
	Input();
	~Input();
	void HandleInput();

public:
	LLGP::Event<sf::Keyboard::Key> moveUp;
	LLGP::Event<sf::Keyboard::Key> moveDown;
	LLGP::Event<sf::Keyboard::Key> moveLeft;
	LLGP::Event<sf::Keyboard::Key> moveRight;

private:
	void BroadcastUp(sf::Keyboard::Key key);
	void BroadcastDown(sf::Keyboard::Key key);
	void BroadcastLeft(sf::Keyboard::Key key);
	void BroadcastRight(sf::Keyboard::Key key);

};

