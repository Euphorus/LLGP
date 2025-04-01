#include<iostream>
#include "Component.h"


void Component::Start()
{
	std::cout << "Start was called" << std::endl;
}

void Component::Update(float deltaTime)
{
	std::cout << "Update was called" << std::endl;
}

void Component::FixedUpdate(float fixedDeltaTime)
{
	std::cout << "Fixed update was called" << std::endl;
}

void Component::onEnable()
{
	std::cout << "On enabled was called" << std::endl;
}

void Component::onDisable()
{
	std::cout << "On disabled was called" << std::endl;
}