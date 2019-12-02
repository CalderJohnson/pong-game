#include "opponent.h"
#include "ball.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
#include <stdlib.h>

opponent::opponent()
{
	paddle.setFillColor(sf::Color::White);
	paddle.setSize(sf::Vector2f(10.0f, 80.0f));
	paddle.setPosition(sf::Vector2f(870.0f, 260.0f));
}

void opponent::update(sf::RenderWindow& window, ball &Ball)
{
	if (Ball.getPosition().x > 400)
	{
		if (Ball.getPosition().y > paddle.getPosition().y + 40)
			paddle.move(sf::Vector2f(0.0f, 0.25f));
		else
			paddle.move(sf::Vector2f(0.0f, -0.25f));
	}
	window.draw(paddle);
}

sf::Vector2f opponent::getPosition()
{
	return paddle.getPosition();
}