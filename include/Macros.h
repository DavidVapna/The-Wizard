//=============================================================================
#pragma once
//=============================================================================
#include "SFML/Graphics.hpp"
#include "box2d/box2d.h"
#include "SFML/Audio.hpp"



#include <typeinfo>
#include <typeindex>
#include <ctime>
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <optional>
#include <stack>
//=============================================================================


const int NUM_OF_MAPS = 1;

//=============================================================================
//		*********   RENDERING & STUFF  ***********
//=============================================================================

constexpr auto SCALE = 30.f;
constexpr auto JUMP = 7.5f;
constexpr auto FEET_DATA = 3;
constexpr auto JUMP_EPS = 0.1f;

constexpr auto TIME_STEP = 1.0f / 60.0f;
constexpr auto VELOCITY_ITERATOR = 6;
constexpr auto POSITION_ITERATOR = 2;



const sf::Vector2u MENU_SIZE(800, 800);
const sf::Vector2u GAME_SIZE(1500, 800);

const sf::Vector2i MENU_POS(500, 130);
const sf::Vector2i GAME_POS(350, 50);

//=============================================================================
//		*****************   BUTTONS    *******************
//=============================================================================
//		*****************   POSITIONS    *******************
//-----------------------------------------------------------------------------
const sf::Vector2f BUTTONS_SIZE(200, 100);

const sf::Vector2f PLAY_POS(MENU_SIZE.x / 2.f, MENU_SIZE.y * (2.f/7.f));
const sf::Vector2f HELP_POS(MENU_SIZE.x / 2.f, MENU_SIZE.y * (4.f/7.f));
const sf::Vector2f QUIT_POS(MENU_SIZE.x / 2.f, MENU_SIZE.y * (6.f/7.f));

const sf::Vector2f HERO_START(20.f, GAME_SIZE.y - 20);


//=============================================================================
//		*****************   TEXTS    *******************
//-----------------------------------------------------------------------------
constexpr auto PLAY_TEXT("Play");
constexpr auto QUIT_TEXT("Exit");
constexpr auto HELP_TEXT("Help");
constexpr auto TITLE_TEXT("THE WIZARD");

//=============================================================================
//		*****************   Colors    *******************
//-----------------------------------------------------------------------------
const sf::Color IDLE_COLOR(sf::Color::Red);
const sf::Color HOVER_COLOR(sf::Color::Yellow);
const sf::Color CLICKED_COLOR(sf::Color::Green);

//=============================================================================
// 
//=============================================================================
const auto HERO_SIZE = sf::Vector2f(GAME_SIZE.x / 10, GAME_SIZE.y / 10);
const auto BLOCK_SIZE = sf::Vector2f(GAME_SIZE.x / 10, GAME_SIZE.y / 10);
//=============================================================================
// 
//=============================================================================

//=============================================================================
// ****************   ANIMATION SIZES   ***************
//=============================================================================
const auto LION_ANIM = sf::Vector2f(36.f, 73);
const auto LION_ANIM_RECTS = sf::Vector2i(0, 4);


//=============================================================================
// ****************   TEXTS POSITIONS   ***************
//=============================================================================
const auto TITLE_POS = sf::Vector2f(MENU_SIZE.x / 2.f, MENU_SIZE.y * 0.1f);




//=============================================================================
enum class Textures
{
	MenuBG,
	GameBG,
	MenuButtons,
	Buttons,
	CowardlyLion,
	Dorothy,
	Block,
	RedHeels,
	PauseBG,
	Mouse,
	Glinda,
	
	MaxTextures
};
//=============================================================================
enum class Sounds
{
	theme,
	Jump,



	MaxSounds
};

//=============================================================================
enum class GameStates
{
	MENU_STATE,
	GAME_STATE
};
//=============================================================================
enum Fonts
{
	Bold_F,
	Empty_F,
	Italic_F,


	MaxFonts
};
//=============================================================================
enum class Shape
{
	Polygon,
	Circle,
	Edge,
	Box
};
//=============================================================================
enum class CategoryBits
{
	Hero = 0x0001,
	Glinda = 0x0002,
	Boundries = 0x0004,
	FeetSensor = 0x0008,
	Block = 0x0010,
	Enemy = 0x0020,
	RedHeels = 0x0040,
	Dorothy = 0x0080,
};

//=============================================================================

constexpr auto MUSIC_VOLUME = 4;
constexpr auto EFFECTS_VOLUME = 5;

//=============================================================================
struct ObjectInfo
{
	std::string type, name;
	sf::Vector2f startingPos, objectSize;
	float desinity, friction;
	bool rotation;
	int bodyType;
};
//=============================================================================