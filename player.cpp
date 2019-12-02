#include "player.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
#include <stdlib.h>

player::player()
{
	paddle.setFillColor(sf::Color::White);
	paddle.setSize(sf::Vector2f(10.0f, 80.0f));
	paddle.setPosition(sf::Vector2f(30.0f, 260.0f));
}

void player::update(sf::RenderWindow& window)
{
	if (paddle.getPosition().y > 0)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
		{
			paddle.move(sf::Vector2f(0.0f, -0.25f));
		}
	}
	if (paddle.getPosition().y < 520)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
		{
			paddle.move(sf::Vector2f(0.0f, 0.25f));
		}
	}
	window.draw(paddle);
}

sf::Vector2f player::getPosition()
{
	return paddle.getPosition();
}