#pragma once

#include <SFML/Graphics.hpp>

class Circumference
{
public:
	Circumference(sf::Vector2f center, float radius);
	~Circumference();
private:
	sf::Vector2f center;
	float radius;
public:
	bool isInside(sf::Vector2i point);

	void draw(sf::RenderTarget* target, sf::Color color);
};

