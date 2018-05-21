#pragma once
#include <SFML\Graphics.hpp>
#include "Hexagon.hpp"
#include "State.hpp"
#include <random>
#include <memory>

class HexMatrix: public sf::Drawable
{
public:
	HexMatrix(sf::Vector2f position, State::Context context, unsigned int width = 10, unsigned int height = 8, unsigned int side = 10);
	~HexMatrix();

private:
	const int initialColors = 3; 
	int nColors;
	sf::Vector2f position;
	unsigned int width;
	unsigned int height;
	unsigned int side;
	float h;
	std::vector<std::unique_ptr<Hexagon>> matrix;

private:
	bool checkCombos();


public:

	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	Hexagon getHexagon(unsigned int i);
	Hexagon getHexagon(unsigned int row, unsigned int col);

	void turnLeft(std::vector<int> selected);
	void turnRight(std::vector<int> selected);

	int solveCombos();
};

