//============================================================================
#pragma once
//============================================================================
#include "Macros.h"
//=============================================================================

//=============================================================================
class Resources 
{
public:
	//----------------functions-------------------
	static Resources& instance();
	const sf::Texture& getTexture(int wantedTexture) const;
	const sf::Font& getFont(int index) const;
	void playMusic(Sounds sound);
	void playSound(Sounds sound);
	const int getButLen(int index) const;
	void stopMusic();
	const AnimationInfo& getAnimInfo(int wantedInfo) const;

private:

	Resources();
	Resources(const Resources&) = default;
	Resources& operator=(const Resources&) = default;

	void setTextures();
	void setAnimationInfo();
	void setFonts();
	void setSounds();
	void setButtonStrLengh();

private:
	std::unordered_map <int, AnimationInfo> m_animInfo;
	std::unordered_map <int, sf::Texture> m_textures;
	std::unordered_map <int, sf::Font> m_fonts;
	std::unordered_map <int, int> m_buttonStrLen;
	std::unordered_map <int, sf::SoundBuffer> m_sounds;
	sf::Sound m_sound;
	sf::Music m_music;




	template <class SfObj>
	SfObj loadSfObj(const std::string& str);

	template<class Container, class Return>
	Return findInMap(Container map, int index) const;
};
//=============================================================================
template<class Container, class Return>
Return Resources::findInMap(Container map, int index) const 
{
	auto it = map.find(index);
	if (it != map.end())
		return (it->second);
	throw std::out_of_range("Texture not found.");
}
//=============================================================================
template <class SfObj>
SfObj Resources::loadSfObj(const std::string& str) 
{
	SfObj obj;
	if (obj.loadFromFile(str))
		return std::move(obj);
	throw std::out_of_range("Coldn't find the file");
}
//============================================================================