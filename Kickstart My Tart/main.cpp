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
	/*std::list<Enemy*>::iterator itr_enemy_list;
	Enemy enemy1(100, 50), enemy2(50, 100);
	enemy_list.push_back(&enemy1);
	enemy_list.push_back(&enemy2);*/
	//itr_enemy_list = enemy_list.begin();
	
	//---scene loading
	sf::Clock scene_timer;
	std::vector<float[3]> scene_script;
	float a[3];
	a[0] = 1000.f;
	a[1] = 100.f;
	a[2] = 100.f;
	scene_script.push_back(a);
	a[0] = 1500.f;
	//scene_script.push_back(a);

	//---realtime editor
	//sf::Thread editor(&editor_wrapper, &ship);
	//editor.launch();

	//---fps counter
	int frame_count = 0;
	SimpleText text_fps("FPS: ");
	std::stringstream text_fps_number;
	sf::Clock fps_clock;
	fps_clock.restart();

	sf::Event ev;

	//---window setup
	sf::RenderWindow window(sf::VideoMode(640, 800, 32), "Kickstart My Tart");
	window.setFramerateLimit(60);
	window.setKeyRepeatEnabled(false);

	Ship ship("ship_train.png", window);

	//-----------------------------------MAIN LOOP
	scene_timer.restart();
	while (window.isOpen()) {
		window.clear();
		
		//---events
		while (window.pollEvent(ev))
			if (ev.type == sf::Event::Closed || (ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::Escape))
				window.close();
				//editor.terminate();

		//---scene
		if (scene_timer.getElapsedTime().asMilliseconds() > scene_script.front()[0]) {
			Enemy enemy(scene_script.front()[1], scene_script.front()[2]);
			enemy_list.push_back(&enemy);
			scene_script.pop_back();
		}


		//---drawing
		if (!enemy_list.empty()) {
			std::for_each(enemy_list.begin(), enemy_list.end(), std::bind2nd(std::mem_fun<void, Enemy>(&Enemy::update), &random));
			std::for_each(enemy_list.begin(), enemy_list.end(), std::bind2nd(std::mem_fun<void, Enemy>(&Enemy::draw), &window));
		}
		/*(*itr_enemy_list)->draw(window);
		++itr_enemy_list;
		(*itr_enemy_list)->draw(window);
		itr_enemy_list = enemy_list.begin();*/

		ship.update();
		ship.draw(window);
		
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

		window.display();
	}
	return EXIT_SUCCESS;
}
