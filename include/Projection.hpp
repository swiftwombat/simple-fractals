#pragma once

#include <SFML/Graphics.hpp>
#include <array>


/// @brief
class Projection :
    public sf::RectangleShape
{
private:
    // m_functions
    void init();

public:
    // construction
    Projection(const sf::Vector2f& size);
    virtual ~Projection();

    // functions
    bool contains(const sf::Vector2f& point);
    void scale(const sf::Vector2f& operands);

    void update(const sf::Texture* screencap);
    void render(sf::RenderTarget& target, const sf::RenderStates& states = sf::BlendAdd);
};