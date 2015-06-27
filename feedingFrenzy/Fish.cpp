#include "Fish.hpp"
#include <iostream>

#pragma region CONSTRUCTORS/DESTRUCTOR
Fish::Fish()
{

}
Fish::~Fish()
{}
#pragma endregion

#pragma region ACCESSORS/MODIFIERS
sf::Sprite* Fish::getSprite() 
{
	return &this->sprite;
}

sf::FloatRect Fish::getBounds()
{
	sf::FloatRect bound = this->getSprite()->getGlobalBounds();
	bound.height -= 10.0f; 
	bound.width -= 15.0f;
	return bound;
}
bool Fish::setBounds(sf::FloatRect *bounds)
{
	this->bounds = *bounds;
	return 0;
}

bool Fish::setTexture(string path)
{
	bool result = true;
	if (!(texture.loadFromFile(path)))
		result = false;
	texture.setSmooth(true);
	sprite.setTexture(texture);	
	
	return result;
}

bool Fish::setSize(float value)
{
	bool result = true;
	if (!(this->size = value))
		result = false;
	return result;
}
float Fish::getSize() const
{
	return this->size;
}

bool Fish::setVelocity(float value)
{
	bool result = true;
	if (!(this->velocity = value))
		result = false;
	return result;
}
float Fish::getVelocity() const
{
	return this->velocity;
}
void Fish::setAlive(bool value)
{
	this->alive = value;
}
bool Fish::getAlive() const
{
	return this->alive;
}
#pragma endregion