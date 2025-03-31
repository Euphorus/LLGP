#include<iostream>
#include "Input.h"


void Input::HandleInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
	{
		moveUp.Invoke(sf::Keyboard::Key::W);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	{
		moveDown.Invoke(sf::Keyboard::Key::S);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		moveLeft.Invoke(sf::Keyboard::Key::A);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		moveRight.Invoke(sf::Keyboard::Key::D);
	}
}

void Input::BroadcastUp(sf::Keyboard::Key key)
{

}

void Input::BroadcastDown(sf::Keyboard::Key key)
{

}

void Input::BroadcastLeft(sf::Keyboard::Key key)
{

}

void Input::BroadcastRight(sf::Keyboard::Key key)
{

}