#include "Cursor.hpp"


Cursor::Cursor()
{
}


Cursor::~Cursor()
{
}


void Cursor::highlightGroup(sf::RenderTarget* target, std::vector<int> selected, std::vector<Hexagon> group){
	if (selected.size() == 3){
		float h = sqrt((3 * group[0].getSide()*group[0].getSide()) / 4);
		float newSide = group[0].getSide() * 1.1;
		float newH = sqrt((3 * newSide*newSide) / 4);
		float diff = newH - h;
		for (int i = 0; i < group.size(); ++i){
			group[i].setSide(newSide);
		}
		
		if (selected[0] == selected[1] - 1){
			if (selected[0] + 10 == selected[2]){
				// 3 Hex Group facing right 
				sf::Vector2f movUpLeft;
				sf::Vector2f movDownLeft;
				sf::Vector2f movRight;
				movUpLeft.x = group[0].getCenter().x - 3;
				movDownLeft.x = group[2].getCenter().x - 3;
				movRight.x = group[1].getCenter().x + 3;
				movUpLeft.y = group[0].getCenter().y - diff;
				movDownLeft.y = group[2].getCenter().y + diff;
				movRight.y = group[1].getCenter().y;
				group[0].setCenter(movUpLeft);
				group[1].setCenter(movRight);
				group[2].setCenter(movDownLeft);
				group[0].draw(target, pattern3UpLeft);
				group[1].draw(target, pattern3Right);
				group[2].draw(target, pattern3DownLeft);
			}
			else{
				// 3 Hex Group facing left
				sf::Vector2f movLeft;
				sf::Vector2f movUpRight;
				sf::Vector2f movDownRight;
				movLeft.x = group[0].getCenter().x - 3;
				movUpRight.x = group[1].getCenter().x + 3;
				movDownRight.x = group[2].getCenter().x + 3;
				movLeft.y = group[0].getCenter().y;
				movUpRight.y = group[1].getCenter().y - diff;
				movDownRight.y = group[2].getCenter().y + diff;
				group[0].setCenter(movLeft);
				group[1].setCenter(movUpRight);
				group[2].setCenter(movDownRight);
				group[0].draw(target, pattern3Left);
				group[1].draw(target, pattern3UpRight);
				group[2].draw(target, pattern3DownRight);
			}
		}
		else{
			if (selected[0] + 10 == selected[1]){
				// 3 Hex Group facing right
				sf::Vector2f movUpLeft;
				sf::Vector2f movDownLeft;
				sf::Vector2f movRight;
				movUpLeft.x = group[0].getCenter().x - 3;
				movDownLeft.x = group[1].getCenter().x - 3;
				movRight.x = group[2].getCenter().x + 3;
				movUpLeft.y = group[0].getCenter().y - diff;
				movDownLeft.y = group[1].getCenter().y + diff;
				movRight.y = group[2].getCenter().y;
				group[0].setCenter(movUpLeft);
				group[1].setCenter(movDownLeft);
				group[2].setCenter(movRight);
				group[0].draw(target, pattern3UpLeft);
				group[1].draw(target, pattern3DownLeft);
				group[2].draw(target, pattern3Right);
			}
			else{
				// 3 Hex Group facing left
				sf::Vector2f movLeft;
				sf::Vector2f movUpRight;
				sf::Vector2f movDownRight;
				movLeft.x = group[1].getCenter().x - 3;
				movUpRight.x = group[0].getCenter().x + 3;
				movDownRight.x = group[2].getCenter().x + 3;
				movLeft.y = group[1].getCenter().y;
				movUpRight.y = group[0].getCenter().y - diff;
				movDownRight.y = group[2].getCenter().y + diff;
				group[0].setCenter(movUpRight);
				group[1].setCenter(movLeft);
				group[2].setCenter(movDownRight);
				group[0].draw(target, pattern3UpRight);
				group[1].draw(target, pattern3Left);
				group[2].draw(target, pattern3DownRight);
			}
		}
	}
	else{

	}
}