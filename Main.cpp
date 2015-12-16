#include "Hexagon.hpp"
#include "SFML\Graphics.hpp"
#include <iostream>

#define OFFSET 50
#define SIZEX 8
#define SIZEY 6
#define SIDE 50

/*
std::vector<Hexagon> generateHexMatrix(unsigned int sizeX, unsigned int sizeY, unsigned int side){
	std::vector<Hexagon> hexTileMap;
	float h = sqrt((3 * side*side) / 4);
	for (int i = 0; i < sizeY+2; ++i){
		for (int j = 0; j < sizeX+2; ++j){
			sf::Vector2f center;
			if (j % 2 == 0){
				center = sf::Vector2f(OFFSET + (1.5*side*j), OFFSET + (i * 2 * h));
				hexTileMap.push_back(Hexagon(center, side));
			}
			else{
				center = sf::Vector2f(OFFSET + (1.5 * side*j), OFFSET + h + (i * 2 * h));
				hexTileMap.push_back(Hexagon(center, side));
			}
		}
	}
	return hexTileMap;
}

bool isDrawableHexagon(std::vector<Hexagon>* hexTileMap, int sizeX, int sizeY, int i){
	if (i >= sizeX + 2 && i <= (hexTileMap->size() - (sizeX + 2))){
		if ((i % (sizeX + 2) != 0) && (i % (sizeX + 2) != (sizeX + 1))){
			return true;
		}
	}
	return false;
}

void drawSelectedHexagon(sf::RenderTarget* target, std::vector<Hexagon>* hexTileMap, int sizeX, int sizeY, int i, bool debug){
	if (isDrawableHexagon(hexTileMap, sizeX, sizeY, i)){
		hexTileMap->at(i).draw(target, sf::Color::Yellow, debug);
	}
}

void drawLineBetween(sf::RenderTarget* target, std::vector<Hexagon>* hexTileMap, int sizeX, int sizeY, int i, int j){
	sf::VertexArray line(sf::PrimitiveType::Lines, 2);
	std::vector<sf::Vertex> verticesA;
	std::vector<sf::Vertex> verticesB;
	bool draw = false;
	if (isDrawableHexagon(hexTileMap, sizeX, sizeY,i)){
		draw = true;
	}
	if (isDrawableHexagon(hexTileMap, sizeX, sizeY, j)){
		draw = true;
	}
	if (draw){
		verticesA = hexTileMap->at(i).getVertices();
		verticesB = hexTileMap->at(j).getVertices();
		line.clear();
		for (int i = 0; i < 6; ++i){
			for (int j = 0; j < 6; ++j){
				if (int(verticesA[i].position.x) == int(verticesB[j].position.x) && int(verticesA[i].position.y) == int(verticesB[j].position.y)){
					verticesA[i].color = sf::Color::Yellow;
					line.append(verticesA[i]);
					j = 6;
				}
			}
		}
		target->draw(line);
	}
}

void drawPointBetween(sf::RenderTarget* target, std::vector<Hexagon>* hexTileMap, int sizeX, int sizeY, int i, int j, int k){
	sf::CircleShape dot(4);
	std::vector<sf::Vertex> verticesA;
	std::vector<sf::Vertex> verticesB;
	std::vector<sf::Vertex> verticesC;
	verticesA = hexTileMap->at(i).getVertices();
	verticesB = hexTileMap->at(j).getVertices();
	verticesC = hexTileMap->at(k).getVertices();
	for (int i = 0; i < 6; ++i){
		for (int j = 0; j < 6; ++j){
			for (int k = 0; k < 6; ++k){
				if (int(verticesA[i].position.x) == int(verticesB[j].position.x) && int(verticesA[i].position.y) == int(verticesB[j].position.y)){
					if (int(verticesA[i].position.x) == int(verticesC[k].position.x) && int(verticesA[i].position.y) == int(verticesC[k].position.y)){
						sf::Vector2f pos(verticesA[i].position.x - 4, verticesA[i].position.y - 4);
						dot.setPosition(pos);
						dot.setFillColor(sf::Color::Yellow);
						k = 6;
						j = 6;
						i = 6;
					}
				}
			}
		}
	}
	target->draw(dot);
}
*/
int main(){
	sf::VideoMode videoMode = sf::VideoMode::getFullscreenModes().at(2);
	sf::RenderWindow window(videoMode, "Hexic");
	std::vector<sf::Color> pat;
	pat.push_back(sf::Color::Yellow);
	pat.push_back(sf::Color::Blue);
	pat.push_back(sf::Color::Magenta);
	pat.push_back(sf::Color::Cyan);
	pat.push_back(sf::Color::Green);
	pat.push_back(sf::Color::White);
	Hexagon h(sf::Vector2f(videoMode.width/2,videoMode.height/2), 250.f, sf::Color::Red);
	while (window.isOpen()){
		sf::Event event;
		while (window.pollEvent(event)){
			switch (event.type){
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::MouseButtonPressed:
				while(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					
				}
				break;
			case sf::Event::MouseButtonReleased:
				sf::Vector2i pointer = sf::Mouse::getPosition(window);
				
				break;
			}
		}
		
		window.clear();
		h.draw(&window, pat);
		window.display();
	}

		
	return 0;
}