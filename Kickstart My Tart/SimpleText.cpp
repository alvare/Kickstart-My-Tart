#include "SimpleText.h"

SimpleText::SimpleText(std::string text)
{
	this->setString(text);
}


SimpleText::~SimpleText(void)
{
}

void SimpleText::update(std::string text, sf::RenderWindow &window)
{
	this->setString(text);
	window.draw(*this);
}