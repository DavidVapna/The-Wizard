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
void PauseState::setButtons()
{
	//auto temp = std::make_unique<Button>
	//	(CONTINUE_BUTTON, BUTTONS_SIZE, CONTINUE_TEXT, sf::Color::Red, sf::Color::Yellow, sf::Color::Green);

	//this->m_buttons.emplace((int)PauseButtons::Continue, temp.release());
}
//=============================================================================
void PauseState::setBG()
{
	m_backGround.setTexture(Resources::instance().getTexture((int)Textures::PauseBG));
	auto size = m_backGround.getTexture()->getSize();
	m_backGround.scale(sf::Vector2f(m_window->getSize().x / size.x, m_window->getSize().y / size.y));
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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
	{
		this->m_end = true;
		return;
	}
}
//=============================================================================
void PauseState::updateInput(const float& deltaTime)
{
	return;
}

//=============================================================================