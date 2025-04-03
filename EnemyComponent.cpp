#include "EnemyComponent.h"

EnemyComponent::EnemyComponent(GameObject* owner) : Component(owner)
{
	_GameObject->SetLocation(450, 450);

	//Cookie cutter part of sprite sheet 
	m_EnemyTextureUV = sf::IntRect({ 148, 235 }, { 24, 24 });

	m_EnemyShapeRectangle.setSize(m_EnemySize);

	//Set the texture to the cookie cutter section of the sprite sheet
	m_EnemyShapeRectangle.setTextureRect(m_EnemyTextureUV);

	//Set Rect to the middle / position
	m_EnemyShapeRectangle.setOrigin(m_EnemySize / 2);
	m_EnemyShapeRectangle.setPosition(_GameObject->GetLocation());

	//Settin git
	_GameObject->SetRectangleShape(m_EnemyShapeRectangle);
}


EnemyComponent::~EnemyComponent() {}

void EnemyComponent::Move()
{
	LLGP::Vector2<float> direction(0.0f, 0.0f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
	{
		_GameObject->GetLocation().x -= m_MovementSpeed;
		direction.x = -1.0f;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
	{
		_GameObject->GetLocation().x += m_MovementSpeed;
		direction.x = 1.0f;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
	{
		_GameObject->GetLocation().y -= m_MovementSpeed;
		direction.y = -1.0f;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
	{
		_GameObject->GetLocation().y += m_MovementSpeed;
		direction.y = 1.0f;
	}

	direction.normalise();

	_GameObject->GetMoveDirection() = direction;

	_GameObject->GetRectangleShape().setPosition(_GameObject->GetLocation());
}