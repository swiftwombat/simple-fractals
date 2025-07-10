#pragma once

#include <State.hpp>

class ProjectionSource :
    public sf::RenderWindow
{
private:
    // m_variables
    sf::Vector2f m_mpos;

    // m_functions
    void init();

public:
    // construction
    ProjectionSource(const sf::String& title, const sf::VideoMode mode = sf::VideoMode().getFullscreenModes()[0]);
    virtual ~ProjectionSource();

    // functions
    const sf::Vector2f& mpos() const;

    void checkEvents(const sf::Event& event);
    void update(State* state);
    void render(State* state);
};