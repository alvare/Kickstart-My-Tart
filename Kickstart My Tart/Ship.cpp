#include "Ship.h"
#include "common.h"

Ship::Ship(std::string filename, sf::RenderWindow &window)
{
	anim_state = none;
	anim_frame = 0;

	sf::Image image;
	image.loadFromFile(filename);
	image.createMaskFromColor(sf::Color(255,0,255));
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, SPRITE_WIDTH, SPRITE_HEIGHT));

	//defaults
	accel = sf::Vector2f (3.0f, 3.0f);
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
	//animating
	if(anim_state == right)
	{
		if (++anim_frame > 7)
			anim_frame = 5;
		sprite.setTextureRect(sf::IntRect(SPRITE_WIDTH*anim_frame, 0, SPRITE_WIDTH, SPRITE_HEIGHT));
	}
	else
		sprite.setTextureRect(sf::IntRect(0, 0, SPRITE_WIDTH, SPRITE_HEIGHT));

	position = position+speed;
	vclamp(position, sf::Vector2f(0, 0), sf::Vector2f(window.getSize().x-sprite.getGlobalBounds().width, window.getSize().y-sprite.getGlobalBounds().height));
	sprite.setPosition(position);
	window.draw(sprite);
}

void Ship::Update()
{
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
}
