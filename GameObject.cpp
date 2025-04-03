#include "GameObject.h"

GameObject::GameObject()
{
	std::cout << "GameObject constructed\n";
}

GameObject::~GameObject() {}

void GameObject::Update(float deltaTime) {}

void GameObject::Render(sf::RenderWindow& window) {}

void GameObject::SetActive(bool newActive) {}

void GameObject::SetTexture(sf::Texture* texture)
{
	m_SpriteShape.setTexture(texture);

	std::cout << "Texture Address: " << m_SpriteShape.getTexture() << std::endl;
}

const sf::Texture* GameObject::GetTexture()
{
	return m_SpriteShape.getTexture();
}

void GameObject::SetTextureRect(sf::IntRect& textureRect)
{
	m_SpriteShape.setTextureRect(textureRect);
}

sf::IntRect GameObject::GetTextureRect()
{
	return m_SpriteShape.getTextureRect();
}

void GameObject::SetRectangleShape(sf::RectangleShape& shape)
{
	m_SpriteShape = shape;
}

sf::RectangleShape& GameObject::GetRectangleShape()
{
	return m_SpriteShape;
}

void GameObject::SetLocation(float x, float y)
{
	m_location.x = x;
	m_location.y = y;

	std::cout << "Location: " << x << ":" << y << std::endl;
}

LLGP::Vector2<float>& GameObject::GetLocation()
{
	return  m_location;
}

void GameObject::DrawOutlines(sf::RectangleShape& shape)
{
	shape.setOutlineThickness(3);
	shape.setOutlineColor(sf::Color(255, 0, 255));
}

bool GameObject::HasBoxCollider(GameObject* GameObject)
{
	BoxCollider* boxCollider = GameObject->GetComponent<BoxCollider>();

	return (boxCollider != nullptr);
}

LLGP::Vector2<float>& GameObject::GetMoveDirection()
{
	return m_MoveDirection;
}

void GameObject::SetIsWall(bool isWall)
{
	m_IsWall = isWall;
}

bool GameObject::GetIsWall()
{
	return m_IsWall;
}

void GameObject::SetIsShooting(bool isShooting)
{
	m_IsShooting = isShooting;
}

bool GameObject::GetIsShooting()
{
	return m_IsShooting;
}

GameObject* GameObject::Instantiate(GameObject* Object)
{
	Object = new GameObject();
	return Object;
}

void GameObject::Destroy()
{
	GameManager::clearGameObjectVector();
	delete this;
}