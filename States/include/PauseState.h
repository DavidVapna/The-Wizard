//=============================================================================
#pragma once
//=============================================================================
#include "State.h"
//=============================================================================
class PauseState : public State
{
public:
	PauseState(sf::RenderWindow* window, std::stack<std::unique_ptr<State>>* states);
	virtual ~PauseState() = default; 
	virtual void setBG() override;
	virtual void setWindow() override;
	virtual void draw() override;
	virtual void update(const float& deltaTime) override;
	virtual void updateInput(const float& deltaTime) override;
	virtual void setButtons() override;

private:
	std::map<std::string, std::unique_ptr<Button>> m_buttons;
};
//=============================================================================