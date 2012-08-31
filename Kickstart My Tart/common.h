#pragma once
#include <SFML/Graphics.hpp>
#include "Ship.h"

void clamp(float &n, const float &min, const float &max);

void vclamp(sf::Vector2f &n, const sf::Vector2f &min, const sf::Vector2f &max);

void editor_wrapper(Ship* ship);