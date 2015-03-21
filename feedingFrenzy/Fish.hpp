#ifndef FISH_HPP
#define FISH_HPP

#pragma region EXTERNALS
#include <SFML/Graphics.hpp>
#include <string>

using namespace std;

#pragma endregion
class Fish
{
public:
	Fish(float size, float velocity);
	virtual ~Fish();
	bool setTexture(string path);
	sf::Sprite* getSprite();
	
	bool setBounds(sf::FloatRect *bounds);
	sf::FloatRect getBounds();

	bool setSize(float value);
	float getSize() const;

	bool setVelocity(float value);
	float getVelocity() const;

 
private:
	Fish();
	sf::Sprite sprite;
	sf::Texture texture;
	sf::FloatRect bounds;
	float	size,
			velocity;
};



#endif