#ifndef SNAKE_H
#define SNAKE_H
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

    /** 
     * @brief Returns the snake's current direction
    */
    Direction get_direction() const;

    /** 
     * @brief  Returns the dqueue associated with the snake's body
    */
    const std::deque<Coord>& get_body() const;

    /**
     * @brief Constructs the snake: (centered, length = 3, direction = RIGHT).
     * @param width Board's width
     * @param height Board's height
     */
    Snake(std::size_t width, std::size_t height);

    private:
    
    // The snake's body is defined by a Coord dqueue
    std::deque<Coord> body;

    // Attribute to store the snake's direction
    Direction current_direction;
};

#endif // SNAKE_H
