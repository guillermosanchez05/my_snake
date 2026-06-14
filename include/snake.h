#include "coord.h"
#include <deque>

class Snake{
    public:

    // Nested class for the direction of the snake
    enum class Direction {
        UP,
        DOWN,
        LEFT,
        RIGHT
    };

    // Public method to check the snake's direction
    Direction get_direction() const {} // Const forces the method to be readonly


    private:
    
    // The snake's body is defined by a Coord dqueue
    std::deque<Coord> body;

    // Attribute to store the snake's direction
    Direction current_direction;
};