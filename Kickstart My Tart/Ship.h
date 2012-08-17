#pragma once
#include <SFML/Graphics.hpp>
#define SPRITE_WIDTH 111
#define SPRITE_HEIGHT 150
#define SPRITE_COUNT 7

class Ship
{
public:
	Ship(std::string filename, sf::RenderWindow &window);
	~Ship(void);
	void draw(sf::RenderWindow &window);
	void update();
	void edit();
	void* getAddress();

	//public for testing
	sf::Vector2f accel;
private:
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2f position;
	sf::Vector2f speed;
	sf::Clock clock;
	enum {left, none, right} anim_state;
	int anim_frame, frame_count;
	int array_memory[SPRITE_COUNT];
};