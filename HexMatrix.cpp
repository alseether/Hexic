#include "HexMatrix.hpp"


HexMatrix::HexMatrix(unsigned int sizeX, unsigned int sizeY, unsigned int side)
{
	std::random_device rd;
	gen = std::mt19937(rd());
	dis = std::uniform_int_distribution<>(0, 7);

	this->sizeX = sizeX;
	this->sizeY = sizeY;
	h = sqrt((3 * side*side) / 4);
	generateMatrix();
}


HexMatrix::~HexMatrix()
{
}

void HexMatrix::generateMatrix(){
	for (int i = 0; i < sizeY; ++i){
		for (int j = 0; j < sizeX; ++j){
			sf::Vector2f center;
			if (j % 2 == 0){
				center = sf::Vector2f((1.5*side*j), (i * 2 * h));
				hexMap.push_back(Hexagon(center, side, randomColor()));
			}
			else{
				center = sf::Vector2f((1.5 * side*j), h + (i * 2 * h));
				hexMap.push_back(Hexagon(center, side, randomColor()));
			}
		}
	}
	while (checkCombos() != 0){
		refillMatrix();
	}
	return;
}

int HexMatrix::checkCombos(){
	sf::Vector2f tmpCursor(0, 0);


}

void HexMatrix::refillMatrix(){
	for (int i = 0; i < sizeY; ++i){
		for (int j = 0; j < sizeX; ++j){
			if (hexMap[i*sizeX + j] == &EmptyHexagon){
				sf::Vector2f center;
				center = sf::Vector2f((1.5*side*j), (i * 2 * h));
				hexMap[i*sizeX + j] = Hexagon(center, side, randomColor());
			}
		}
	}
}

sf::Color HexMatrix::randomColor(){
	int rnd = dis(gen);
	switch (rnd){
	case 0:
		return sf::Color::Black;
	case 1:
		return sf::Color::Blue;
	case 2:
		return sf::Color::Cyan;
	case 3:
		return sf::Color::Green;
	case 4:
		return sf::Color::Magenta;
	case 5:
		return sf::Color::Red;
	case 6:
		return sf::Color::White;
	case 7:
		return sf::Color::Yellow;
	}
}


Hexagon HexMatrix::getHexagon(int x, int y)
{
	return hexMap[y*sizeX + x];
}


void HexMatrix::setCursor(sf::Vector2i cursor)
{
}

void HexMatrix::draw(sf::RenderTarget* target)
{
}

void HexMatrix::rotateRight(){

}
void HexMatrix::rotateLeft(){

}
