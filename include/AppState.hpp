#pragma once

#include <State.hpp>
#include <Projection.hpp>
#include <ProjectionSource.hpp>

class AppState :
    public State
{
private:
    // m_variables
    const ProjectionSource& projectionSource;

    Projection* selectedProjection;
    std::vector<Projection*> projections;
    sf::Vector2f previousMousePosition;
    sf::Texture* screencap;

    // m_functions
    Projection* getProjectionAt(const sf::Vector2f& mousePosition);

public:
    // construction
    AppState(const ProjectionSource& projectionSource);
    virtual ~AppState();

    // functions
    void checkEvents(const sf::Event& event, const sf::Vector2f& mousePosition);
    void update(const sf::Vector2f& mousePosition);
    void render(sf::RenderTarget& target);
};