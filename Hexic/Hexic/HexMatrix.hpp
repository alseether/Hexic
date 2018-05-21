#pragma once
#include <SFML\Graphics.hpp>
#include "Hexagon.hpp"
#include <random>

class HexMatrix
{
public:
	HexMatrix(sf::Vector2f position, unsigned int width = 10, unsigned int height = 8, unsigned int side = 50);
	~HexMatrix();

private:
	const int initialColors = 5; // Red, Blue, Green, Yellow, Magenta
	sf::Vector2f position;
	unsigned int width;
	unsigned int height;
	unsigned int side;
	float h;
	std::vector<Hexagon> matrix;

	bool checkCombos(int colors);

public:

	void draw(sf::RenderTarget* target);
	std::vector<int> getSelectedHexagons(sf::Vector2i pointer);
	Hexagon getHexagon(unsigned int i);
	Hexagon getHexagon(unsigned int row, unsigned int col);

	void turnLeft(std::vector<int> selected);
	void turnRight(std::vector<int> selected);

	int solveCombos(sf::RenderTarget* target);
};

