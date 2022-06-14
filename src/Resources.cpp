//============================================================================
#include "Resources.h"
//============================================================================
using TexturesPair = std::pair<int, sf::Texture>;
using ButtonPairStr = std::pair<int, int>;
using FontPair = std::pair<int, sf::Font>;
//============================================================================
/*
* Singeltone that holds all the Resources in the game
* c-tor
*/
Resources::Resources()
	: m_buttonStrLen(), m_textures((int)Textures::MaxTextures), m_fonts((int)Fonts::MaxFonts),
	m_sounds((int)Sounds::MaxSounds), m_music()
{
	setTextures();
	setButtonStrLengh();
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
//sets all textures  of textures map
void Resources::setTextures() 
{
	m_textures.insert(TexturesPair((int)Textures::MenuBG, loadSfObj<sf::Texture>("MenuBG.png")));
	m_textures.insert(TexturesPair((int)Textures::GameBG, loadSfObj<sf::Texture>("GameState.png")));
	m_textures.insert(TexturesPair((int)Textures::MenuButtons, loadSfObj<sf::Texture>("MenuButtons.png")));
	m_textures.insert(TexturesPair((int)Textures::Buttons, loadSfObj<sf::Texture>("Buttons.jpg")));
	m_textures.insert(TexturesPair((int)Textures::CowardlyLion, loadSfObj<sf::Texture>("CowardlyLion.png")));
	m_textures.insert(TexturesPair((int)Textures::Dorothy, loadSfObj<sf::Texture>("Dorothy.png")));
	m_textures.insert(TexturesPair((int)Textures::Block, loadSfObj<sf::Texture>("Hay.jpg")));
	m_textures.insert(TexturesPair((int)Textures::RedHeels, loadSfObj<sf::Texture>("RedHeels.png")));
	m_textures.insert(TexturesPair((int)Textures::Mouse, loadSfObj<sf::Texture>("Mouse.png")));
	m_textures.insert(TexturesPair((int)Textures::Glinda, loadSfObj<sf::Texture>("Glinda.png")));
	m_textures.insert(TexturesPair((int)Textures::PauseBG, loadSfObj<sf::Texture>("PauseBG.png")));
}
//============================================================================
//sets the butten len based on the string len
void Resources::setButtonStrLengh() 
{
	return;
	//m_buttonStrLen.insert(ButtonPairStr(singlePlayer, strlen("single player")));
}
//============================================================================

//============================================================================
void Resources::setFonts() 
{
	m_fonts.insert(FontPair((int)Fonts::Bold_F, loadSfObj<sf::Font>("Bold.TTF")));
	m_fonts.insert(FontPair((int)Fonts::Empty_F, loadSfObj<sf::Font>("Empty.TTF")));
	m_fonts.insert(FontPair((int)Fonts::Italic_F, loadSfObj<sf::Font>("Italic.TTF")));
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
	m_sounds.insert(std::pair<int, sf::SoundBuffer>((int)Sounds::Jump, loadSfObj<sf::SoundBuffer>("jump.wav")));
}
//============================================================================
const int Resources::getButLen(int index) const
{
	return findInMap<std::unordered_map<int, int>, int>(m_buttonStrLen, index);
}
//============================================================================

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
//============================================================================
//============================================================================


