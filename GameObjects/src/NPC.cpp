
//============================================================================
#include "NPC.h"
//============================================================================

//============================================================================
NPC::NPC(b2World* world, int bodyT, const sf::Vector2f& pos,
	bool rotation, const sf::Vector2f& size, int gameObj)
	:StaticObject(world, bodyT, pos, rotation, size, gameObj),
	text("something something", Resources::instance().getFont(Fonts::Empty_F), 30)
{
	setAnimation(size, gameObj);
}
//============================================================================
void NPC::setAnimation(const sf::Vector2f& size, int theObject)
{
	auto& texture = Resources::instance().getTexture(theObject);
	m_animation = std::make_unique<Animation>(m_sprite, texture);
	auto start = sf::Vector2i{ 0,0 };

	auto animSpeed = 100.f;

	auto AnimStartIdle = sf::Vector2i(0, 0);/*starting row and col*/
	auto AnimInRowIdle = sf::Vector2i(0, 4);/*(images per row, current row*/

	m_animation->addAnimation("IDLE", animSpeed, AnimStartIdle, AnimInRowIdle, LION_ANIM);

	m_sprite.setScale(size.x / m_sprite.getTextureRect().width, size.y / m_sprite.getTextureRect().height);
	m_sprite.setOrigin(m_sprite.getTextureRect().width / 2.f, m_sprite.getTextureRect().height / 2.f);
}
//============================================================================
void NPC::update(const float& deltaTime)
{
	StaticObject::update(deltaTime);
	m_animation->play("IDLE", deltaTime);
}
//============================================================================
void NPC::chat(Dorothy* dorothy)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		m_sprite.setTexture(Resources::instance().getTexture((int)Textures::Mouse));
	}
}
//============================================================================