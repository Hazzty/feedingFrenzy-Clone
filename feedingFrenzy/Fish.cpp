#include "Fish.hpp"

Fish::Fish()
{	
	texture.loadFromFile("C:/Users/Hampus/Documents/Visual Studio 2013/Projects/feedingFrenzy/Resources/Textures/fish.png");
	sprite.setTexture(texture);
	bounds = sprite.getGlobalBounds();
	sprite.setOrigin(0.5, 0.5);
	
	size = 1.00f;
	velocity = 2.0f;
}
Fish::~Fish()
{
	
}sf::Sprite* Fish::getSprite()
{
	return &this->sprite;
}



bool Fish::setBounds(sf::FloatRect bounds)
{
	this->bounds = bounds;
	return true;
}
sf::FloatRect Fish::getBounds()
{
	return this->bounds;
}

bool Fish::setTexture(string path)
{
	sf::Texture texture;

	bool result = true;
	if (!(texture.loadFromFile(path)))
		result = false;

	sprite.setTexture(texture);
	sf::FloatRect boundingBox = sprite.getGlobalBounds();

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