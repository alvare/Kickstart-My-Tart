#pragma once
#include <SFML/Graphics.hpp>
class Ship
{
public:
	Ship(std::string file, sf::RenderWindow &window);
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
};