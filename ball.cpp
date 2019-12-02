#include "ball.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
#include <stdlib.h>

ball::ball()
{
	Ball.setFillColor(sf::Color::White);
	Ball.setSize(sf::Vector2f(10.0f, 10.0f));
	Ball.setPosition(sf::Vector2f(450.0f, 300.0f));
	dir = tragectory(rand() % 4);
}

sf::Vector2f ball::getPosition()
{
	return Ball.getPosition();
}

void ball::update(sf::RenderWindow &window, const bool ricochet)
{
	if (Ball.getPosition().x < 0 || Ball.getPosition().x > 900)
	{
		Ball.setPosition(sf::Vector2f(450.0f, 300.0f));
		dir = tragectory(rand() % 4);
	}
	if (Ball.getPosition().y < 0 || Ball.getPosition().y > 590)
	{
		switch (dir)
		{
		case upLeft:
			dir = downLeft;
			break;
		case upRight:
			dir = downRight;
			break;
		case downRight:
			dir = upRight;
			break;
		case downLeft:
			dir = upLeft;
			break;
		}
	}
	switch (dir)
	{
	case upLeft:
		Ball.move(sf::Vector2f(-0.3f, -0.3f));
		break;
	case upRight:
		Ball.move(sf::Vector2f(0.3f, -0.3f));
		break;
	case downRight:
		Ball.move(sf::Vector2f(0.3f, 0.3f));
		break;
	case downLeft:
		Ball.move(sf::Vector2f(-0.3f, 0.3f));
		break;
	}
	window.draw(Ball);
}

void ball::setDir(int Dir)
{
	dir = tragectory(Dir);
}

int ball::getDir()
{
	return int(dir);
}