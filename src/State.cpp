#include <State.hpp>

// construction

State::State()
{
    m_isEnded = false;
}

State::~State()
{

}

const bool& State::isEnded() const
{
    return m_isEnded;
}