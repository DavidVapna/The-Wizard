//=============================================================================
#include "State.h"
//=============================================================================
State::State(sf::RenderWindow* window, std::stack<std::unique_ptr<State>>* states)
	:m_end(false),m_pause(false),m_window(window), m_states(states)
{
}
//=============================================================================
State::~State()
{

}
//=============================================================================
bool State::isEnd() const
{
	return m_end;
}
//=============================================================================
void State::updateMouse()
{
	m_mouseScreen = sf::Mouse::getPosition();
	m_mouseWindow = sf::Mouse::getPosition(*m_window);
	m_mouseView = m_window->mapPixelToCoords(m_mouseWindow);

}
//=============================================================================