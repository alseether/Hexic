#include "HexMatrix.hpp"

sf::Color getColorFromInt(int i){
	switch (i){
	case 1:
		return sf::Color(0xDC143CFF);
	case 2:
		return sf::Color(0x6495EDFF);
	case 3:
		return sf::Color(0x7FFF00FF);
	case 4:
		return sf::Color(0xFFD700FF);
	case 5:
		return sf::Color(0x8B008BFF);
	default:
		return sf::Color::Black;
	}
}


HexMatrix::HexMatrix(sf::Vector2f position, unsigned int width, unsigned int height, unsigned int side) :
position(position)
{
	this->width = width;
	this->height = height;
	this->side = side;
	h = sqrt((3 * side*side) / 4);
	nColors = initialColors;

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(1, nColors);

	sf::Color prevColor = sf::Color::Transparent;
	for (int i = 0; i < height; ++i){
		for (int j = 0; j < width; ++j){
			sf::Color color;
			sf::Vector2f center;			
			if (j % 2 == 0){
				center = sf::Vector2f(position.x + (1.5 * side*j), position.y + h + (i * 2 * h));
			}
			else{
				center = sf::Vector2f(position.x + (1.5*side*j), position.y + (i * 2 * h));
			}
			do{
				color = getColorFromInt(dis(gen));
			} while (color == prevColor);
			matrix.push_back(std::make_unique<Hexagon>(center, side, color));
			prevColor = color;
		}
	}
}

HexMatrix::~HexMatrix()
{
}

bool HexMatrix::checkCombos(){
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(1, nColors);
	bool changes = false;
	for (int i = 0; i < matrix.size() - width; ++i){
		if (matrix[i]->getColor() == matrix[i + 1]->getColor() && matrix[i]->getColor() == matrix[i + 10]->getColor()){
			matrix[i]->setColor(getColorFromInt(dis(gen)));
			changes = true;
		}
		else if (i != matrix.size() - width -1 && matrix[i]->getColor() == matrix[i + 10]->getColor() && matrix[i]->getColor() == matrix[i + 11]->getColor()){
			matrix[i]->setColor(getColorFromInt(dis(gen)));
			changes = true;
		}
	}
	return changes;
}


void HexMatrix::draw(sf::RenderTarget &target, sf::RenderStates states) const{
	for (int i = 0; i < matrix.size(); ++i){
		target.draw(*matrix[i]);
	}
}

/*
std::vector<int> HexMatrix::getSelectedHexagons(sf::Vector2i pointer){
	std::vector<int> ret;
	for (int i = 0; i < matrix.size(); ++i){
		if (matrix[i].isInOutterCircle(pointer)){
			ret.push_back(i);
		}
	}
	return ret;
}
*/
Hexagon HexMatrix::getHexagon(unsigned int i){
	return *matrix[i];
}

Hexagon HexMatrix::getHexagon(unsigned int row, unsigned int col){
	return *matrix[row * width + col];
}

void HexMatrix::turnLeft(std::vector<int> selected){
	if (selected[0] + 1 == selected[1]){
		sf::Color aux = matrix[selected[0]]->getColor();
		matrix[selected[0]]->setColor(matrix[selected[1]]->getColor());
		matrix[selected[1]]->setColor(matrix[selected[2]]->getColor());
		matrix[selected[2]]->setColor(aux);
	}
	else{
		sf::Color aux = matrix[selected[0]]->getColor();
		matrix[selected[0]]->setColor(matrix[selected[2]]->getColor());
		matrix[selected[2]]->setColor(matrix[selected[1]]->getColor());
		matrix[selected[1]]->setColor(aux);
	}
}
void HexMatrix::turnRight(std::vector<int> selected){
	if (selected[0] + 1 == selected[1]){
		sf::Color aux = matrix[selected[0]]->getColor();
		matrix[selected[0]]->setColor(matrix[selected[2]]->getColor());
		matrix[selected[2]]->setColor(matrix[selected[1]]->getColor());
		matrix[selected[1]]->setColor(aux);
	}
	else{
		sf::Color aux = matrix[selected[0]]->getColor();
		matrix[selected[0]]->setColor(matrix[selected[1]]->getColor());
		matrix[selected[1]]->setColor(matrix[selected[2]]->getColor());
		matrix[selected[2]]->setColor(aux);
	}
}

int HexMatrix::solveCombos(){
	bool changes;
	int punt = 0;
	do{
		changes = false;
		for (int i = 0; i < matrix.size() - width; ++i){
			if (i%width < width - 1 && matrix[i]->getColor() == matrix[i + 1]->getColor() && matrix[i]->getColor() == matrix[i + width +1]->getColor() && matrix[i]->getColor() != sf::Color::Transparent){
				// 3 Hex Group facing left combo
				matrix[i]->setColor(sf::Color::Transparent);
				matrix[i+1]->setColor(sf::Color::Transparent);
				matrix[i+ width + 1]->setColor(sf::Color::Transparent);
				punt += 30;
				changes = true;
			}
			else if (i != matrix.size() - width - 1 && matrix[i]->getColor() == matrix[i + 1]->getColor() && matrix[i]->getColor() == matrix[i + width]->getColor() && matrix[i]->getColor() != sf::Color::Transparent){
				// 3 Hex Group facing right combo
				matrix[i]->setColor(sf::Color::Transparent);
				matrix[i + 1]->setColor(sf::Color::Transparent);
				matrix[i + width]->setColor(sf::Color::Transparent);
				punt += 30;
				changes = true;
			}
			else if (i != matrix.size() - width - 1 && matrix[i]->getColor() == matrix[i + width]->getColor() && matrix[i]->getColor() == matrix[i + width + 1]->getColor() && matrix[i]->getColor() != sf::Color::Transparent){
				// 3 Hex Group facing right combo
				matrix[i]->setColor(sf::Color::Transparent);
				matrix[i + width]->setColor(sf::Color::Transparent);
				matrix[i + width + 1]->setColor(sf::Color::Transparent);
				punt += 30;
				changes = true;
			}
			else if (i != matrix.size() - width - 1 && matrix[i]->getColor() == matrix[i + width -1]->getColor() && matrix[i]->getColor() == matrix[i + width]->getColor() && matrix[i]->getColor() != sf::Color::Transparent){
				// 3 Hex Group facing right combo
				matrix[i]->setColor(sf::Color::Transparent);
				matrix[i + width -1]->setColor(sf::Color::Transparent);
				matrix[i + width]->setColor(sf::Color::Transparent);
				punt += 30;
				changes = true;
			}
		}
		//this->draw(target);
		for (int i = 0; i < width; ++i){
			for (int j = height - 1; j > 0; --j){
				if (matrix[j*width + i]->getColor() == sf::Color::Transparent){
					int k = j*width + i;
					do{
						k -= width;
					} while (k > width && matrix[k]->getColor() == sf::Color::Transparent);
					matrix[j*width + i]->setColor(matrix[k]->getColor());
					matrix[k]->setColor(sf::Color::Transparent);
				}
			}
		}
		//this->draw(target);
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<int> dis(1, initialColors);
		for (int i = 0; i < matrix.size(); ++i){
			if (matrix[i]->getColor() == sf::Color::Transparent){
				matrix[i]->setColor(getColorFromInt(dis(gen)));
			}
		}
		//this->draw(target);
	} while (changes);
	return punt;
}