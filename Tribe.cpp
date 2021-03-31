#include "Tribe.h"
#include "MyFunctions.h"
extern int widthWindow;
extern int heightWindow;
extern sf::Font font;
extern int fontSize;

std::vector<sf::Vector2f> Tribe::positionsArray;
int Tribe::count = 0;

Tribe::Tribe(const int radius_):
	radius(radius_),
	position(CalculateNewTribePosition(radius_))
{
	setSomeText(count);
	++count;
	initDataPosVector(position);
	citizens = 5;
	warriers = 1;
	armor = 1;
	money = 10;
	texture = sf::CircleShape(radius, 60);
	texture.setFillColor(get_random_color());
	texture.setPosition(position);
}

Tribe::~Tribe()
{
}

void Tribe::Draw(sf::RenderWindow& window)
{
	window.draw(texture);
	window.draw(text);
}

sf::Vector2f Tribe::CalculateNewTribePosition(const int radius_)
{
	sf::Vector2f maxPosition (widthWindow - 2 * radius_, heightWindow - 2 * radius_);
	if (positionsArray.size() == 0) { 
		return sf::Vector2f((maxPosition.x)* get_rand_float(), (maxPosition.y) * get_rand_float());
	}
	else if (positionsArray.size() == 1)
	{
		if (positionsArray[0].x < maxPosition.x / 2.f && positionsArray[0].y < maxPosition.y / 2.f)
		{
			float randTmp = get_rand_float();
			return sf::Vector2f((maxPosition.x - positionsArray[0].x) * randTmp, (maxPosition.y - positionsArray[0].y) * (1.f - randTmp)) + positionsArray[0] / 2.f;
		}
		else
			return positionsArray[0] / 2.f;
	}
	else if (positionsArray.size() == 2)
	{
		sf::Vector2f tmpVec(widthWindow, 0);
		for (int i = 0; i < positionsArray.size(); ++i)
		{
			tmpVec += positionsArray[i];
		}
		return tmpVec / ((float)positionsArray.size() + 1.f);
	}
	else {
		sf::Vector2f tmpVec(0, 0);
		for (int i = 0; i < positionsArray.size(); ++i)
		{
			tmpVec += positionsArray[i];
		}
		return tmpVec / ((float)positionsArray.size()+1.f);
	}
}

void Tribe::initDataPosVector(const sf::Vector2f& position)
{
	Tribe::positionsArray.push_back(position);
}

void Tribe::setSomeText(const int value)
{
	text.setFont(font); // font is a sf::Font
	text.setString(static_cast<char>('0'+value));
	text.setCharacterSize(fontSize); // in pixels, not points!
	text.setFillColor(sf::Color::Red);

	// set the text style
	text.setPosition(position + sf::Vector2f(radius - fontSize / 3, radius - fontSize/2));
}