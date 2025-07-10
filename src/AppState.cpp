#include <AppState.hpp>

// construction

AppState::AppState(const ProjectionSource& projection_source)
    : State(), m_projection_source(projection_source)
{
    this->init();
}

AppState::~AppState()
{
    delete this->m_curr_proj;
    delete this->m_screencap;
    for ( auto p : this->m_projections ) { delete p; }
}

// m_functions

void AppState::init()
{
    auto size = sf::Vector2u(this->m_projection_source.getSize());
    this->m_screencap = new sf::Texture(sf::Vector2u(size.x, size.y));
    this->m_curr_proj = nullptr;
}

Projection* AppState::getProjectionAt(const sf::Vector2f& mpos)
{
    Projection* p_proj = nullptr;
    for (auto p : this->m_projections)
    {
        if (!p->contains(mpos)) { continue; }
        p_proj = p;
        break;
    }
    return p_proj;
}

// functions

void AppState::checkEvents(const sf::Event& e, const sf::Vector2f& mpos)
{
    // add new projection
    if (const auto* keyPressed = e.getIf<sf::Event::KeyPressed>())
        if (keyPressed->scancode == sf::Keyboard::Scancode::Space)
        {
            auto p_proj = new Projection(sf::Vector2f(this->m_projection_source.getSize()) / 6.f);
            p_proj->setPosition(mpos);
            this->m_projections.push_back(p_proj);
        }

    // delete projection
    if (const auto* mouseButtonPress = e.getIf<sf::Event::MouseButtonPressed>())
        if (mouseButtonPress->button == sf::Mouse::Button::Right)
        {
            auto i = this->m_projections.begin();
            while (i != this->m_projections.end())
            {
                auto p_proj = *i;
                if (p_proj->contains(mpos)) { this->m_projections.erase(i); break; }
                else                        { ++i; }
            }
        }

    // rotate projection
    if (const auto* mouseWheelScroll = e.getIf<sf::Event::MouseWheelScrolled>())
    {
        Projection* p_proj = getProjectionAt(mpos);
        auto ds = mouseWheelScroll->delta;
        if (p_proj)
        {
            bool scaling = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift);
            if (scaling) { p_proj->scale(sf::Vector2f(0.1f, 0.1f) * ds); }
            else         { p_proj->rotate(sf::degrees(1.5f * ds)); }
        }
    }
}

void AppState::update(const sf::Vector2f& mpos)
{
    this->m_screencap->update(this->m_projection_source);
    for (auto proj : this->m_projections) { proj->update(this->m_screencap); }


    if (!sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
    {
        this->m_curr_proj = nullptr;
        return;
    }

    if (!this->m_curr_proj)
    {
        for (auto proj : this->m_projections)
        {
            if (!proj->contains(mpos)) { continue; }
            this->m_prev_mpos = mpos;
            this->m_curr_proj = proj;
            break;
        }
    }
    else
    {
        this->m_curr_proj->move(mpos - m_prev_mpos);
        this->m_prev_mpos = mpos;
    }
}

void AppState::render(sf::RenderTarget& target)
{
    for (auto proj : this->m_projections) { proj->render(target); }
}
