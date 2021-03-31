#include <SFML/Graphics.hpp>
#include "Tribe.h"
#include <chrono>
#include <iostream>

int widthWindow = 800;
int heightWindow = 600;
void Draw(sf::RenderWindow& window);
void Update(sf::RenderWindow& window);

float TribeRadius = 40.f;

Tribe firstTribe(TribeRadius);
Tribe secondTribe(TribeRadius);
Tribe thirdTribe(TribeRadius);

sf::Vertex line[] =
{
	sf::Vertex(firstTribe.position + sf::Vector2f(firstTribe.radius, firstTribe.radius)),
	sf::Vertex(secondTribe.position + sf::Vector2f(secondTribe.radius, secondTribe.radius)),
	sf::Vertex(thirdTribe.position + sf::Vector2f(thirdTribe.radius, thirdTribe.radius)),
	sf::Vertex(firstTribe.position + sf::Vector2f(firstTribe.radius, firstTribe.radius))
};

int main()
{
	sf::RenderWindow window(sf::VideoMode(widthWindow, heightWindow), "SFML works!");
	while (window.isOpen())
	{
		Update(window);
		Draw(window);
	}

	return 0;
}




void Update(sf::RenderWindow& window)
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
	}
}

void Draw(sf::RenderWindow& window)
{
	window.clear();
	window.draw(line, 4, sf::LinesStrip);
	firstTribe.Draw(window);
	secondTribe.Draw(window);
	thirdTribe.Draw(window);
	window.display();
}