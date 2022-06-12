//=============================================================================
#include "AnimationComponent.h"
//=============================================================================
AnimationComponent::AnimationComponent(sf::Sprite& sprite,const sf::Texture& texture)
	:m_sprite(sprite), m_textureSheet(&texture)
{

}
//=============================================================================

//=============================================================================
void AnimationComponent::addAnimation(const std::string& key, float animTimer,
	const sf::Vector2i& frameStart, const sf::Vector2i& frames, sf::Vector2f size)
{
	m_animations[key] = std::make_unique<Animation>(m_sprite, m_textureSheet, animTimer, frameStart, frames, size);
}
//=============================================================================
void AnimationComponent::play(const std::string& key, const float& deltaTime)
{
	m_animations[key]->play(deltaTime);
}
//=============================================================================