#pragma once

#include <State.hpp>
#include <Projection.hpp>
#include <ProjectionSource.hpp>

class AppState :
    public State
{
private:
    // m_variables
    const ProjectionSource& m_projection_source;

    Projection* m_curr_proj;
    std::vector<Projection*> m_projections;
    sf::Vector2f m_prev_mpos;
    sf::Texture* m_screencap;

    // m_functions
    void init();
    Projection* getProjectionAt(const sf::Vector2f& mpos);

public:
    // construction
    AppState(const ProjectionSource& projection_source);
    virtual ~AppState();

    // functions
    void checkEvents(const sf::Event& event, const sf::Vector2f& mpos);
    void update(const sf::Vector2f& mpos);
    void render(sf::RenderTarget& target);
};