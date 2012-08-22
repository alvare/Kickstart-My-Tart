#define _USE_MATH_DEFINES
//#include <cmath>
#include <iostream>
#include "Enemy.h"
#define RAD M_PI/180

Enemy::Enemy(float x, float y)
{
	sf::Image image;
	image.create(20, 20, sf::Color(200, 20, 20));
	texture.loadFromImage(image);
	sprite.setTexture(texture);

	vel = 1.0f;
	angle = 0.0f;

	//---defaults
	position = sf::Vector2f(x, y);
	sprite.setPosition(position);
}


Enemy::~Enemy(void)
{
}

void Enemy::draw(sf::RenderWindow &window)
{
	window.draw(sprite);
}

void Enemy::update(float angle)
{
	position += sf::Vector2f(vel*sin(angle*RAD), vel*cos(angle*RAD));
	sprite.setPosition(position);
}