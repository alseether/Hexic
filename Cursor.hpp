#pragma once

#include "SFML\Graphics.hpp"

class Cursor
{
public:
	Cursor(unsigned int sizeX, unsigned int sizeY);
	~Cursor();
private:
	std::vector<sf::Vector2i> group;
	unsigned int sizeX;
	unsigned int sizeY;
	unsigned int posX;
	unsigned int posY;
	unsigned int maxX;
	unsigned int maxY;
public:
	std::vector<sf::Vector2i>* getGroup();
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
};

