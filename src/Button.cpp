//=============================================================================
#include "Button.h"
#include "Resources.h"
//=============================================================================
Button::Button(sf::Vector2f pos, sf::Vector2f size, std::string text,
				sf::Color idle, sf::Color hover, sf::Color clicked)
	:m_idle(idle), m_hover(hover), m_clicked(clicked), m_state(Idle)
{
	m_button.setSize(size);
	m_button.setOrigin(m_button.getGlobalBounds().width / 2.f, m_button.getGlobalBounds().height / 2.f);
	m_button.setPosition(pos);
	m_button.setFillColor(m_idle);


	m_text.setFont(Resources::instance().getFont(Fonts::Bold_F));
	m_text.setString(text);
	m_text.setFillColor(sf::Color::White);
	m_text.setCharacterSize(35);
	m_text.setOrigin(m_text.getGlobalBounds().width / 2, m_text.getGlobalBounds().height / 2);
	m_text.setPosition(pos);	

}
//=============================================================================
void Button::draw(sf::RenderWindow& window)
{
	window.draw(m_button);
	window.draw(m_text);
}
//=============================================================================
void Button::update(sf::Vector2f mousePos) //if theres a problem, maybe mouseWindow (not view)
{
	m_state = Idle;

	if (m_button.getGlobalBounds().contains(mousePos))
	{
		m_state = Hover;

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			m_state = clicked;
		}
	}
	switch (m_state)
	{
	case Idle:
		m_button.setFillColor(m_idle);
		break;
	case Hover:
		m_button.setFillColor(m_hover);
		break;
	case clicked:
		m_button.setFillColor(m_clicked);
		break;
	default:
		m_button.setFillColor(sf::Color::Black);
	}
}
//=============================================================================
bool Button::isClicked() const
{
	if (m_state == clicked)
		return true;

	return false;
}
//=============================================================================