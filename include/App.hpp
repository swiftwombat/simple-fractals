#pragma once

#include <SFML/Graphics.hpp>

#include <AppState.hpp>
#include <ProjectionSource.hpp>

#include <stack>

class App
{
private:
    // m_variables
    ProjectionSource* m_projection_source;
    std::stack<State*> m_states;

    // m_functions
    void init();
    void initProjectionSource();
    void initStates();

    void update(State* state);

public:
    // construction
    App();
    virtual ~App();

    // functions
    void run();
};