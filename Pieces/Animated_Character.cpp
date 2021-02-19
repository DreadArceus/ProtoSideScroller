#include <iostream>
using namespace std;
class Character
{
public:
	Character(vector<sf::Sprite> v, double fpms);
	sf::Sprite animate();
	sf::Sprite oldFrame() {return sheet[currentFrame];};
	double getTime() {return FrameTime + fpms/1000;}
	void updateTime(double t) {FrameTime = t;};
private:
	vector<sf::Sprite> sheet;
	int currentFrame;
	double FrameTime;
	double fpms;
};
Character::Character(vector<sf::Sprite> v, double fpms)
{
	this->sheet = v;
	this->currentFrame = 0;
	this->FrameTime = 0;
	this->fpms = fpms;
}
sf::Sprite Character::animate()
{
	if(FrameTime == 0)
	{
		return sheet[0];
	}
	if(currentFrame == 12)
	{
		currentFrame = 0;;
	}
	return sheet[currentFrame++];
}
int main()
{
	sf::Texture tex[12];
	for(int i = 0; i < 12; i++)
	{
		tex[i].loadFromFile("content/CharacterSprites/" + to_string(i + 1) + ".png");
	}
	vector<sf::Sprite> sp(12);
	for(int i = 0; i < 12; i++)
	{
		sp[i].setTexture(tex[i]);
	}
	Character a(sp, 0.00001);
	sf::RenderWindow rw(sf::VideoMode(1280, 720), "Character Animation");
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
		}
		rw.clear(sf::Color::Black);
		if(time(0) >= a.getTime())
		{
			rw.draw(a.animate());
			a.updateTime(time(0));
		}
		else
		{
			rw.draw(a.oldFrame());
		}

		rw.display();
	}
}