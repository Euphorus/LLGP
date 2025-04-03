#include "BoxCollider.h"

BoxCollider::BoxCollider(GameObject* owner) : ColliderComponent(owner)
{

}

BoxCollider::~BoxCollider()
{

}

bool BoxCollider::CheckCollision(GameObject* objectOne, GameObject* objectTwo)
{
	sf::RectangleShape rectOne = objectOne->GetRectangleShape();
	sf::RectangleShape rectTwo = objectTwo->GetRectangleShape();

	if (rectOne.getGlobalBounds().findIntersection(rectTwo.getGlobalBounds()))
	{
		return true;
	}

	return false;
}

bool BoxCollider::WallCollision(GameObject* objectOne, GameObject* objectTwo)
{
	sf::FloatRect playerBounds = objectOne->GetRectangleShape().getGlobalBounds();
	sf::FloatRect wallBounds = objectTwo->GetRectangleShape().getGlobalBounds();
	sf::FloatRect intersection;

	if (playerBounds.findIntersection({wallBounds, intersection}))
	{
		float overlapX = intersection.size.x;
		float overlapY = intersection.size.y;

		//Determine the direction of player movement
		LLGP::Vector2<float> moveDirection = objectOne->GetMoveDirection();

		//Calculate

	}



	return false;
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