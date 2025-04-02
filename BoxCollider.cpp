#include "BoxCollider.h"

BoxCollider::BoxCollider(GameObject* owner) : ColliderComponent(owner)
{

}

BoxCollider::~BoxCollider()
{

}

bool BoxCollider::CheckCollision(GameObject* objectOne, GameObject* objectTwo)
{

}

bool BoxCollider::WallCollision(GameObject* objectOne, GameObject* objectTwo)
{

}

void BoxCollider::DrawOutlines(sf::RectangleShape& shape)
{
	shape.setOutlineThickness(3.f);
	shape.setOutlineColor(sf::Color(0, 0, 255));
}

void BoxCollider::SetGlobalBounds(sf::FloatRect& bounds)
{
	m_Bounds = bounds;
}

sf::FloatRect BoxCollider::GetGlobalBounds()
{
	return m_Bounds;
}