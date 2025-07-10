#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class State
{
    private:
    // m_variables
    bool m_isEnded;

public:
    // construction
    State();
    virtual ~State();

    // functions
    const bool& isEnded() const;

    virtual void checkEvents(const sf::Event& event, const sf::Vector2f& mpos) = 0;
    virtual void update(const sf::Vector2f& mpos) = 0;
    virtual void render(sf::RenderTarget& target) = 0;
};