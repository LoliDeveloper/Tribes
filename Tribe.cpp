#include "Tribe.h"
#include "MyFunctions.h"
extern int widthWindow;
extern int heightWindow;

float radius = 50.f;
Tribe::Tribe()
{
	citizens = 5;
	warriers = 1;
	armor = 1;
	money = 10;
	texture = sf::CircleShape(radius);
	texture.setFillColor(sf::Color::Blue);
	texture.setPosition((widthWindow - 2 * radius)* get_rand_double(), (heightWindow - 2 * radius) * get_rand_double());
}

Tribe::~Tribe()
{
}

void Tribe::Draw(sf::RenderWindow& window)
{
	texture.setPosition((widthWindow - 2 * radius)* get_rand_double(), (heightWindow - 2 * radius) * get_rand_double());
	window.draw(texture);
}