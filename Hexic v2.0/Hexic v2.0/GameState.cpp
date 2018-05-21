#include "GameState.hpp"
#include "PauseState.hpp"
#include "MenuState.hpp"
#include "ResourceHolder.hpp"

GameState::GameState(StateStack& stack, Context context) :
State(stack,context),
hex(sf::Vector2f(20,20), context, 10,8,20)
{
}

bool GameState::update(sf::Time dt) {

	return true;
}


void GameState::draw(){
	sf::RenderWindow& window = *getContext().window;
	window.setView(window.getDefaultView());
	window.draw(hex);
}

bool GameState::handleEvent(const sf::Event &e){
	if (e.type == sf::Event::KeyReleased){
		if (e.key.code == sf::Keyboard::Escape){
			auto pauseState = std::make_shared<PauseState>(*_stack, _context);
			requestStackPush(pauseState);
		}
		else if (e.key.code == sf::Keyboard::M){
			requestStateClear();
			auto menuState = std::make_shared<MenuState>(*_stack, _context);
			requestStackPush(menuState);
		}
	}
	return false;
}
