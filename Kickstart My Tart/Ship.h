#pragma once
#include <SFML/Graphics.hpp>
#define SPRITE_WIDTH 99
#define SPRITE_HEIGHT 106
#define SPRITE_COUNT 8
class Ship
{
public:
	Ship(std::string filename, sf::RenderWindow &window);
	~Ship(void);
	void Draw(sf::RenderWindow &window);
	void Update();

	//public for debugging
	sf::Vector2f accel;
private:
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2f position;
	sf::Vector2f speed;
	enum {left, none, right} anim_state;
	int anim_frame;

	inline void next_frame();
};