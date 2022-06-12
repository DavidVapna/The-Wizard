//=============================================================================
#pragma once
//=============================================================================
#include "Macros.h"
//=============================================================================
class Animation
{
public:

    Animation(sf::Sprite& sprite, const sf::Texture* texture ,float animTimer,
        const sf::Vector2i& frameStart, const sf::Vector2i& frames, sf::Vector2f size)
        :m_sprite(sprite), m_textureSheet(texture), m_animTimer(animTimer),
        m_timer(0.f), m_size(size), m_done(false)
    {
        m_startRect = sf::IntRect(frameStart.x * size.x, frameStart.y * size.y, size.x, size.y);
        m_currentRect = m_startRect;
        m_endRect = sf::IntRect(frames.x * size.x, frames.y * size.y, size.x, size.y);

        m_sprite.setTexture(*m_textureSheet, true);
        m_sprite.setTextureRect(m_startRect);
    }

    //functions
    void play(const float& deltaTime)
    {
        m_done = false;
        m_timer += 100.f * deltaTime;
        if (m_timer >= m_animTimer)
        {
            m_timer = 0.f;

            if (m_currentRect != m_endRect)
            {
                m_currentRect.left += m_size.x;
            }
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

    ~Animation() = default;

public:
    //members
    sf::Sprite& m_sprite;
    const sf::Texture* m_textureSheet;
    float m_animTimer;
    float m_timer;
    sf::IntRect m_startRect;
    sf::IntRect m_currentRect;
    sf::IntRect m_endRect;
    sf::Vector2f m_size;
    bool m_done;
};

//=============================================================================
class AnimationComponent
{
public:
    AnimationComponent(sf::Sprite& sprite, const sf::Texture& texture);
    ~AnimationComponent() = default;

    //functions
    void addAnimation(const std::string& key, float animTimer,
        const sf::Vector2i& frameStart, const sf::Vector2i& frames, sf::Vector2f size);
    void play(const std::string& key, const float& deltaTime);

private:
    
    std::map<std::string, std::unique_ptr<Animation>> m_animations;
    sf::Sprite& m_sprite;
    const sf::Texture* m_textureSheet;
};
//=============================================================================