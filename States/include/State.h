//=============================================================================
#pragma once
//=============================================================================
#include "Button.h"
//=============================================================================
//=============================================================================
class State
{
	//public functions.
public:
	State(sf::RenderWindow* window,	std::stack<std::unique_ptr<State>>* m_states);
	virtual ~State();

	virtual void setBG() = 0;
	virtual void setWindow() = 0;
	virtual void draw() = 0;
	virtual void update(const float& deltaTime) = 0;
	virtual void updateInput(const float& deltaTime) = 0;
	virtual void setButtons() = 0;

	virtual bool isEnd() const;
	virtual void updateMouse();


	//protected functions.
protected:

protected:
	sf::RenderWindow* m_window;
	sf::Sprite m_backGround;
	bool m_end;
	bool m_pause;
	sf::Vector2i m_mouseScreen;
	sf::Vector2i m_mouseWindow;
	sf::Vector2f m_mouseView;

	std::unordered_map<int, std::unique_ptr<Button>> m_buttons;

	std::stack<std::unique_ptr<State>> *m_states;

private:
};
//=============================================================================