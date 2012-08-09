#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "Ship.h"

void edit(Ship *object)
{
	std::string input = "";
	char member, var;
	while(input != "qq")
	{
		std::cin >> input;
		member = input.at(0);
		var = input.at(1);

		switch (member)
		{
		case 'a':
			switch (var)
			{
			case 'x':
				std::cin >> object->accel.x;
				break;
			case 'y':
				std::cin >> object->accel.y;
				break;
			}
			break;
		}
	}
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(640, 800, 32), "Kickstart My Tart");
	window.setFramerateLimit(60);
	window.setKeyRepeatEnabled(false);

	Ship ship("srun.png", window);

	sf::Thread editor(&edit, &ship);
	editor.launch();
	
	while (window.isOpen())
	{
		sf::Event ev;
		while (window.pollEvent(ev))
		{
			if (ev.type == sf::Event::Closed || (ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::Escape))
			{
				window.close();
			}
		}
		window.clear();
		ship.Update();
		ship.Draw(window);
		window.display();
	}
	return EXIT_SUCCESS;
}
