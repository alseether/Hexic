#pragma once

#include <SFML\Graphics.hpp>
#include "Hexagon.hpp"

/* Patterns for 3 Hexagons groups */
const std::vector<sf::Color> pattern3UpLeft = { sf::Color::White, sf::Color::White, sf::Color::Black, sf::Color::Black, sf::Color::White, sf::Color::White };
const std::vector<sf::Color> pattern3UpRight = { sf::Color::White, sf::Color::White, sf::Color::White, sf::Color::Black, sf::Color::Black, sf::Color::White };
const std::vector<sf::Color> pattern3DownLeft = { sf::Color::Black, sf::Color::Black, sf::Color::White, sf::Color::White, sf::Color::White, sf::Color::White };
const std::vector<sf::Color> pattern3DownRight = { sf::Color::Black, sf::Color::White, sf::Color::White, sf::Color::White, sf::Color::White, sf::Color::Black };
const std::vector<sf::Color> pattern3Left = { sf::Color::White, sf::Color::Black, sf::Color::Black, sf::Color::White, sf::Color::White, sf::Color::White };
const std::vector<sf::Color> pattern3Right = { sf::Color::White, sf::Color::White, sf::Color::White, sf::Color::White, sf::Color::Black, sf::Color::Black };

/* Patterns for 7 Hexagon groups (star selection)*/
const std::vector<sf::Color> pattern6Up = { sf::Color::White, sf::Color::White, sf::Color::Black, sf::Color::Black, sf::Color::Black, sf::Color::White };
const std::vector<sf::Color> pattern6UpRight = { sf::Color::White, sf::Color::White, sf::Color::White, sf::Color::Black, sf::Color::Black, sf::Color::Black };
const std::vector<sf::Color> pattern6DownRight = { sf::Color::Black, sf::Color::White, sf::Color::White, sf::Color::White, sf::Color::Black, sf::Color::Black };
const std::vector<sf::Color> pattern6Down = { sf::Color::Black, sf::Color::Black, sf::Color::White, sf::Color::White, sf::Color::White, sf::Color::Black };
const std::vector<sf::Color> pattern6DownLeft = { sf::Color::Black, sf::Color::Black, sf::Color::Black, sf::Color::White, sf::Color::White, sf::Color::White };
const std::vector<sf::Color> pattern6UpLeft = { sf::Color::White, sf::Color::Black, sf::Color::Black, sf::Color::Black, sf::Color::White, sf::Color::White };

class Cursor
{
public:
	Cursor();
	~Cursor();
private:
	

public:
	void highlightGroup(sf::RenderTarget* target, std::vector<int> selected, std::vector<Hexagon> group);
};

