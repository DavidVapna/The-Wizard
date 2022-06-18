//=============================================================================
#include "Controller.h"
//=============================================================================
Controller::Controller()  
    :m_currMod(GameStates::MENU_STATE)
{
    m_states.emplace(initMenu());
    m_states.top()->setWindow();
}
//=============================================================================
std::unique_ptr<State> Controller::initMenu()
{
    sf::VideoMode windSize;
    std::string windName;
    unsigned frameLim;
    loadWithFile(windSize, windName, frameLim);
    m_window = std::make_unique<sf::RenderWindow>(windSize, windName, sf::Style::Close | sf::Style::Titlebar);
    m_window->setFramerateLimit(60);
    return std::make_unique<MenuState>(m_window.get(), &m_states);
}
//=============================================================================
void Controller::loadWithFile(sf::VideoMode &windSize, std::string &windName, unsigned &frameLim)
{
    ///RETURN TO FIXXXXXXXXXXXXXXXXXXXXXXX
 /*   std::ifstream config("Config/window.ini");
    if (config.is_open())
    {
        std::getline(config, windName);
        config >> windSize.width >> windSize.height;
        config >> frameLim;
    }
    else 
    {
        windSize = sf::VideoMode(GAME_SIZE.x, GAME_SIZE.y);
        windName = "The Wizard";
        frameLim = 60;
    }*/
    windSize = sf::VideoMode(GAME_SIZE.x, GAME_SIZE.y);
    windName = "The Wizard";
    frameLim = 60;
}
//=============================================================================
Controller::~Controller()
{

}
//=============================================================================
void Controller::run()
{   
    while (m_window->isOpen())
    {  
        update();
        display();
    }
}
//=============================================================================
void Controller::update()
{
    handleEvents();

    if (!m_states.empty())
    {
        m_states.top()->update(0);
        if (m_states.top()->isEnd())
        {
            m_states.pop();
            if(!m_states.empty())
                m_states.top()->setWindow();
        }
    }
    else
        m_window->close();
}
//=============================================================================
void Controller::display()
{
    m_window->clear();

    if (!m_states.empty())
        m_states.top()->draw();

    m_window->display();
}
//=============================================================================
void Controller::handleEvents()
{
    for (auto event = sf::Event{}; m_window->pollEvent(event); )
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            m_window->close();
        }
    }
}
//=============================================================================
void Controller::closeGame()
{
    return;
}
//=============================================================================

//=============================================================================

//=============================================================================





//=============================================================================