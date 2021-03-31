#pragma once
#ifndef _USE_MATH_DEFINES
	#define _USE_MATH_DEFINES
#endif
#include <math.h> 
#include <SFML/Graphics.hpp>
#include <inttypes.h>
#include "MyFunctions.h"
#include <cstdarg>
#include <chrono>
#include <iostream>


sf::Color get_random_color()
{
	int8_t color1 = (int8_t)(get_rand_double() * 255);
	int8_t color2 = (int8_t)(get_rand_double() * 255);
	int8_t color3 = (int8_t)(get_rand_double() * 255);
	return sf::Color(color1, color2, color3, 255u);
}

float get_rand_float()
{
	return (static_cast<float>(rand())) / RAND_MAX;
}

double get_rand_double()
{
	unsigned short int ic = std::chrono::system_clock::now().time_since_epoch().count();
	srand(ic);
	return (static_cast<double>(rand())) / RAND_MAX;
}


double get_rand_double(int value)
{
	return get_rand_double() * value;
}

double sigmoid(const double oldvalue)
{
	return 1 / (1 + pow(M_E, -1 * oldvalue));
}
