#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include <SFML\Graphics.hpp>
#include "State.hpp"
#include "Rand.hpp"
#include "HexMatrix.hpp"

class GameState : public State{
public:
	GameState(StateStack& stack, Context context);

	virtual bool update(sf::Time dt);

	virtual void draw();

	virtual bool handleEvent(const sf::Event &e);

private:
	HexMatrix hex;
};

#endif