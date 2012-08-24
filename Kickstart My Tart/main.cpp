//#include <time.h>
//#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <list>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "common.h"
#include "Ship.h"
#include "Enemy.h"
#include "SimpleText.h"

int main()
{
	//---random!
	std::srand(time(NULL));
	double random = std::rand() % 360+1;

	std::list<Enemy*> enemy_list;
	std::list<Enemy*>::iterator itr_enemy_list;
	Enemy enemy1(100, 50);
	Enemy enemy2(50, 100);
	enemy_list.push_back(&enemy1);
	enemy_list.push_back(&enemy2);
	itr_enemy_list = enemy_list.begin();
	
	//---realtime editor
	//sf::Thread editor(&editor_wrapper, &ship);
	//editor.launch();

	//---fps counter
	int frame_count = 0;
	SimpleText text_fps("FPS: ");
	std::stringstream text_fps_number;
	sf::Clock fps_clock = sf::Clock();
	fps_clock.restart();

	sf::Event ev;

	//---window setup
	sf::RenderWindow window(sf::VideoMode(640, 800, 32), "Kickstart My Tart");
	window.setFramerateLimit(60);
	window.setKeyRepeatEnabled(false);

	Ship ship("ship_train.png", window);

	//-----------------------------------MAIN LOOP
	while (window.isOpen()) {
		window.clear();
		
		while (window.pollEvent(ev))
			if (ev.type == sf::Event::Closed || (ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::Escape)) {
				window.close();
				//editor.terminate();
			}

		//---fps
		frame_count++;
		if(fps_clock.getElapsedTime().asMilliseconds() > 1000.0f) {
			fps_clock.restart();
			text_fps_number.str("");
			text_fps_number << frame_count;
			text_fps.update("FPS: "+text_fps_number.str(), window);
			frame_count = 0;
			//TESTING
			random = std::rand()%360+1;
		}
		else
			text_fps.update(window);

		//---drawing
		std::for_each(enemy_list.begin(), enemy_list.end(), std::bind2nd(std::mem_fun<void, Enemy>(&Enemy::update), &random));
		std::for_each(enemy_list.begin(), enemy_list.end(), std::bind2nd(std::mem_fun<void, Enemy>(&Enemy::draw), &window));
		/*(*itr_enemy_list)->draw(window);
		++itr_enemy_list;
		(*itr_enemy_list)->draw(window);
		itr_enemy_list = enemy_list.begin();*/

		ship.update();
		ship.draw(window);

		window.display();
	}
	return EXIT_SUCCESS;
}
