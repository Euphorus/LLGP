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
	

	if (playerBounds.findIntersection(wallBounds))
	{
		float overlapX = wallBounds.size.x;
		float overlapY = wallBounds.size.y;

		LLGP::Vector2<float> moveDirection = objectOne->GetMoveDirection();

		//Calculate displacemnt needed to move the player out of the wall
		float displacementX = 0.0f;
		float displacementY = 0.0f;

		if (moveDirection.x > 0)
		{
			displacementX = overlapX;
		}
		else if (moveDirection.x < 0)
		{
			displacementX = -overlapX;
		}

		if (moveDirection.y > 0)
		{
			displacementY = overlapY;
		}
		else if (moveDirection.y < 0)
		{
			displacementY = -overlapY;
		}

		//Apply the displacement to move the player out of the wall
		LLGP::Vector2<float> currentPosition = objectOne->GetLocation();
		currentPosition.x -= displacementX;
		currentPosition.y -= displacementY;
		objectOne->SetLocation(currentPosition.x, currentPosition.y);
		objectOne->GetRectangleShape().setPosition(objectOne->GetLocation());

		return true;
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