//=============================================================================
#include "Direction.h"
#include <stdexcept>
//=============================================================================
Direction opposite(Direction dir)
{
    switch (dir)
    {
    case Direction::Jump:
        return Direction::Jump;
    case Direction::Right:
        return Direction::Left;
    case Direction::Left:
        return Direction::Right;
    case Direction::Idle:
        return Direction::Idle;
    }
    throw std::runtime_error("Unknown direction");
}
//=============================================================================
sf::Vector2f toVector(Direction dir)
{
    switch (dir)
    {
    case Direction::Jump:
        return { 0, -1 };
    case Direction::Right:
        return { 1, 0 };
    case Direction::Left:
        return { -1, 0 };
    case Direction::Idle:
        return { 0, 0 };
    }
    throw std::runtime_error("Unknown direction");
}
//=============================================================================