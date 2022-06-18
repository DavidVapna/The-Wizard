//============================================================================
#pragma once
//============================================================================
#include "StaticObject.h"
class Dorothy;
//============================================================================
class NPC : public StaticObject
{
public:

	NPC(b2World* world, int bodyT, const sf::Vector2f& pos, bool rotation, const sf::Vector2f& size, int gameObj);
	virtual ~NPC() = default;
	void update(const float& deltaTime);
	void chat();
	bool inChat() const;
	void drawText(sf::RenderWindow& window);
	void isClicked(sf::RenderWindow& window);


protected:
	sf::Sprite m_textBG;
	sf::Text m_text;
	bool m_inChat = false;
	std::vector<std::string > m_lines;
	int m_currLine = 0;
	int m_chatTimer = 0;

private:
};
//============================================================================
//