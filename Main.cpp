#include "Hexagon.hpp"
#include "HexMatrix.hpp"
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
	for (int i = 0; i < sizeY+2; +=2i){
		for (int j = 0; j < sizeX+2; +=2j){
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
		for (int i = 0; i < 6; +=2i){
			for (int j = 0; j < 6; +=2j){
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
	for (int i = 0; i < 6; +=2i){
		for (int j = 0; j < 6; +=2j){
			for (int k = 0; k < 6; +=2k){
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
	std::vector<int> selected;

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

	HexMatrix mat(sf::Vector2f(100, 100));

	while (window.isOpen()){
		window.clear();
		sf::Event event;
		while (window.pollEvent(event)){
			switch (event.type){
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::MouseButtonPressed:
				if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					selected = mat.getSelectedHexagons(sf::Mouse::getPosition(window));
					if (selected.size() == 3)	mat.turnLeft(selected);
				}
				else if (sf::Mouse::isButtonPressed(sf::Mouse::Right)){
					selected = mat.getSelectedHexagons(sf::Mouse::getPosition(window));
					if (selected.size() == 3)	mat.turnRight(selected);
				}
				break;
			case sf::Event::MouseButtonReleased:
				mat.solveCombos();
				
				break;
			}
		}
		mat.draw(&window);
		selected = mat.getSelectedHexagons(sf::Mouse::getPosition(window));
		if (selected.size() == 3){
			if (selected[0] == selected[1] - 1){
				if (selected[0] + 10 == selected[2]){
					// 3 Hex Group facing right 
					mat.getHexagon(selected[0]).draw(&window, pattern3UpLeft);
					mat.getHexagon(selected[1]).draw(&window, pattern3Right);
					mat.getHexagon(selected[2]).draw(&window, pattern3DownLeft);
				}
				else{
					// 3 Hex Group facing left
					mat.getHexagon(selected[0]).draw(&window, pattern3Left);
					mat.getHexagon(selected[1]).draw(&window, pattern3UpRight);
					mat.getHexagon(selected[2]).draw(&window, pattern3DownRight);
				}
			}
			else{
				if (selected[0] + 10 == selected[1]){
					// 3 Hex Group facing right 
					mat.getHexagon(selected[0]).draw(&window, pattern3UpLeft);
					mat.getHexagon(selected[1]).draw(&window, pattern3DownLeft);
					mat.getHexagon(selected[2]).draw(&window, pattern3Right);
				}
				else{
					// 3 Hex Group facing left
					mat.getHexagon(selected[0]).draw(&window, pattern3UpRight);
					mat.getHexagon(selected[1]).draw(&window, pattern3Left);
					mat.getHexagon(selected[2]).draw(&window, pattern3DownRight);
				}
			}
		}
		window.display();
	}

		
	return 0;
}