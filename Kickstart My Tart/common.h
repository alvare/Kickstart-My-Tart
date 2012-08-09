#pragma once
#include <SFML/Graphics.hpp>

void clamp(float &n, const float &min, const float &max);

void vclamp(sf::Vector2f &n, const sf::Vector2f &min, const sf::Vector2f &max);

//void Reduce (sf::Vector2f &speed, const sf::Vector2f &friciton);