#include <App.hpp>

// construction

App::App()
{
    auto title = sf::String("Fractal Studio");
    projectionSource = new ProjectionSource(title);
    states.push(new AppState(*projectionSource));
}

App::~App()
{
    delete projectionSource;
    while (!states.empty())
    {
        delete states.top();
        states.pop();
    }
}

// m_functions

void App::update(State* state)
{
    projectionSource->update(state);
    const sf::Vector2f& mousePosition = projectionSource->getMousePosition();

    if (state) { state->update(mousePosition); }
}

// functions

void App::run()
{
    while (projectionSource->isOpen())
    {
        State* state = nullptr;
        if (!states.empty()) { state = states.top(); }

        update(state);
        projectionSource->render(state);
    }
}


#ifdef _WIN32
#include <Windows.h>
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    App app;
    app.run();
    return 0;
}
#else
int main(int argc, char* argv[]) {
    App app;
    app.run();
    return 0;
}
#endif