#include "Enemy.h"
#include <iostream>


Enemy::Enemy(float x, float y)
{
	sf::Image image;
	image.create(20, 20, sf::Color(200, 20, 20));
	texture.loadFromImage(image);
	sprite.setTexture(texture);

	//---defaults
	position = sf::Vector2f(x, y);
}


Enemy::~Enemy(void)
{
}

void Enemy::draw(sf::RenderWindow &window)
{
	window.draw(sprite);
}

void Enemy::update()
{
	position += sf::Vector2f(1, 1);
	sprite.setPosition(position);
}