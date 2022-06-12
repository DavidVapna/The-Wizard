//=============================================================================
#include "Animation.h"
//=============================================================================
Animation::Animation(sf::Sprite& sprite,const sf::Texture& texture)
	:m_sprite(sprite), m_textureSheet(&texture)
{

}
//=============================================================================

//=============================================================================
void Animation::addAnimation(const std::string& key, float animTimer,
	const sf::Vector2i& frameStart, const sf::Vector2i& frames, sf::Vector2f size)
{
	m_animations[key] = std::make_unique<AnimationComp>(m_sprite, m_textureSheet, animTimer, frameStart, frames, size);
}
//=============================================================================
void Animation::play(const std::string& key, const float& deltaTime)
{
	m_animations[key]->play(deltaTime);
}
//=============================================================================