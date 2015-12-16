#include "Cursor.hpp"


Cursor::Cursor(unsigned int sizeX, unsigned int sizeY)
{
	this->sizeX = sizeX;
	this->sizeY = sizeY;
	posX = 0;
	posY = 0;
	if (sizeY <= 2){
		sizeY = 2;
		maxY = 0;
	}
	else{
		maxY = sizeY * 2 - 3;	// Number of vertical steps
	}
	if (sizeX <= 2){
		sizeX = 2;
		maxX = 0;
	}
	else{
		maxX = sizeX * 2 - 3;	// Number of horizontal steps
	}
}


Cursor::~Cursor()
{
}


std::vector<sf::Vector2i>* Cursor::getGroup()
{
	return &this->group;
}

int whoIsHigher(std::vector<sf::Vector2i> group){
	sf::Vector2i a = group.at(0);
	sf::Vector2i b = group.at(1);
	sf::Vector2i c = group.at(2);
	if (a.x < b.x){	// if a is on the left side of the group (and alone on left)
		if (b.y < c.y){	// if b is higher than c
			return 1;	// b is the higher one
		}
		else{
			return 2;	// c is the higher one
		}
	}
	else if (a.x == b.x){	// if a and b are both on the same side
		return (a.y < b.y) ? 0 : 1;
	}
	else{	// a is alone on the right side
		return (b.y < c.y) ? 1 : 2;
	}
}

void Cursor::moveLeft(){
	if (posX > 0){

		posX--;
	}
}
void Cursor::moveRight(){
	if (posX < maxX){

		posX++;
	}
}
void Cursor::moveUp(){
	if (posY > 0){

		posY--;
	}
}
void Cursor::moveDown(){
	if (posY < maxY){
		int higher = whoIsHigher(group);
		
		posY++;
	}
}