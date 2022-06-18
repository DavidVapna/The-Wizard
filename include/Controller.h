//=============================================================================
#pragma once
//=============================================================================
#include "MenuState.h"
//=============================================================================
class Controller
{
public:
	Controller();
	~Controller();
	void run();
	
private:
	std::unique_ptr<State> initMenu();
	void loadWithFile(sf::VideoMode& windSize, std::string& windName, unsigned& frameLim);
	void update();
	void display();
	void handleEvents();
	void closeGame();

private:
	std::stack<std::unique_ptr<State>> m_states;
	GameStates m_currMod;
	std::unique_ptr<sf::RenderWindow> m_window;
};
//=============================================================================