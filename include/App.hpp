#pragma once

#include <SFML/Graphics.hpp>
#include <AppState.hpp>
#include <ProjectionSource.hpp>
#include <stack>

class App
{
private:
    // m_variables
    ProjectionSource* projectionSource;
    std::stack<State*> states;

    // m_functions
    void update(State* state);

public:
    // construction
    App();
    virtual ~App();

    // functions
    void run();
};