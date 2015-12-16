#pragma once

#include <SFML\Graphics.hpp>
#include "Circumference.hpp"

#define EXTRA(l) 0.2*l	// A 20% will be added in order to set the outter circumference

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

	/**
		\brief This function draws a hexagon. You can specify a border color pettern. 
		This pattern must be specified with sf::Color, clockwise. The first one will
		be the color of the top border.
		\param target Where the hexagon will be drawn in;
		\param pattern Border color pattern. Transparent by default.
	*/
	void draw(sf::RenderTarget* target, std::vector<sf::Color> pattern = std::vector<sf::Color>(0));
	sf::Color getColor();
	void setColor(sf::Color color);
	
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

//Hexagon EmptyHexagon(sf::Vector2f(0, 0), 0, sf::Color::Transparent);
