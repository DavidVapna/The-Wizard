
//============================================================================
#include "NPC.h"
//============================================================================

//============================================================================
NPC::NPC(b2World* world, int bodyT, const sf::Vector2f& pos,
	bool rotation, const sf::Vector2f& size, int gameObj)
	:StaticObject(world, bodyT, pos, rotation, size, gameObj),
	m_text("", Resources::instance().getFont(Fonts::Italic_F), 10),
	m_chatTimer(0)
{



	m_textBG.setOrigin(m_textBG.getGlobalBounds().width / 2.f, m_textBG.getGlobalBounds().height / 2.f);
	m_text.setOrigin(m_text.getGlobalBounds().width / 2, m_text.getGlobalBounds().height / 2);
	m_text.setFillColor(sf::Color::Black);
	m_textBG.setFillColor(sf::Color::White);
	m_text.setCharacterSize(13);
	m_textBG.setPosition(sf::Vector2f(pos.x, pos.y - 100));



}
//============================================================================
bool NPC::isClickedOn()
{
	return false;
}
//============================================================================
void NPC::update(const float& deltaTime)
{
	StaticObject::update(deltaTime);
	m_chatTimer--;
	if (m_inChat && sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && m_chatTimer <= 0)
	{
		m_chatTimer = 15;
		++m_currLine;
		m_text.setString(m_lines[m_currLine]);

		if (m_inChat && m_currLine == m_lines.size() - 1)
			m_inChat = false;	
	}
}
//============================================================================
void NPC::chat()
{
	if(!m_inChat)
	{
		std::string s1("Welcome Dorothy to\nthe land of OZ!\n");
		std::string s2("your house has\n lended on the wicked\nwitch of the north\n");
		std::string s3("thus, angring her sister\nthe wicked witch\nof the west, Elphaba\n");
		std::string s4("quickly! you have to find\nand wear the red heels\nof the witch you just killed\n");
		std::string s5("they will protect you!\n");
		std::string s6("when you find\nthem continue down\nthe roat and find me,\n");
		std::string s7("i have a very\nimportant mission\nto give you!");
		m_lines.push_back(s1); m_lines.push_back(s2); m_lines.push_back(s3);
		m_lines.push_back(s4); m_lines.push_back(s5); m_lines.push_back(s6);
		m_lines.push_back(s7);
		m_inChat = true;
		m_text.setString(m_lines[m_currLine]);
		m_text.setPosition(m_sprite.getPosition().x, m_sprite.getPosition().y - 50);
		m_chatTimer = 20;
	}
}
//============================================================================
bool NPC::inChat() const
{
	return m_inChat;
}
//============================================================================
void NPC::drawText(sf::RenderWindow& window)
{
	m_textBG.setSize(sf::Vector2f(m_text.getGlobalBounds().width, m_text.getGlobalBounds().height));
	m_text.setPosition(m_textBG.getPosition());
	window.draw(m_textBG);
	window.draw(m_text);
}
//============================================================================