#include "Shapes.h"

Shapes::Shapes(unsigned int width, unsigned int height) : width(width), height(height)
{
	window = new sf::RenderWindow(sf::VideoMode({ width, height }), "RAYLIB AND SDL2 BETTER!!!");
	window->setFramerateLimit(30);

	circle.setRadius(64.f);
	circle.setOrigin(circle.getGeometricCenter());
	circle.setPosition({ width / 2.f, height / 2.f });
	circle.setFillColor(sf::Color::Green);
	circle.setOutlineThickness(4.7f);
	circle.setOutlineColor(sf::Color::Magenta);
	circle.setPointCount(5);
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

		window->clear();
		window->draw(circle);
		window->display();
	}
}