#pragma once

#include "Hexagon.hpp"
#include "SFML\Graphics.hpp"
#include <random>

class HexMatrix
{
public:
	HexMatrix(unsigned int sizeX, unsigned int sizeY, unsigned side);
	~HexMatrix();
private:
	unsigned int sizeX;
	unsigned int sizeY;
	unsigned int side;
	float h;
public:
	Hexagon getHexagon(int x, int y);
private:
	sf::Vector2i cursor;
	std::vector<Hexagon> hexMap;

	void generateMatrix();
	int checkCombos();
	void refillMatrix();
	sf::Color randomColor();

	std::mt19937 gen;
	std::uniform_int_distribution<> dis;
public:
	void setCursor(sf::Vector2i cursor);
	void draw(sf::RenderTarget* target);
	void rotateRight();
	void rotateLeft();

};

