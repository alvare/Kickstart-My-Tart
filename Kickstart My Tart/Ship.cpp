#include <iostream>
#include "Ship.h"
#include "common.h"

Ship::Ship(std::string filename, sf::RenderWindow &window)
{
	//---animation init
	anim_state = NONE;
	anim_frame = 0;
	//ultra efficient array initializing
	int tmp[SPRITE_COUNT] = {8, 6, 4, 2};
	std::copy(&tmp[0], &tmp[SPRITE_COUNT], anim_timing);
	timing_counter = 0;

	clock.restart();

	texture.loadFromFile(filename);
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, SPRITE_WIDTH, SPRITE_HEIGHT));

	//---constants
	c_accel = sf::Vector2f (0.4f, 0.4f);
	//---defaults
	speed = sf::Vector2f (0.0f, 0.0f);
	position = sf::Vector2f (window.getSize().x/2-sprite.getGlobalBounds().width / 2, window.getSize().y-sprite.getGlobalBounds().height);

	sprite.setPosition(position);
}

Ship::~Ship(void)
{
}

void Ship::draw(sf::RenderWindow &window)
{
	vclamp(position, sf::Vector2f(0, 0), sf::Vector2f(window.getSize().x-sprite.getGlobalBounds().width, window.getSize().y-sprite.getGlobalBounds().height));
	sprite.setPosition(position);
	window.draw(sprite);
}

void Ship::update()
{
	//---input
	speed.x = speed.y = 0;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		anim_state = RIGHT;
		speed.x = c_accel.x;
	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		anim_state = LEFT;
		speed.x = -c_accel.x;
	} else {
		anim_state = NONE;
		anim_frame = 0;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		speed.y = -c_accel.y;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		speed.y = c_accel.y;

	//---animating
	if(++timing_counter > anim_timing[anim_frame]) {
		if (++anim_frame > SPRITE_COUNT-1)
			anim_frame -= 1;
		timing_counter = 0;
	}

	sprite.setTextureRect(sf::IntRect(SPRITE_WIDTH*anim_frame, SPRITE_HEIGHT*anim_state, SPRITE_WIDTH, SPRITE_HEIGHT));

	//---updating
	position.y = position.y + speed.y*clock.getElapsedTime().asMilliseconds();
	position.x = position.x + speed.x*clock.getElapsedTime().asMilliseconds();

	clock.restart();
}

void Ship::edit()
{
	std::string input = "";
	char member, var;
	while(input != "qq") {
		while (input.length() > 2)
			std::cin >> input;
		member = input.at(0);
		var = input.at(1);

		switch (member) {
		case 'a':
			switch (var) {
			case 'x':
				std::cin >> this->c_accel.x;
				break;
			case 'y':
				std::cin >> this->c_accel.y;
				break;
			}
			break;
		}
	}
}
