#include <Projection.hpp>

// construction

Projection::Projection(const sf::Vector2f& size)
    : sf::RectangleShape(size)
{
    this->init();
}

Projection::~Projection()
{

}

// m_functions

void Projection::init()
{
    auto size = this->getSize();
    this->setOrigin(sf::Vector2f(size.x / 2.f, size.y / 2.f));
}

// functions

bool Projection::contains(const sf::Vector2f& point)
{
    const sf::Vector2f tpoint = this->getInverseTransform().transformPoint(point);
    return this->getLocalBounds().contains(tpoint);
}

void Projection::scale(const sf::Vector2f& operands)
{
    auto scale = this->getScale() + operands;
    this->setScale(scale);
}

void Projection::update(const sf::Texture* screencap)
{
    this->setTexture(screencap, false);
}

void Projection::render(sf::RenderTarget& target, const sf::RenderStates& states)
{
    target.draw(*this, states);
}
