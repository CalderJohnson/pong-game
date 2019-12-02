#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
#include <stdlib.h>

class player
{
public:
	player();
	void update(sf::RenderWindow& window);
	sf::Vector2f getPosition();
private:
	sf::RectangleShape paddle;
};

