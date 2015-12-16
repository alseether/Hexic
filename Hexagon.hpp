#pragma once

#include <SFML\Graphics.hpp>
#include "Circumference.hpp"

#define EXTRA(l) 0.2*l	// A 20% will be added in order to set the outter circumference

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

class Hexagon
{
public:
	Hexagon(sf::Vector2f center, float side, sf::Color color);
	~Hexagon();

	static sf::Texture hexagonTexture;

private:
	sf::Vector2f center;
	float h;
	float side;
	std::vector<sf::Vertex> vertices;
	Circumference outter;
	sf::ConvexShape shape;
	sf::Color color;
public:
	std::vector<sf::Vertex> getVertices();
	bool isInOutterCircle(sf::Vector2f point);
	void draw(sf::RenderTarget* target, ColorPattern pattern);
	sf::Color getColor();
	
	bool operator==(const Hexagon* other){
		if (center == other->center){
			if (side == other->side){
				if (color == other->color){
					return true;
				}
			}
		}
		return false;
	}
};

Hexagon EmptyHexagon(sf::Vector2f(0, 0), 0, sf::Color::Transparent);
