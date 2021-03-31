#include "Tribe.h"
#include "MyFunctions.h"
extern int widthWindow;
extern int heightWindow;

float radius = 150.f;
Tribe::Tribe():
	position(sf::Vector2f((widthWindow - 2 * radius)* get_rand_double(), (heightWindow - 2 * radius) * get_rand_double()))
{
	citizens = 5;
	warriers = 1;
	armor = 1;
	money = 10;
	texture = sf::CircleShape(radius, 60);
	texture.setFillColor(sf::Color::Blue);
	texture.setPosition(position);
}

Tribe::~Tribe()
{
}

void Tribe::Draw(sf::RenderWindow& window)
{
	window.draw(texture);
}