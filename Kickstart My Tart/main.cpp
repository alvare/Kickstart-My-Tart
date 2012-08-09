#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Ship.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(640, 800, 32), "Kickstart My Tart");
	window.setFramerateLimit(60);
	window.setKeyRepeatEnabled(false);

	Ship ship("srun.png", window);
	
	while (window.isOpen())
	{
		sf::Event ev;
		while (window.pollEvent(ev))
		{
			if (ev.type == sf::Event::Closed || (ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::Escape))
				window.close();
		}
		window.clear();
		ship.Update();
		ship.Draw(window);
		window.display();
	}
	return EXIT_SUCCESS;
}
