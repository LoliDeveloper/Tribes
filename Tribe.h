#pragma once
#include <SFML/Graphics.hpp>

class Tribe
{
public:
	Tribe();
	~Tribe();
	int citizens;
	int warriers;
	int armor;
	int money;

	void Draw(sf::RenderWindow& window);
private:
	sf::CircleShape texture;

};