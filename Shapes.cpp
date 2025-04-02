#include "Shapes.h"

Shapes::Shapes(unsigned int width, unsigned int height) : width(width), height(height)
{
	window = new sf::RenderWindow(sf::VideoMode({ width, height }), "RAYLIB AND SDL2 BETTER!!!");
	window->setFramerateLimit(30);

	//

	//bind the MoveShape function to the Input events
	input.moveUp.AddListener(this, [this](sf::Keyboard::Key key) {MoveShape(key); });
	input.moveDown.AddListener(this, [this](sf::Keyboard::Key key) {MoveShape(key); });
	input.moveLeft.AddListener(this, [this](sf::Keyboard::Key key) {MoveShape(key); });
	input.moveRight.AddListener(this, [this](sf::Keyboard::Key key) {MoveShape(key); });
}

Shapes::~Shapes()
{
	delete window;
}

void Shapes::Run()
{
	while (window->isOpen())
	{
		while (const std::optional event = window->pollEvent())
		{
			if (event->is<sf::Event::Closed>())
			{
				window->close();
			}
			else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
			{
				if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
				{
					window->close();
				}
			}
		}

		input.HandleInput();

		window->clear();
		window->draw(circle);
		window->display();
	}
}

void Shapes::MoveShape(sf::Keyboard::Key key)
{
	switch (key)
	{
	case sf::Keyboard::Key::W:
		circle.move({0.f, -speed});
		std::cout << "W is being pressed...\n";
		break;
	case sf::Keyboard::Key::S:
		circle.move({ 0.f, speed });
		std::cout << "S is being pressed...\n";
		break;
	case sf::Keyboard::Key::A:
		circle.move({ -speed, 0.f });
		std::cout << "A is being pressed...\n";
		break;
	case sf::Keyboard::Key::D:
		circle.move({ speed, 0.f });
		std::cout << "D is being pressed...\n";
		break;
	default:
		break;
	}
}