#pragma once
#include "Component.h"
#include "GameObject.h"

class PlayerComponent : public Component
{
public:
	PlayerComponent(GameObject* owner);
	~PlayerComponent();

	void Move(float deltaTime);

	void Shooting();

private:
	LLGP::Vector2<float> m_PlayerSize = LLGP::Vector2<float>::one * 50;

	sf::RectangleShape m_PlayerShapeRectangle;

	sf::IntRect m_PlayerTextureUV;

	float m_MovementSpeed = 37.0f;
	//float m_MovementSpeed = 3.1f; for uni pcs
};

