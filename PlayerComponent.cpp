#include "PlayerComponent.h"

PlayerComponent::PlayerComponent(GameObject* owner) : Component(owner)
{
	std::cout << "PlayerComponent Constructed" << std::endl;
	std::cout << "GameObject value in PlayerComponent : " << _GameObject << std::endl;

	_GameObject->SetLocation(650, 450);


	//Cookie cutter part of sprite sheet (0, 0 = Coordinates, 24, 24 = Size of rectangle
	m_PlayerTextureUV = sf::IntRect({ 210, 164 }, {24, 24});

	m_PlayerShapeRectangle.setSize(m_PlayerSize);

	//Set texture to be the whole sprite sheet
	m_PlayerShapeRectangle.setTexture(&ResourceManager::getTexture("Player"));


	//Set the texture to the cookie cutter section of the sprite sheet
	m_PlayerShapeRectangle.setTextureRect(m_PlayerTextureUV);

	//Set Rect to the middle / position
	m_PlayerShapeRectangle.setOrigin(m_PlayerSize / 2);
	m_PlayerShapeRectangle.setPosition(_GameObject->GetLocation());

	_GameObject->SetRectangleShape(m_PlayerShapeRectangle);

}

PlayerComponent::~PlayerComponent() {}

void PlayerComponent::Move(float deltaTime)
{
	LLGP::Vector2<float> direction(0.0f, 0.0f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		_GameObject->GetLocation().x -= m_MovementSpeed * deltaTime;
		direction.x = -1.0f;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		_GameObject->GetLocation().x += m_MovementSpeed * deltaTime;
		direction.x = 1.0f;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
	{
		_GameObject->GetLocation().y -= m_MovementSpeed * deltaTime;
		direction.y = -1.0f;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	{
		_GameObject->GetLocation().y += m_MovementSpeed * deltaTime;
		direction.y = 1.0f;
	}

	direction.normalise();

	_GameObject->GetMoveDirection() = direction;

	_GameObject->GetRectangleShape().setPosition(_GameObject->GetLocation());
}

void PlayerComponent::Shooting()
{
	GameObject* bullet = new GameObject();
	bullet->Instantiate(bullet);

	std::cout << "mouse clicked." << std::endl;
}