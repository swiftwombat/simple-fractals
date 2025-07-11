#include <Projection.hpp>

// construction

Projection::Projection(const sf::Vector2f& size)
    : sf::RectangleShape(size)
{
    setOrigin(sf::Vector2f(size.x / 2.f, size.y / 2.f));
}

Projection::~Projection() {}

// functions

bool Projection::contains(const sf::Vector2f& point)
{
    const sf::Vector2f transformPoint = getInverseTransform().transformPoint(point);
    return getLocalBounds().contains(transformPoint);
}

void Projection::scale(const sf::Vector2f& operands)
{
    auto scale = getScale() + operands;
    setScale(scale);
}

void Projection::update(const sf::Texture* screencap)
{
    setTexture(screencap, false);
}

void Projection::render(sf::RenderTarget& target, const sf::RenderStates& states)
{
    target.draw(*this, states);
}
