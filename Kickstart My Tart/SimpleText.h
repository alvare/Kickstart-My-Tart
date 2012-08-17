#pragma once
#include <SFML/Graphics.hpp>

class SimpleText :
	public sf::Text
{
public:
	SimpleText(std::string text);
	~SimpleText(void);
	void update(std::string text, sf::RenderWindow &window);
};

