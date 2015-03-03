#include "Fish.hpp"

#pragma region CONSTRUCTORS/DESTRUCTOR
Fish::Fish()
{	
	texture.loadFromFile("../Resources/Textures/fish.png");
	sprite.setTexture(texture);
	sprite.setOrigin(0.5, 0.5);
	bounds = sprite.getGlobalBounds();
	alive = true;
	size = 1.00f;
	velocity = 0.5f;

}
Fish::~Fish()
{
	
}
#pragma endregion

#pragma region ACCESSORS/MODIFIERS
sf::Sprite* Fish::getSprite()
{
	return &this->sprite;
}

sf::FloatRect Fish::getBounds()
{
	sf::FloatRect bound = this->getSprite()->getGlobalBounds();
	//bound.height -= 45.0f;
	//bound.width -= 35.0f;
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

bool Fish::setAlive(bool value)
{
	if (!(this->alive = value))
		return false;
}
bool Fish::getAlive() const
{
	return this->alive;
}
#pragma endregion