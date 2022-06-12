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
constexpr auto JUMP = 1.7f;

constexpr auto JUMP_EPS = 0.1f;

constexpr auto TIME_STEP = 1.0f / 60.0f;
constexpr auto VELOCITY_ITERATOR = 6;
constexpr auto POSITION_ITERATOR = 2;



const sf::Vector2u MENU_SIZE(800, 800);
const sf::Vector2u GAME_SIZE(900, 900);

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
	Hay,
	RedHeels,
	PauseBG,
	
	MaxTextures
};
//=============================================================================
enum class Sounds
{

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

constexpr auto MUSIC_VOLUME = 10;
constexpr auto EFFECTS_VOLUME = 10;

//=============================================================================