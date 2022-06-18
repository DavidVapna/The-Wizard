//=============================================================================
#pragma once
//=============================================================================
#include "PauseState.h"
#include "contactListener.h"
#include "GameBoard.h"
//=============================================================================
class GameState : public State
{
public:
	GameState(sf::RenderWindow* window, std::stack<std::unique_ptr<State>>* states);
	virtual ~GameState();
	virtual void setBG() override;
	virtual void setWindow() override;
	virtual void draw() override;
	virtual void update(const float& deltaTime) override;
	void updateInput(const float& deltaTime)override;
	virtual void setButtons() override;
	void debugMouse();
	void setBoundries();
	void updateView();

private:
	b2World m_world;
	GameBoard m_gameBoard;
	ContactListener m_contactListener;
	sf::View m_view;
	float m_deltaTime;
	sf::Clock m_gameClock;
	sf::Text m_debugMouse;
};
//=============================================================================





