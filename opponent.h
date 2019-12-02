#pragma once
#include "ball.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
#include <stdlib.h>

class opponent
{
public:
	opponent();
	void update(sf::RenderWindow& window, ball& Ball);
	sf::Vector2f getPosition();
private:
	sf::RectangleShape paddle;
};

