#include "pch.h"
#include "PRS.h"

bool isSpriteHover(sf::FloatRect sprite, sf::Vector2f mp)
{
	if (sprite.contains(mp)) {
		return true;
	}
	return false;
}

template <class A, class B>
bool winner(A & a, B & b) {
	return a.beat(b);
}

int main()
{

	sf::RenderWindow window, window2, window3;
	window.create(sf::VideoMode(1000, 900), "Rock&Scissors&Paper");

	sf::Texture bg;
	if (!bg.loadFromFile("background.png"))
	{
		return 1;
	}
	sf::Sprite bgsprite;
	bgsprite.setTexture(bg);
	sf::Vector2f targetSize(1200, 900);

	bgsprite.setScale(
		targetSize.x / bgsprite.getLocalBounds().width,
		targetSize.y / bgsprite.getLocalBounds().height);

	rock p;
	scissors s;
	// для бота:
	p.sprite.setRotation(180);
	p.sprite.setScale(-1, 1);

	sf::Vector2f mp;
	mp.x = sf::Mouse::getPosition(window).x;
	mp.y = sf::Mouse::getPosition(window).y;

	//итог
	std::string g;
	if (winner(p, s)) {
		g = "You Win";
	}	
	else { g = "You Lose";
	}


	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			//isSpriteHover(p.sprite.getGlobalBounds(), sf::Vector2f(event.mouseButton.x, event.mouseButton.y)) == true
			if (p.beat(s))
			{
				if (event.type == sf::Event::MouseButtonReleased &&  event.mouseButton.button == sf::Mouse::Left)
				{
					window.create(sf::VideoMode(400, 200), "Result");
					while (window.isOpen())
					{
						sf::Event event;

						while (window.pollEvent(event))
						{
							if (event.type == sf::Event::Closed)
								window.close();

						}
					}
				}
			}

		}
		window.clear(sf::Color::Black);

		p.sprite.setPosition(sf::Vector2f(300, 430));
		s.sprite.setPosition(sf::Vector2f(300, 530));

		window.draw(bgsprite);

		//window.draw(p.sprite);
		//window.draw(s.sprite);

		window.display();

	}

	return 0;
}