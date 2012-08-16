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
	//window.setFramerateLimit(60);
	window.setKeyRepeatEnabled(false);

	Ship ship("ship_train.bmp", window);

	sf::Thread editor(&edit, &ship);
	editor.launch();
	
	int frame_counter = 0;
	sf::Clock fps = sf::Clock();
	fps.restart();

	while (window.isOpen())
	{

		//FPS
		frame_counter++;
		if(fps.getElapsedTime().asSeconds() > 1.0f){
			fps.restart();
			//std::cout << frame_counter;
			frame_counter = 0;
		}

		sf::Event ev;
		while (window.pollEvent(ev))
		{
			if (ev.type == sf::Event::Closed || (ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::Escape))
			{
				window.close();
				editor.terminate();
			}
		}
		window.clear();
		ship.Update();
		ship.Draw(window);
		window.display();
	}
	return EXIT_SUCCESS;
}
