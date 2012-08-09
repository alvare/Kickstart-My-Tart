#pragma once
#include <SFML/Graphics.hpp>
class Ship
{
public:
	Ship(std::string file, sf::RenderWindow &window);
	~Ship(void);
	void Draw(sf::RenderWindow &window);
	void Update();
private:
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2f position;
	sf::Vector2f speed;
	//sf::Vector2f maxspeed;
	//sf::Vector2f acceleration;
	//sf::Vector2f friction;
	sf::Vector2f accel;
};