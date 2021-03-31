#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Tribe
{
public:
	const sf::Vector2f position;


	Tribe(int radius_);
	~Tribe();
	int citizens;
	int warriers;
	int armor;
	int money; 
	float radius;

	void Draw(sf::RenderWindow& window);
private:
	sf::CircleShape texture;
	sf::Vector2f CalculateNewTribePosition(const int radius_);
	static std::vector<sf::Vector2f> positionsArray;
	void initDataPosVector(const sf::Vector2f& position);
};