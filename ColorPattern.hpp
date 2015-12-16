#pragma once

#include <vector>
#include "SFML\Graphics.hpp"

enum Edge{
	TOP,
	TOP_RIGHT,
	BOTTOM_RIGHT,
	BOTTOM,
	BOTTOM_LEFT,
	TOP_LEFT
};

class ColorPattern{
public:
	ColorPattern(std::vector<sf::Color> pattern) :
		pattern(pattern)
	{

	}
	~ColorPattern();

	sf::Color getEdgeColor(Edge edge){
		return pattern[edge];
	}

	void setEdgeColor(Edge edge, sf::Color color){
		pattern[edge] = color;
	}

	sf::Color operator[](int i){
		return pattern[i];
	}

private:
	std::vector<sf::Color> pattern;
};