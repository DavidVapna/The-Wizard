//=============================================================================
#include "Animation.h"
//=============================================================================
Animation::Animation(sf::Sprite& sprite)
	:m_sprite(sprite)
{
}
//=============================================================================
void Animation::addAnimation(const std::string& key, float animTimer, const AnimationInfo& animInfo, const sf::Vector2f& objSize)
{
	m_animations[key] = std::make_unique<AnimationComp>(m_sprite, animTimer, animInfo, objSize);
}
//=============================================================================
void Animation::play(const std::string& key, const float& deltaTime)
{
	m_animations[key]->play(deltaTime);
}
//=============================================================================