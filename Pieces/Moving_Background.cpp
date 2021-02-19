#include <iostream>
using namespace std;

int main()
{
	sf::RenderWindow rw(sf::VideoMode(1920, 1200), "2D Scroll");
	rw.setFramerateLimit(15);
	sf::Texture tex;
	tex.loadFromFile("content/2DBG-Joined.png");
	tex.setRepeated(1);

	sf::Sprite s1;
	s1.setTexture(tex);

	int x = 0;
	while(rw.isOpen())
	{
		sf::Event event;
		while(rw.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
			{
				rw.close();
			}
		}
		rw.clear(sf::Color::Black);

		s1.setTextureRect(sf::IntRect(x, tex.getSize().y/3, tex.getSize().x, 3*tex.getSize().y/5));
		x += 7;
		rw.draw(s1);

		rw.display();
	}
}