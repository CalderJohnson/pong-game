#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
#include <stdlib.h>

class ball
{
public:
	ball();
	void update(sf::RenderWindow& window, const bool ricochet = false);
	sf::Vector2f getPosition();
	void setDir(int Dir);
	int getDir();
private:
	enum tragectory
	{
		upLeft,
		upRight,
		downRight,
		downLeft
	};
	sf::RectangleShape Ball;
	tragectory dir;
};