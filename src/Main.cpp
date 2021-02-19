#include <iostream>
#include "Character.hpp"
using namespace std;

int main()
{
	sf::Texture tex, t[12];
	tex.loadFromFile("content/2DBG-Joined.png");
	for(int i = 0; i < 12; i++)
	{
		t[i].loadFromFile("content/CharacterSprites/" + to_string(i + 1) + ".png");
	}
	tex.setRepeated(1);

	sf::Sprite s;
	s.setTexture(tex);
	vector<sf::Sprite> sp(12);
	for(int i = 0; i < 12; i++)
	{
		sp[i].setTexture(t[i]);
		sp[i].setTextureRect(sf::IntRect(t[i].getSize().x/2, 0, t[i].getSize().x, t[i].getSize().y * 25/32));
		sp[i].setPosition(0, 300);
		sp[i].scale({0.3, 0.3});
	}

	Character c(sp, 0.0001);

	int x = 0;
	sf::RenderWindow rw(sf::VideoMode(1920, 1200), "2D Scroll");
	rw.setFramerateLimit(15);

	while(rw.isOpen())
	{
		sf::Event event;
		while(rw.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
			{
				rw.close();
			}
			if(event.type == sf::Event::KeyPressed)
			{
				if(event.key.code == sf::Keyboard::Space && c.atBase())
				{
					c.jump();
				}
			}
		}
		rw.clear(sf::Color::Black);

		s.setTextureRect(sf::IntRect(x, tex.getSize().y/3, tex.getSize().x, 3*tex.getSize().y/5));
		x += 7;
		rw.draw(s);

		if(time(0) >= c.getTime())
		{
			rw.draw(c.animate());
			c.updateTime(time(0));
		}
		else
		{
			rw.draw(c.oldFrame());
		}

		rw.display();
	}
}