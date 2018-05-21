#include "Hexagon.hpp"

Hexagon::Hexagon(sf::Vector2f center, float side, sf::Color color, sf::Color border) :
center(center),
color(color)
{
	border = border;
	this->setSide(side);
	this->setCenter(center);
	shape.setFillColor(color);
}

Hexagon::Hexagon(const Hexagon* other):
center(other->center),
color(other->color)
{
	border = other->getBorder();
	this->setSide(other->side);
	this->setCenter(center);
	shape.setFillColor(other->color);
}


Hexagon::~Hexagon()
{
}

void Hexagon::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(shape);
	target.draw(vertices);
}

sf::VertexArray Hexagon::getVertices(){
	return this->vertices;
}

sf::Color Hexagon::getColor() const{
	return color;
}

void Hexagon::setColor(sf::Color color){
	this->color = color;
}

sf::Color Hexagon::getBorder() const{
	return border;
}

void Hexagon::setBorder(sf::Color color){
	this->border = color;
}

void Hexagon::setCenter(sf::Vector2f cent){
	this->center = cent;
	vertices.clear();
	vertices.setPrimitiveType(sf::LineStrip);
	vertices.append(sf::Vertex(sf::Vector2f(center.x - side / 2, center.y - h), border));	// top-left vertex
	vertices.append(sf::Vertex(sf::Vector2f(center.x + side / 2, center.y - h), border));	// top-right vertex
	vertices.append(sf::Vertex(sf::Vector2f(center.x + side, center.y), border));			// right vertex
	vertices.append(sf::Vertex(sf::Vector2f(center.x + side / 2, center.y + h), border));	// bottom-right vertex
	vertices.append(sf::Vertex(sf::Vector2f(center.x - side / 2, center.y + h), border));	// bottom-left vertex
	vertices.append(sf::Vertex(sf::Vector2f(center.x - side, center.y), border));			// left vertex
	vertices.append(sf::Vertex(sf::Vector2f(center.x - side / 2, center.y - h), border));	// top-left vertex (again, to close the shape

	shape.setPointCount(6);
	shape.setPoint(0, vertices[0].position);
	shape.setPoint(1, vertices[1].position);
	shape.setPoint(2, vertices[2].position);
	shape.setPoint(3, vertices[3].position);
	shape.setPoint(4, vertices[4].position);
	shape.setPoint(5, vertices[5].position);
}
sf::Vector2f Hexagon::getCenter(){
	return this->center;
}
void Hexagon::setSide(float newSide){
	this->side = newSide;
	h = sqrt((3 * side*side) / 4);
	this->setCenter(center);
}
float Hexagon::getSide(){
	return this->side;
}