#pragma once
#include <SFML/Graphics.hpp>

class Enemy
{
public:
	Enemy(float x, float y);
	~Enemy(void);
	void draw(sf::RenderWindow &window);
	void update();
private:
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2f position;
};
