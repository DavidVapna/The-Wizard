//=============================================================================
#pragma once
//=============================================================================
#include "Macros.h"
//=============================================================================
class AnimationComp
{
public:
    AnimationComp(sf::Sprite& sprite, float animTimer, const AnimationInfo& animInfo, const sf::Vector2f& objSize)
        :m_sprite(sprite), m_animTimer(animTimer),
        m_timer(0.f), m_size(animInfo.frameSize), m_done(false)
    {
            
        m_startRect = sf::IntRect(animInfo.frameStart.x * m_size.x, animInfo.frameStart.y * m_size.y, m_size.x, m_size.y);
        m_currentRect = m_startRect;
        m_endRect = sf::IntRect(animInfo.frames.x * m_size.x, animInfo.frames.y * m_size.y, m_size.x, m_size.y);

        m_sprite.setTextureRect(m_startRect);
        m_sprite.setScale(objSize.x / m_sprite.getTextureRect().width, objSize.y / m_sprite.getTextureRect().height);
        //m_sprite.setScale(objSize.x / m_sprite.getGlobalBounds().width, objSize.y / m_sprite.getGlobalBounds().height);
        m_sprite.setOrigin(m_sprite.getTextureRect().width / 2.f, m_sprite.getTextureRect().height / 2.f);
    }

    void play(const float& deltaTime)
    {
        return;
        m_done = false;
        m_timer += 100.f * deltaTime;
        if (m_timer >= m_animTimer)
        {
            m_timer = 0.f;

            if (m_currentRect != m_endRect)
                m_currentRect.left += m_size.x;
            else
            {
                m_currentRect.left = m_startRect.left;
                m_done = true;
            }
            m_sprite.setTextureRect(m_currentRect);
        }
    }
    void reset()
    {
        m_timer = 0.f;
        m_currentRect = m_startRect;
    }
    ~AnimationComp() = default;

public:
    sf::Sprite& m_sprite;
    float m_animTimer;
    float m_timer;
    sf::IntRect m_startRect;
    sf::IntRect m_currentRect;
    sf::IntRect m_endRect;
    sf::Vector2f m_size;
    bool m_done;
};
//=============================================================================
class Animation
{
public:
    Animation(sf::Sprite& sprite);
    ~Animation() = default;

    //functions
    void addAnimation(const std::string& key, float animTimer, const AnimationInfo& animInfo, const sf::Vector2f& objSize);
    void play(const std::string& key, const float& deltaTime);

private:
    std::map<std::string, std::unique_ptr<AnimationComp>> m_animations;
    sf::Sprite& m_sprite;
};
//=============================================================================