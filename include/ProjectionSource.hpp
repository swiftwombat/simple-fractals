#pragma once

#include <State.hpp>

class ProjectionSource :
    public sf::RenderWindow
{
private:
    // m_variables
    sf::Vector2f mousePosition;

public:
    // construction
    ProjectionSource(const sf::String& title, const sf::VideoMode mode = sf::VideoMode().getFullscreenModes()[0]);
    virtual ~ProjectionSource();

    // functions
    const sf::Vector2f& getMousePosition() const;

    void checkEvents(const sf::Event& event);
    void update(State* state);
    void render(State* state);
};