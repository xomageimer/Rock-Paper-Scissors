#include "pch.h"
#include "PRS.h"
#include <locale>

bool isSpriteHover(sf::FloatRect sprite, sf::Vector2f mp)
{
	if (sprite.contains(mp)) {
		return true;
	}
	return false;
}

template <class A, class B>
int winner(A & a, B & b) {
	return a.beat(b);
}

int main()
{

	std::locale::global(std::locale(""));

	sf::RenderWindow window, window2, window3, window4;
	window3.create(sf::VideoMode(1000, 900), "Rock&Scissors&Paper", sf::Style::Close);
	

	sf::Texture bgmenu;
	if (!bgmenu.loadFromFile("photo.png"))
	{
		return 1;
	}
	sf::Sprite bgmenusprite;
	bgmenusprite.setTexture(bgmenu);

	sf::Texture bgstart;
	if (!bgstart.loadFromFile("Start.png"))
	{
		return 1;
	}
	sf::Sprite bgstartsprite;
	bgstartsprite.setTexture(bgstart);

	sf::Texture bgrules;
	if (!bgrules.loadFromFile("Rules.png"))
	{
		return 1;
	}
	sf::Sprite bgrulessprite;
	bgrulessprite.setTexture(bgrules);
	

	/////////////////////////

	sf::Texture butpap;
	if (!butpap.loadFromFile("paperbtn.png"))
	{
		return 1;
	}
	sf::Sprite butpapsprite;
	butpapsprite.setTexture(butpap);
	sf::Texture butr;
	if (!butr.loadFromFile("rockbtn.png"))
	{
		return 1;
	}
	sf::Sprite butrsprite;
	butrsprite.setTexture(butr);
	sf::Texture butsc;
	if (!butsc.loadFromFile("scissorsbtn.png"))
	{
		return 1;
	}
	sf::Sprite butscsprite;
	butscsprite.setTexture(butsc);

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

	bgmenusprite.setScale(
		1000 / bgmenusprite.getLocalBounds().width,
		900 / bgmenusprite.getLocalBounds().height);

	rock p;
	scissors s;
	paper r;

	// для бота:

	rock bp;
	scissors bs;
	paper br;

	bp.sprite.setRotation(180);
	bp.sprite.setScale(-1, 1);
	bs.sprite.setRotation(180);
	bs.sprite.setScale(-1, 1);
	br.sprite.setRotation(180);
	br.sprite.setScale(-1, 1);


	sf::Vector2f mp;
	mp.x = sf::Mouse::getPosition(window).x;
	mp.y = sf::Mouse::getPosition(window).y;

	std::string g;
	int j = 0;
	int k = 0;
	int flag = -1;
	float timer = 0.f;
	sf::Clock clock;

	while (window3.isOpen()) {
		sf::Event event;

		while (window3.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window3.close();

			if (isSpriteHover(bgrulessprite.getGlobalBounds(), sf::Vector2f(event.mouseButton.x, event.mouseButton.y)) == true)
			{
				if (event.type == sf::Event::MouseButtonReleased &&  event.mouseButton.button == sf::Mouse::Left)
				{
					window3.setVisible(false);
					
					window4.create(sf::VideoMode(1200, 200), "Rules", sf::Style::Close);
					while (window4.isOpen()) {
						sf::Event event;

						while (window4.pollEvent(event))
						{
							if (event.type == sf::Event::Closed)
							{
								window4.close();
								window3.setVisible(true);
							}
						}
						window4.clear(sf::Color::Black);
						//window4.draw(bgmenusprite);
						sf::Font font;
						font.loadFromFile("Arial.ttf");
						sf::Text text;
						text.setFont(font);
						text.setString("Победитель определяется по следующим правилам:\nбумага побеждает камень (\"бумага накрывает камень\" или \"камень тонет, бумага нет\").\nКамень побеждает ножницы (\"камень затупляет или ломает ножницы\").\nНожницы побеждают бмагу (\"ножницы разрезают бумагу\").\nЕсли игроки показали одинаковый знак, то засчвитывается ничя и игра переигрывается");
						text.setPosition(1, 30);
						text.setFillColor(sf::Color::White);
						text.setCharacterSize(24);
						text.setStyle(sf::Text::Bold);
						window4.draw(text);
						window4.display();
					}
				}
			}

			if (isSpriteHover(bgstartsprite.getGlobalBounds(), sf::Vector2f(event.mouseButton.x, event.mouseButton.y)) == true)
			{
				if (event.type == sf::Event::MouseButtonReleased &&  event.mouseButton.button == sf::Mouse::Left)
				{
					window3.close();
					clock.restart();
					window.create(sf::VideoMode(1000, 900), "Rock&Scissors&Paper", sf::Style::Close);
					while (window.isOpen())
					{
						sf::Event event;

						while (window.pollEvent(event))
						{
							if (event.type == sf::Event::Closed)
								window.close();
							//isSpriteHover(p.sprite.getGlobalBounds(), sf::Vector2f(event.mouseButton.x, event.mouseButton.y)) == true
							//event.type == sf::Event::MouseButtonReleased &&  event.mouseButton.button == sf::Mouse::Left


							if (isSpriteHover(butpapsprite.getGlobalBounds(), sf::Vector2f(event.mouseButton.x, event.mouseButton.y)) == true)
							{
								if (event.type == sf::Event::MouseButtonReleased &&  event.mouseButton.button == sf::Mouse::Left)
								{
									k = 1 + rand() % 3;
									j = 1;
								}
							}
							if (isSpriteHover(butrsprite.getGlobalBounds(), sf::Vector2f(event.mouseButton.x, event.mouseButton.y)) == true)
							{
								if (event.type == sf::Event::MouseButtonReleased &&  event.mouseButton.button == sf::Mouse::Left)
								{
									k = 1 + rand() % 3;
									j = 2;
								}
							}
							if (isSpriteHover(butscsprite.getGlobalBounds(), sf::Vector2f(event.mouseButton.x, event.mouseButton.y)) == true)
							{
								if (event.type == sf::Event::MouseButtonReleased &&  event.mouseButton.button == sf::Mouse::Left)
								{
									k = 1 + rand() % 3;
									j = 3;
								}
							}

						}
						window.clear(sf::Color::Black);

						

						/*p.sprite.setPosition(sf::Vector2f(300, 430));
						s.sprite.setPosition(sf::Vector2f(300, 530));*/
					
						timer = timer / 800;
						timer += clock.getElapsedTime().asSeconds();
						if (timer > 5) j = 4;


						srand(time(0));

						window.draw(bgsprite);

						// конечный автомат D:
						if (j == 0) {
							butpapsprite.setPosition(sf::Vector2f(50, 340));
							window.draw(butpapsprite);

							butrsprite.setPosition(sf::Vector2f(400, 340));
							window.draw(butrsprite);

							butscsprite.setPosition(sf::Vector2f(750, 340));
							window.draw(butscsprite);
						}

						

						if (j == 1) {
							r.sprite.setPosition(sf::Vector2f(300, 530));
							window.draw(r.sprite);
						}
						if (j == 2) {
							p.sprite.setPosition(sf::Vector2f(300, 530));
							window.draw(p.sprite);
						}
						if (j == 3) {
							s.sprite.setPosition(sf::Vector2f(300, 530));
							window.draw(s.sprite);
						}

						if (k == 1) {
							br.sprite.setPosition(sf::Vector2f(300, 430));
							window.draw(br.sprite);
							if (j == 1) flag = winner(r, br);
							if (j == 2) flag = winner(p, br);
							if (j == 3) flag = winner(s, br);
						}
						if (k == 2) {
							bp.sprite.setPosition(sf::Vector2f(300, 430));
							window.draw(bp.sprite);
							if (j == 1) flag = winner(r, bp);
							if (j == 2) flag = winner(p, bp);
							if (j == 3) flag = winner(s, bp);
						}
						if (k == 3) {
							bs.sprite.setPosition(sf::Vector2f(300, 430));
							window.draw(bs.sprite);
							if (j == 1) flag = winner(r, bs);
							if (j == 2) flag = winner(p, bs);
							if (j == 3) flag = winner(s, bs);

						}


						window.display();

						if (j != 0)
						{
							int size = 60;
							std::this_thread::sleep_for(std::chrono::seconds(2));
							//window.setVisible(false);
							if (flag == 1) {
								g = "You Win";
							}
							else if (flag == 0) {
								g = "You Lose";
							}
							else if (flag == 2) {
								g = "Draw";
							}
							else {
								g = "you lose,\n because nothing choose";
								size = 24;
							}


							window2.create(sf::VideoMode(400, 200), "Result", sf::Style::Close);
							sf::Font font;
							font.loadFromFile("Arial.ttf");
							sf::Text text;
							text.setFont(font);
							text.setString(g);
							text.setPosition(70, 30);
							text.setFillColor(sf::Color::White);
							text.setCharacterSize(size);
							text.setStyle(sf::Text::Bold | sf::Text::Underlined);
							window2.draw(text);
							window2.display();

							std::this_thread::sleep_for(std::chrono::seconds(2));
							j = 0;
							k = 0;
							flag = -1;
							timer = clock.getElapsedTime().asSeconds();
							clock.restart();
							window2.close();


						}

					}
				}
			}

		}
		window3.clear(sf::Color::Black);
		window3.draw(bgmenusprite);

		bgstartsprite.setPosition(sf::Vector2f(350, 30));
		window3.draw(bgstartsprite);

		bgrulessprite.setPosition(sf::Vector2f(650, 750));
		window3.draw(bgrulessprite);

		window3.display();
	}

	return 0;
}