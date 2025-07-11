#include <ProjectionSource.hpp>

// construction

ProjectionSource::ProjectionSource(const sf::String &title, const sf::VideoMode mode)
    : sf::RenderWindow(mode, title, sf::Style::None, sf::State::Fullscreen)
{
    // sf::Image icon;
    // icon.loadFromFile("./img/icon.png");
    // setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    setKeyRepeatEnabled(false);
}

ProjectionSource::~ProjectionSource() {}

// functions

const sf::Vector2f& ProjectionSource::getMousePosition() const
{
    return mousePosition;
}

void ProjectionSource::checkEvents(const sf::Event& e)
{
    if (e.is<sf::Event::Closed>())
        close();

    if (const auto* keyPressed = e.getIf<sf::Event::KeyPressed>())
        if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
            close();
}

void ProjectionSource::update(State* state)
{
    mousePosition = mapPixelToCoords(sf::Mouse::getPosition(*this));

    while (const std::optional event = pollEvent())
    {
        if (event) {
            checkEvents(*event);
            if (state) { state->checkEvents(*event, mousePosition); }
        }
    }
}

void ProjectionSource::render(State* state)
{
    clear(sf::Color(2u, 2u, 2u));
    if(state) { state->render(*this); }
    display();
}
