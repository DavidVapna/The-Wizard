//=============================================================================
#include "PauseState.h"
#include "Resources.h"
//=============================================================================
PauseState::PauseState(sf::RenderWindow* window, std::stack<std::unique_ptr<State>>* states)
	:State(window, states)
{
	setBG();
	setButtons();
}
//=============================================================================
void PauseState::setBG()
{
	m_backGround.setTexture(
		Resources::instance().getTexture(int(Textures::PauseBG)));
	sf::Vector2f bgScale = sf::Vector2f(static_cast<float>(m_window->getSize().x),
							static_cast<float>(m_window->getSize().y));
	m_backGround.setScale(bgScale);
}
//=============================================================================
void PauseState::setButtons()
{
	return;
}
//=============================================================================
void PauseState::setWindow()
{

}
//=============================================================================
void PauseState::draw()
{
	m_window->draw(m_backGround);

	for (auto& button : m_buttons)
	{
		button.second->draw(*m_window);
	}
}
//=============================================================================
void PauseState::update(const float& deltaTime)
{
	return;
}
//=============================================================================
void PauseState::updateInput(const float& deltaTime)
{
	return;
}
//=============================================================================

//=============================================================================