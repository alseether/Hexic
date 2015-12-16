#include "Hexagon.hpp"
#include <math.h>


Hexagon::Hexagon(sf::Vector2f center, float side, sf::Color color) :
center(center),
outter(center,side + EXTRA(side)),	// (side + side*0.2) is the outter circumference radius
color(color)
{
	this->side = side;
	h = sqrt((3*side*side)/4);	
	vertices.push_back(sf::Vertex(sf::Vector2f(center.x - side / 2, center.y - h)));	// top-left vertex
	vertices.push_back(sf::Vertex(sf::Vector2f(center.x + side / 2, center.y - h)));	// top-right vertex
	vertices.push_back(sf::Vertex(sf::Vector2f(center.x + side, center.y)));			// right vertex
	vertices.push_back(sf::Vertex(sf::Vector2f(center.x + side / 2, center.y + h)));	// bottom-right vertex
	vertices.push_back(sf::Vertex(sf::Vector2f(center.x - side / 2, center.y + h)));	// bottom-left vertex
	vertices.push_back(sf::Vertex(sf::Vector2f(center.x - side, center.y)));			// left vertex

	shape.setPointCount(6);
	shape.setPoint(0, vertices[0].position);
	shape.setPoint(1, vertices[1].position);
	shape.setPoint(2, vertices[2].position);
	shape.setPoint(3, vertices[3].position);
	shape.setPoint(4, vertices[4].position);
	shape.setPoint(5, vertices[5].position);
	shape.setFillColor(color);
}


Hexagon::~Hexagon()
{
}


bool Hexagon::isInOutterCircle(sf::Vector2i point)
{
	return outter.isInside(point);
}

void Hexagon::draw(sf::RenderTarget* target, std::vector<sf::Color> pattern)
{
	sf::VertexArray temp(sf::PrimitiveType::Lines);
	for (int i = 0; i < vertices.size(); ++i){
		temp.append(vertices[i]);
		temp.append(vertices[(i+1) % 6]);
	}
	bool noBorders = (pattern.size() == 0);
	for (int i = 0; i < temp.getVertexCount(); ++i){
		if (noBorders){
			temp[i].color = sf::Color::Black;
		}
		else{
			temp[i].color = pattern[(i / 2) % 6];
		}
	}
	shape.setFillColor(color);
	target->draw(shape);
	target->draw(temp);
	
	return;
}

std::vector<sf::Vertex> Hexagon::getVertices(){
	return this->vertices;
}

sf::Color Hexagon::getColor(){
	return color;
}

void Hexagon::setColor(sf::Color color){
	this->color = color;
}