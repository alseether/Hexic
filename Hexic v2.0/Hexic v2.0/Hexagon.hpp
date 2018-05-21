#pragma once

#include <SFML\Graphics.hpp>

class Hexagon : public sf::Drawable
{
public:
	Hexagon(sf::Vector2f center, float side, sf::Color color = sf::Color::White, sf::Color border = sf::Color::Black);
	Hexagon(const Hexagon* other);
	~Hexagon();

	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

private:
	float h;
	sf::VertexArray vertices;
	sf::ConvexShape shape;
	sf::Color color;
	sf::Color border;
	sf::Vector2f center;
	float side;
public:
	void setCenter(sf::Vector2f cent);
	sf::Vector2f getCenter();
	void setSide(float newSide);
	float getSide();

	/**
		  0   1
		  -----
		5/     \2
		 \     /
		  -----
		  4   3
	*/
	sf::VertexArray getVertices();

	sf::Color getColor() const;
	void setColor(sf::Color color);

	sf::Color getBorder() const;
	void setBorder(sf::Color color);
	
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
