#include <State.hpp>

// construction

State::State()
{
    ended = false;
}

State::~State()
{

}

const bool& State::isEnded() const
{
    return ended;
}