#include "Ship.h"
#include "common.h"
#include <iostream>

Ship::Ship(std::string filename, sf::RenderWindow &window)
{
	//---animation init
	anim_state = none;
	anim_frame = 0;

	int tmp[SPRITE_COUNT] = {4, 4, 3, 3, 2, 2, 4}; //ultra efficient array initializing
	for(int i=0;i<SPRITE_COUNT;i++){
		array_memory[i] = tmp[i];
	}
	frame_count = 0;

	clock.restart();

	sf::Image image;
	image.loadFromFile(filename);
	image.createMaskFromColor(sf::Color(255,0,255)); //colorkey stuff
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, SPRITE_WIDTH, SPRITE_HEIGHT));

	//---defaults
	accel = sf::Vector2f (2.0f, 2.0f);
	speed = sf::Vector2f (0.0f, 0.0f);
		
	//---initial position
	position = sf::Vector2f (window.getSize().x/2-sprite.getGlobalBounds().width / 2, window.getSize().y-sprite.getGlobalBounds().height);
	sprite.setPosition(position);
}

Ship::~Ship(void)
{
}

void Ship::draw(sf::RenderWindow &window)
{
	sprite.setPosition(position);
	vclamp(position, sf::Vector2f(0, 0), sf::Vector2f(window.getSize().x-sprite.getGlobalBounds().width, window.getSize().y-sprite.getGlobalBounds().height));
	window.draw(sprite);
}

void Ship::update()
{

	//input
	speed.x = speed.y = 0;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		anim_state = right;
		speed.x = accel.x;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		anim_state = left;
		speed.x = -accel.x;
	}
	else
	{
		anim_state = none;
		anim_frame = 0;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		speed.y = -accel.y;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		speed.y = accel.y;

	//---animating
	if(clock.getElapsedTime().asMilliseconds() > 10)
	{
		if(anim_state == right)
		{
			if(++frame_count > array_memory[anim_frame]){
				if (++anim_frame > SPRITE_COUNT)
					anim_frame = 5;
				frame_count = 0;
			}
			sprite.setTextureRect(sf::IntRect(SPRITE_WIDTH*anim_frame, 0, SPRITE_WIDTH, SPRITE_HEIGHT));
		}
		else
			sprite.setTextureRect(sf::IntRect(0, 0, SPRITE_WIDTH, SPRITE_HEIGHT));

		clock.restart();
		position = position + speed;
	}
}

void Ship::edit()
{
	std::string input = "";
	char member, var;
	while(input != "qq")
	{
		std::cin >> input;
		member = input.at(0);
		var = input.at(1);

		switch (member)
		{
		case 'a':
			switch (var)
			{
			case 'x':
				std::cin >> this->accel.x;
				break;
			case 'y':
				std::cin >> this->accel.y;
				break;
			}
			break;
		}
	}
}
