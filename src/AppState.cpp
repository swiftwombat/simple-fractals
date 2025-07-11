#include <AppState.hpp>

// construction

AppState::AppState(const ProjectionSource& projectionSource)
    : State(), projectionSource(projectionSource)
{
    auto size = sf::Vector2u(projectionSource.getSize());
    screencap = new sf::Texture(sf::Vector2u(size.x, size.y));
    selectedProjection = nullptr;
}

AppState::~AppState()
{
    delete selectedProjection;
    delete screencap;
    for ( auto p : projections ) { delete p; }
}

// m_functions

Projection* AppState::getProjectionAt(const sf::Vector2f& mousePosition)
{
    Projection* hoveredProjection = nullptr;
    for (auto projection : projections)
    {
        const bool isSmaller =
            !hoveredProjection || projection->getScale().x < hoveredProjection->getScale().x;
        if (projection->contains(mousePosition) && isSmaller)
            hoveredProjection = projection;
    }
    return hoveredProjection;
}

// functions

void AppState::checkEvents(const sf::Event& e, const sf::Vector2f& mousePosition)
{
    if (const auto* keyPress = e.getIf<sf::Event::KeyPressed>())
    {
        // add new projection
        if (keyPress->scancode == sf::Keyboard::Scancode::Space)
        {
            auto newProjection = new Projection(sf::Vector2f(projectionSource.getSize()) / 6.f);
            newProjection->setPosition(mousePosition);
            projections.push_back(newProjection);
        }
    }
    else if (const auto* mouseButtonPress = e.getIf<sf::Event::MouseButtonPressed>())
    {
        // delete projection
        if (mouseButtonPress->button == sf::Mouse::Button::Right)
        {
            Projection* selectedProjection = getProjectionAt(mousePosition);
            auto i = std::find(projections.begin(), projections.end(), selectedProjection);
            if (i != projections.end()) { projections.erase(i); }
        }
    }
    else if (const auto* mouseWheelScroll = e.getIf<sf::Event::MouseWheelScrolled>())
    {
        // rotate projection
        Projection* hoveredProjection = getProjectionAt(mousePosition);
        auto ds = mouseWheelScroll->delta;
        if (hoveredProjection)
        {
            bool scaling = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift);
            if (scaling) { hoveredProjection->scale(sf::Vector2f(0.1f, 0.1f) * ds); }
            else         { hoveredProjection->rotate(sf::degrees(1.4f * ds)); }
        }
    }
}

void AppState::update(const sf::Vector2f& mousePosition)
{
    screencap->update(projectionSource);
    for (auto proj : projections) { proj->update(screencap); }

    if (!sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
    {
        selectedProjection = nullptr;
        return;
    }
    if (!selectedProjection) { selectedProjection = getProjectionAt(mousePosition); }
    else                    { selectedProjection->move(mousePosition - previousMousePosition); }
    previousMousePosition = mousePosition;
}

void AppState::render(sf::RenderTarget& target)
{
    for (auto proj : projections) { proj->render(target); }
}
