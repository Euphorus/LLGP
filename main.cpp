#include <SFML/Graphics.hpp>

/*
    This version of the SFML "hello world" is statically linked, you may wish to try the dynamically linked version as well.
*/
#ifdef _DEBUG
int main()
#else
int WinMain()
#endif
{
	unsigned int width = 640;
	unsigned int height = 480;
	sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode({ width, height }), "RAYLIB AND SDL2 BETTER!!!!");
	window->setFramerateLimit(30);

	sf::CircleShape circle(64.f);
	circle.setOrigin(circle.getGeometricCenter());
	circle.setPosition({ width / 2.f, height / 2.f });
	circle.setFillColor(sf::Color::Green);
	circle.setOutlineThickness(4.7f);
	circle.setOutlineColor(sf::Color::Magenta);
	circle.setPointCount(5);

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

	delete window;
	return 0;
}