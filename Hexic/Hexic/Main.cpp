#include "Hexagon.hpp"
#include "HexMatrix.hpp"
#include <SFML\Graphics.hpp>
#include "Cursor.hpp"
#include <iostream>

#define OFFSET 50
#define SIZEX 8
#define SIZEY 6
#define SIDE 50

int main(){
	sf::VideoMode videoMode = sf::VideoMode(800,600);
	sf::RenderWindow window(videoMode, "Hexic");
	Cursor cursor;
	std::vector<int> selected;
	std::vector<Hexagon> group;

	int puntuation = 0;
	int lastPunt;
	int retries = 0;

	HexMatrix mat(sf::Vector2f(100, 100));

	while (window.isOpen()){
		window.clear();
		group.clear();
		sf::Event event;
		while (window.pollEvent(event)){
			switch (event.type){
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::MouseButtonPressed:
				retries = 0;
				do{
					retries++;
					lastPunt = puntuation;
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
						selected = mat.getSelectedHexagons(sf::Mouse::getPosition(window));
						if (selected.size() == 3)	mat.turnLeft(selected);
					}
					else if (sf::Mouse::isButtonPressed(sf::Mouse::Right)){
						selected = mat.getSelectedHexagons(sf::Mouse::getPosition(window));
						if (selected.size() == 3)	mat.turnRight(selected);
					}

					puntuation += mat.solveCombos(&window);
				} while ((puntuation - lastPunt) == 0 && retries < 3);
				break;
			case sf::Event::MouseButtonReleased:
				
				
				break;
			}
		}
		mat.draw(&window);
		selected = mat.getSelectedHexagons(sf::Mouse::getPosition(window));
		for (int i = 0; i < selected.size(); ++i){
			group.push_back(Hexagon(mat.getHexagon(selected[i])));
		}
		cursor.highlightGroup(&window, selected, group);
		window.display();
	}

	return 0;
}