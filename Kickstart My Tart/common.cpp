#include "common.h"

void clamp(float &n, const float &min, const float &max)
{
	n = n > max ? max : n;
	n = n < min ? min : n;
}

void vclamp(sf::Vector2f &n, const sf::Vector2f &min, const sf::Vector2f &max)
{
	clamp(n.x, min.x, max.x);
	clamp(n.y, min.y, max.y);
}


void Reduce (sf::Vector2f &speed, const sf::Vector2f &friciton)
{
	speed.x *= friciton.x;
	speed.y *= friciton.y;
}