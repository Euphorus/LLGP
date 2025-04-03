#pragma once
#include "Component.h"
#include "GameObject.h"

class EnemyComponent : public Component
{
public:
	EnemyComponent(GameObject* owner);
	~EnemyComponent();

	void Move();

private:
	LLGP::Vector2<float> m_EnemySize = LLGP::Vector2<float>::one * 50;

	sf::RectangleShape m_EnemyShapeRectangle;

	sf::IntRect m_EnemyTextureUV;

	//float m_MovementSpeed = 0.1f;
	float m_MovementSpeed = 3.1f;   //for uni pcs
};

