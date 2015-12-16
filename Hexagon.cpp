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


bool Hexagon::isInOutterCircle(sf::Vector2f point)
{
	return outter.isInside(point);
}

void Hexagon::draw(sf::RenderTarget* target, ColorPattern pattern)
{
	sf::VertexArray temp(sf::PrimitiveType::Lines);

	temp.append(this->vertices[0]);		// top border	(-)
	temp.append(this->vertices[1]);

	temp.append(this->vertices[1]);		// top-right border	(\)
	temp.append(this->vertices[2]);

	temp.append(this->vertices[2]);		// bottom-right border (/)
	temp.append(this->vertices[3]);

	temp.append(this->vertices[3]);		// bottom border (_)
	temp.append(this->vertices[4]);

	temp.append(this->vertices[4]);		// bottom-left border	(\)
	temp.append(this->vertices[5]);

	temp.append(this->vertices[5]);		// top-left border(/)
	temp.append(this->vertices[0]);

	for (int i = 0; i < temp.getVertexCount(); ++i){
		temp[i].color = pattern[i];
	}

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