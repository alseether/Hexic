#pragma once

#include <SFML\Graphics.hpp>
#include "State.hpp"
#include "Utils.hpp"

class Hexagon : public sf::Drawable
{
public:
	Hexagon(sf::Vector2f center, float side, State::Context context, sf::Color color = sf::Color::White, sf::Color border = sf::Color::Black);
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

	sf::Text text;

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

	std::string getText() const;
	void setText(std::string text);
	
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
