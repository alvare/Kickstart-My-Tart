#include <iostream>
#include <sstream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "Ship.h"
#include "SimpleText.h"
//#include "common.h"

void editor_wrapper(Ship* ship){
	ship->edit();
}

int main()
{
	//---window setup
	sf::RenderWindow window(sf::VideoMode(640, 800, 32), "Kickstart My Tart");
	//window.setFramerateLimit(60);
	window.setKeyRepeatEnabled(false);

	Ship ship("ship_train.bmp", window);

	sf::Thread editor(&editor_wrapper, &ship);
	editor.launch();
	
	//---fps counter
	int frame_count = 0;
	SimpleText text_fps("FPS: ");
	std::stringstream text_fps_number;
	sf::Clock fps_clock = sf::Clock();
	fps_clock.restart();

	while (window.isOpen())
	{

		//---fps
		frame_count++;
		if(fps_clock.getElapsedTime().asSeconds() > 1.0f){
			fps_clock.restart();
			text_fps_number.str("");
			text_fps_number << frame_count;
			text_fps.update("FPS: "+text_fps_number.str(), window);
			frame_count = 0;
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

		//---drawing
		window.clear();

		window.draw(text_fps);

		ship.update();
		ship.draw(window);

		
		window.display();
	}
	return EXIT_SUCCESS;
}
