#include <SFML/Graphics.hpp>
#include "Tribe.h"
#include <chrono>
#include <iostream>

int widthWindow = 800;
int heightWindow = 600;
void Draw(sf::RenderWindow& window);

Tribe firstTribe;
int main()
{
	sf::RenderWindow window(sf::VideoMode(widthWindow, heightWindow), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		Draw(window);
	}

	return 0;
}

void Draw(sf::RenderWindow& window)
{
	window.clear();
	firstTribe.Draw(window);
	window.display();
}