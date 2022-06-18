//============================================================================
#include "Resources.h"
//============================================================================
Resources::Resources()
	:m_textures((int)Textures::MaxTextures), m_fonts((int)Fonts::MaxFonts),
	m_sounds((int)Sounds::MaxSounds), m_music()
{
	setTextures();
	setAnimationInfo();
	setFonts();
	setSounds();

	m_music.setVolume(MUSIC_VOLUME);
	m_sound.setVolume(EFFECTS_VOLUME);
}
//============================================================================
const sf::Texture& Resources::getTexture(int wantedTexture) const
{
	auto it = m_textures.find(wantedTexture);
	if (it != m_textures.end())
		return it->second;
	throw std::out_of_range("Texture not found.");
}
//============================================================================
const AnimationInfo& Resources::getAnimInfo(int wantedInfo) const
{
	auto it = m_animInfo.find(wantedInfo);
	if (it != m_animInfo.end())
		return it->second;
	throw std::out_of_range("Animation Info not found");
}
//============================================================================
//sets all textures  of textures map
void Resources::setTextures() 
{
	m_textures[(int)Textures::MenuBG		] = loadSfObj<sf::Texture>("MenuBG.png");
	m_textures[(int)Textures::GameBG0		] = loadSfObj<sf::Texture>("GameState1.png");
	m_textures[(int)Textures::MenuButtons	] = loadSfObj<sf::Texture>("MenuButtons.png");
 	m_textures[(int)Textures::Buttons	    ] = loadSfObj<sf::Texture>("Buttons.png");
	m_textures[(int)Textures::CowardlyLion	] = loadSfObj<sf::Texture>("CowardlyLion.png");
	m_textures[(int)Textures::Dorothy		] = loadSfObj<sf::Texture>("Dorothy.png");
	m_textures[(int)Textures::Block			] = loadSfObj<sf::Texture>("Block.png");
	m_textures[(int)Textures::RedHeels	    ] = loadSfObj<sf::Texture>("RedHeels.png");
	m_textures[(int)Textures::RandomEnemy	] = loadSfObj<sf::Texture>("RandomEnemy.png");
	m_textures[(int)Textures::Glinda		] = loadSfObj<sf::Texture>("Glinda.png");
	m_textures[(int)Textures::PauseBG		] = loadSfObj<sf::Texture>("PauseBG.png");
	m_textures[(int)Textures::ChatBG		] = loadSfObj<sf::Texture>("ChatBG.jpg");
	m_textures[(int)Textures::Portal		] = loadSfObj<sf::Texture>("Portal.png");
	m_textures[(int)Textures::GameBG1		] = loadSfObj<sf::Texture>("GameState2.png");
}
//============================================================================
void Resources::setAnimationInfo()
{

	m_animInfo[(int)Animations::DOROTHY_WALK_R] = AnimationInfo(sf::Vector2i(0, 0), sf::Vector2i(7, 0), sf::Vector2f(37.5f, 60));
	m_animInfo[(int)Animations::DOROTHY_JUMP_R] = AnimationInfo(sf::Vector2i(0, 1), sf::Vector2i(7, 1), sf::Vector2f(37.5f, 60));
	m_animInfo[(int)Animations::DOROTHY_IDLE_R] = AnimationInfo(sf::Vector2i(0, 2), sf::Vector2i(6, 2), sf::Vector2f(37.5f, 60));
	m_animInfo[(int)Animations::DOROTHY_WALK_L] = AnimationInfo(sf::Vector2i(0, 3), sf::Vector2i(7, 3), sf::Vector2f(37.5f, 60));
	m_animInfo[(int)Animations::DOROTHY_JUMP_L] = AnimationInfo(sf::Vector2i(0, 4), sf::Vector2i(7, 4), sf::Vector2f(37.5f, 60));
	m_animInfo[(int)Animations::DOROTHY_IDLE_L] = AnimationInfo(sf::Vector2i(0, 5), sf::Vector2i(6, 5), sf::Vector2f(37.5f, 60));

	m_animInfo[(int)Animations::BLOCK		  ] = AnimationInfo(sf::Vector2i(0, 0), sf::Vector2i(0, 0), sf::Vector2f(1280.f, 668.f));
	m_animInfo[(int)Animations::Glinda		  ] = AnimationInfo(sf::Vector2i(0, 10), sf::Vector2i(8, 10), sf::Vector2f(64.f, 64.f));
	m_animInfo[(int)Animations::RANDOM_L	  ] = AnimationInfo(sf::Vector2i(0, 0), sf::Vector2i(3, 0), sf::Vector2f(46.75f, 33.f));
	m_animInfo[(int)Animations::RANDOM_R	  ] = AnimationInfo(sf::Vector2i(0, 1), sf::Vector2i(3, 1), sf::Vector2f(46.75f, 33.f));
	m_animInfo[(int)Animations::REDHEELS	  ] = AnimationInfo(sf::Vector2i(0, 0), sf::Vector2i(0, 0), sf::Vector2f(360.f, 360.f));
	m_animInfo[(int)Animations::Portal	      ] = AnimationInfo(sf::Vector2i(0, 0), sf::Vector2i(0, 0), sf::Vector2f(306, 165.f));
}
//============================================================================
void Resources::setFonts() 
{
	m_fonts[(int)Fonts::Bold_F  ] = loadSfObj<sf::Font>("Bold.TTF");
	m_fonts[(int)Fonts::Empty_F ] = loadSfObj<sf::Font>("Empty.TTF");
	m_fonts[(int)Fonts::Italic_F] = loadSfObj<sf::Font>("Italic.TTF");
	m_fonts[(int)Fonts::NpcFont ] = loadSfObj<sf::Font>("dpcomic.ttf");
}
//-----------------------------------------------------------------------------
Resources& Resources::instance()
{
	static Resources instance;
	return instance;
}
//============================================================================
void Resources::setSounds() 
{
	m_sounds[(int)Sounds::Jump] = loadSfObj<sf::SoundBuffer>("jump.wav");
}
//============================================================================
const sf::Font& Resources::getFont(int index) const
{
	auto it = m_fonts.find(index);
	if (it != m_fonts.end())
		return it->second;
	throw std::out_of_range("Font not found.");
}
//============================================================================
void Resources::playMusic(Sounds sound)
{
	switch (sound)
	{
	case Sounds::theme:
		m_music.openFromFile("theme.wav");
		break;
	}
	m_music.play();
	m_music.setLoop(true);
}
//============================================================================
void Resources::playSound(Sounds sound)
{
	m_sound.setBuffer(m_sounds.find((int)sound)->second);
	m_sound.play();
}
//============================================================================
void Resources::stopMusic()
{
	m_music.stop();
}
//============================================================================
