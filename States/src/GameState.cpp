//=============================================================================
//debug
#include <format>
//=============================================================================
#include "GameState.h"
//=============================================================================
enum currMap{first, second, third};
//=============================================================================
GameState::GameState(sf::RenderWindow* window, std::stack<std::unique_ptr<State>>* states)
    :State(window, states),
    m_world(b2Vec2(0.f, 9.8)),
    m_gameBoard(m_window, &m_world),
    m_debugMouse("", Resources::instance().getFont(Fonts::Bold_F))
{
    m_debugMouse.setFillColor(sf::Color::Red);
    m_world.SetContactListener(&m_contactListener);
    setWindow();
    setBoundries();
    setBG();
    Resources::instance().playMusic(Sounds::theme);
}
//=============================================================================
GameState::~GameState()
{

}
//=============================================================================
void GameState::setWindow()
{
    m_window->setSize(sf::Vector2u(GAME_SIZE.x, GAME_SIZE.y));
    m_window->setPosition(GAME_POS);

    sf::Vector2f viewSize(m_window->getSize().x / 2, m_window->getSize().y);
    m_view = sf::View(sf::Vector2f(viewSize.x / 2.f, viewSize.y / 2.f), viewSize);
    m_window->setView(m_view);
}
//=============================================================================
void GameState::setBG()
{
    switch (m_gameBoard.getCurrMap())
    {
    case first:
        m_backGround.setTexture(Resources::instance().getTexture((int)Textures::GameBG0));
        break;
    case second:
        m_backGround.setTexture(Resources::instance().getTexture((int)Textures::GameBG1));
        break;
    case third:
        m_backGround.setTexture(Resources::instance().getTexture((int)Textures::GameBG2));
        break;
    }
    auto textSize = m_backGround.getTexture()->getSize();
    m_backGround.setScale(m_window->getSize().x / m_backGround.getGlobalBounds().width,
        m_window->getSize().y / m_backGround.getGlobalBounds().height);
}
//=============================================================================
void GameState::setButtons()
{
    return;
}
//=============================================================================
void GameState::setBoundries()
{
    auto screenSize = m_window->getSize();
    float widthInMeters = screenSize.x / SCALE;
    float heightInMeters = screenSize.y / SCALE;
    b2Vec2 topLeftCorner = b2Vec2(0, 0);
    b2Vec2 topRightCorner = b2Vec2(widthInMeters, 0);
    b2Vec2 lowerLeftCorner = b2Vec2(0, heightInMeters);
    b2Vec2 lowerRightCorner = b2Vec2(widthInMeters, heightInMeters);


    b2BodyDef screenBorderDef;
    screenBorderDef.position.Set(0, 0);
    b2Body* screenBorderBody = m_world.CreateBody(&screenBorderDef);
    b2EdgeShape screenBorderShape;

    b2FixtureDef fixture;
    fixture.shape = &screenBorderShape;
    fixture.friction = 1.f;


    screenBorderShape.SetTwoSided(topLeftCorner, topRightCorner);
    screenBorderBody->CreateFixture(&fixture);
    screenBorderShape.SetTwoSided(topRightCorner, lowerRightCorner);
    screenBorderBody->CreateFixture(&fixture);
    screenBorderShape.SetTwoSided(lowerRightCorner, lowerLeftCorner);
    screenBorderBody->CreateFixture(&fixture);
    screenBorderShape.SetTwoSided(lowerLeftCorner, topLeftCorner);
    screenBorderBody->CreateFixture(&fixture);
}
//=============================================================================
void GameState::debugMouse()
{
    updateMouse();
    m_debugMouse.setString(std::format("({}, {})", (int)m_mouseView.x, (int)m_mouseView.y));
    m_debugMouse.setPosition(m_window->mapPixelToCoords({ m_mouseWindow.x, m_mouseWindow.y }));
    m_window->draw(m_debugMouse);
}
//=============================================================================
void GameState::update(const float& deltaTime)
{
    if (m_gameBoard.mapFisnished())
    {
        m_gameBoard.nextMap();
        setWindow();
        setBG();
    }
    else
    {
        m_deltaTime = m_gameClock.restart().asSeconds();
        m_world.Step(TIME_STEP, VELOCITY_ITERATOR, POSITION_ITERATOR);
        updateInput(m_deltaTime);
        m_gameBoard.update(m_deltaTime);
        updateView();
    }
}
//=============================================================================
void GameState::updateInput(const float& deltaTime)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
    {
        this->m_end = true;
        Resources::instance().stopMusic();
        return;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P))
    {
        if (!m_pause)
            m_states->emplace(std::make_unique<PauseState>(m_window, nullptr));
    }
}
//=============================================================================
void GameState::updateView()
{
    sf::Vector2f heroPos = m_gameBoard.getHeroPos();
    if (heroPos.x - m_window->getSize().x / 4 < 0)
    {
        m_view.setCenter(m_window->getSize().x / 4, m_view.getCenter().y);
    }
    else if ((heroPos.x + m_window->getSize().x / 4) > GAME_SIZE.x)
    {
        m_view.setCenter(GAME_SIZE.x - m_window->getSize().x / 4, m_view.getCenter().y);
    }
    else
        m_view.setCenter(heroPos.x, m_view.getCenter().y);

    m_window->setView(m_view);
}
//=============================================================================
void GameState::draw()
{
    m_window->draw(m_backGround);
    m_gameBoard.draw();
    debugMouse();
}
//=============================================================================

//=============================================================================

//=============================================================================
//=============================================================================

//=============================================================================
