#include <Windows.h>
#include <App.hpp>

// construction

App::App()
{
    this->init();
}

App::~App()
{
    delete m_projection_source;
    while (!m_states.empty())
    {
        delete m_states.top();
        m_states.pop();
    }
}

// m_functions

void App::init()
{
    this->initProjectionSource();
    this->initStates();
}

void App::initProjectionSource()
{
    auto title = sf::String("Simple Fractals");
    m_projection_source = new ProjectionSource(title);
}

void App::initStates()
{
    m_states.push(new AppState(*m_projection_source));
}

void App::update(State* state)
{
    m_projection_source->update(state);
    const sf::Vector2f& mpos = m_projection_source->mpos();

    if (state) { state->update(mpos); }
}

// functions

void App::run()
{
    while (m_projection_source->isOpen())
    {
        State* state = nullptr;
        if (!m_states.empty()) { state = m_states.top(); }

        this->update(state);
        m_projection_source->render(state);
    }
}


int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    App app;
    app.run();
    return 0;
}
