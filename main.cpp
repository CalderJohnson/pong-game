#include "ball.h"
#include "opponent.h"
#include "player.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
#include <stdlib.h>

int score1 = 0, score2 = 0;

void detectCollision(ball& Ball, opponent& Opponent, player& Player)
{
	if (Ball.getPosition().x > 869.0f && Ball.getPosition().x < 880.0f)
	{
		if (Ball.getPosition().y + 10 > Opponent.getPosition().y
			&& Ball.getPosition().y < Opponent.getPosition().y + 80)
		{
			switch (Ball.getDir())
			{
			case 1:
				Ball.setDir(0);
				break;
			case 2:
				Ball.setDir(3);
				break;
			}
		}
	}
	else if (Ball.getPosition().x < 31.0f && Ball.getPosition().x > 20.0f)
	{
		if (Ball.getPosition().y + 10 > Player.getPosition().y
			&& Ball.getPosition().y < Player.getPosition().y + 80)
		{
			switch (Ball.getDir())
			{
			case 0:
				Ball.setDir(1);
				break;
			case 3:
				Ball.setDir(2);
				break;
			}
		}
	}
	if (Ball.getPosition().x < 0.0f)
	{
		++score2;
		std::cout << "The enemy scored! Score is: " << score1 << ":" << score2 << std::endl;
	}
	else if (Ball.getPosition().x > 900.0f)
	{
		++score1;
		std::cout << "You scored! Score is: " << score1 << ":" << score2 << std::endl;
	}
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(900, 600), "PONG", sf::Style::Titlebar | sf::Style::Close);
	sf::Event event;
	srand(time(0));

	ball Ball;
	opponent Opponent;
	player Player;

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
			}
		}
		detectCollision(Ball, Opponent, Player);
		Ball.update(window);
		Opponent.update(window, Ball);
		Player.update(window);

		window.display();
		window.clear(sf::Color::Black);
	}
	return 0;
}