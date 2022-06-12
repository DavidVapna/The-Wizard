//=============================================================================
#include "MenuState.h"
//=============================================================================

//=============================================================================
MenuState::MenuState(sf::RenderWindow* window, std::stack<std::unique_ptr<State>>* states)
    :State(window, states)
{
    setBG();
    setButtons();
    setTitle();
}
//=============================================================================
void MenuState::setTitle()
{
    m_title.setFont(Resources::instance().getFont((int)Fonts::Bold_F));
    m_title.setCharacterSize(45);
    m_title.setString(TITLE_TEXT);
    m_title.setPosition(TITLE_POS);
    m_title.setOrigin(m_title.getGlobalBounds().width / 2.f, m_title.getGlobalBounds().height / 2.f);
    m_title.setColor(sf::Color::Red);
}
//=============================================================================
MenuState::~MenuState() 
{

}
//=============================================================================

//=============================================================================
void MenuState::setBG()
{
    m_backGround.setTexture(Resources::instance().getTexture((int)Textures::MenuBG));
    auto size = m_backGround.getTexture()->getSize();
    m_backGround.scale(sf::Vector2f(MENU_SIZE.x / size.x, MENU_SIZE.y / size.y));
}
//=============================================================================
void MenuState::setButtons()
{
    m_buttons[Play_B] = std::make_unique<Button>
        (PLAY_POS, BUTTONS_SIZE, PLAY_TEXT, sf::Color::Red, sf::Color::Yellow, sf::Color::Green);
    m_buttons[Help_B] = std::make_unique<Button>
        (HELP_POS, BUTTONS_SIZE, HELP_TEXT, sf::Color::Red, sf::Color::Yellow, sf::Color::Green);
    m_buttons[Quit_B] = std::make_unique<Button>
        (QUIT_POS, BUTTONS_SIZE, QUIT_TEXT, sf::Color::Red, sf::Color::Yellow, sf::Color::Green);
}
//=============================================================================

//=============================================================================
void MenuState::setWindow()
{
    m_window->setView(sf::View(sf::FloatRect(0, 0, MENU_SIZE.x, MENU_SIZE.y)));
    m_window->setSize(sf::Vector2u(MENU_SIZE.x, MENU_SIZE.y));
    m_window->setPosition(MENU_POS);

}
//=============================================================================
void MenuState::draw()
{
    m_window->draw(m_backGround);
    m_window->draw(m_title);

    for (auto& button : m_buttons)
    {
        button.second->draw(*m_window);
    }
}
//=============================================================================
void MenuState::update(const float& deltaTime)
{
    updateMouse();
    updateInput(deltaTime);
    for (auto& button : m_buttons)
    {
        button.second->update(m_mouseView);
    }
    if (m_buttons.find(Quit_B)->second->isClicked())
    {
        this->m_end = true;
    }
    if (m_buttons.find(Play_B)->second->isClicked() || 
        sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P))
    {
        m_states->emplace(std::make_unique<GameState>(m_window, this->m_states));
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q))
    {
        this->m_end = true;
    }

    
}
//=============================================================================
void MenuState::updateInput(const float& deltaTime)
{
    return;
}
//=============================================================================

//=============================================================================

//=============================================================================