#include "Ship.h"
#include "common.h"
#include <cmath>

Ship::Ship(std::string file, sf::RenderWindow &window)
{
	texture.loadFromFile(file);
	sprite.setTexture(texture);

	//defaults
	accel = sf::Vector2f (2.0f, 2.0f);
	speed = sf::Vector2f (0.0f, 0.0f);
		
	//initial position
	position = sf::Vector2f (window.getSize().x/2-sprite.getGlobalBounds().width / 2, window.getSize().y-sprite.getGlobalBounds().height);
	sprite.setPosition(position);
}

Ship::~Ship(void)
{
}

void Ship::Draw(sf::RenderWindow &window)
{

	position = position+speed;
	vclamp(position, sf::Vector2f(0, 0), sf::Vector2f(window.getSize().x-sprite.getGlobalBounds().width, window.getSize().y-sprite.getGlobalBounds().height));
	sprite.setPosition(position);
	window.draw(sprite);
}

void Ship::Update()
{
	/*switch (ev.key.code){
		case sf::Keyboard::Right:
			acceleration.x = ev.type == ev.KeyPressed? init_accel.x : 0;
			break;
		case sf::Keyboard::Left:
			acceleration.x = ev.type == ev.KeyPressed? -init_accel.x : 0;
			break;
		case sf::Keyboard::Up:
			acceleration.y = ev.type == ev.KeyPressed? -init_accel.y : 0;
			break;
		case sf::Keyboard::Down:
			acceleration.y = ev.type == ev.KeyPressed? init_accel.y : 0;
			break;
	}*/
	speed.x = speed.y = 0;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		speed.x = accel.x;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		speed.x = -accel.x;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		speed.y = -accel.y;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		speed.y = accel.y;
}
