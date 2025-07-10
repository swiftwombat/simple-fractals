#include <ProjectionSource.hpp>

// construction

ProjectionSource::ProjectionSource(const sf::String &title, const sf::VideoMode mode)
    : sf::RenderWindow(mode, title, sf::Style::None, sf::State::Fullscreen)
{
    this->init();
}

ProjectionSource::~ProjectionSource()
{

}

// m_functions

void ProjectionSource::init()
{
    // sf::Image icon;
    // icon.loadFromFile("./img/icon.png");
    // this->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    this->setKeyRepeatEnabled(false);
}

// functions

const sf::Vector2f& ProjectionSource::mpos() const
{
    return m_mpos;
}

void ProjectionSource::checkEvents(const sf::Event& e)
{
    if (e.is<sf::Event::Closed>())
        this->close();

    if (const auto* keyPressed = e.getIf<sf::Event::KeyPressed>())
        if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
            this->close();
}

void ProjectionSource::update(State* state)
{
    m_mpos = mapPixelToCoords(sf::Mouse::getPosition(*this));

    while (const std::optional event = this->pollEvent())
    {
        if (event) {
            this->checkEvents(*event);
            if (state) { state->checkEvents(*event, m_mpos); }
        }
    }
}

void ProjectionSource::render(State* state)
{
    this->clear(sf::Color(2u, 2u, 2u));
    if(state) { state->render(*this); }
    this->display();
}
