#pragma once

#include <vector>
using namespace std;

class Character
{
public:
	Character(vector<sf::Sprite> v, double fpms);
	sf::Sprite animate();
	sf::Sprite oldFrame() {return sheet[currentFrame];};
	double getTime() {return FrameTime + fpms/1000;}
	void updateTime(double t) {FrameTime = t;};
	void jump();
	bool atBase();
private:
	vector<sf::Sprite> sheet;
	int currentFrame;
	int jumpState;
	int jumpHeight;
	pair<int, int> basePosition;
	double FrameTime;
	double fpms;
};