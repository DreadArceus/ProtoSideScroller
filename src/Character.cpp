#include "Character.hpp"
#include <iostream>

Character::Character(vector<sf::Sprite> v, double fpms)
{
	this->sheet = v;
	this->currentFrame = 0;
	this->FrameTime = 0;
	this->jumpState = 0;
	this->jumpHeight = 0;
	this->basePosition = {sheet[0].getPosition().x, sheet[0].getPosition().y};
	this->fpms = fpms;
}

sf::Sprite Character::animate()
{
	if(jumpHeight >= 150)
	{
		jumpState = -1;
	}
	if(jumpState != 0)
	{
		for(int i = 0; i < this->sheet.size(); i++)
		{
			sheet[i].setPosition(basePosition.first, basePosition.second - jumpHeight);
		}
		jumpHeight += jumpState*20;
		if(jumpHeight <= 0)
		{
			jumpState = 0;
		}
	}
	else
	{
		for(int i = 0; i < this->sheet.size(); i++)
		{
			sheet[i].setPosition(basePosition.first, basePosition.second);
		}
	}

	if(FrameTime == 0)
	{
		return sheet[0];
	}
	if(currentFrame == 12)
	{
		currentFrame = 0;
	}
	return sheet[currentFrame++];
}

void Character::jump()
{
	this->jumpHeight = 1;
	this->jumpState = 1;
}

bool Character::atBase()
{
	return ((sheet[0].getPosition().x == basePosition.first)
			&& (sheet[0].getPosition().y == basePosition.second));
}