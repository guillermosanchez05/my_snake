#ifndef SNAKE_H
#define SNAKE_H
#include "coord.h"
#include "board.h"
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
    Direction get_direction() const; // Const forces the method to be readonly

    /** 
     * @brief  Returns the dqueue associated with the snake's body
    */
    const std::deque<Coord>& get_body() const;

    /**
     * @brief Initializes the snake: (centered, length = 3, direction = RIGHT).
     * Should be called in the main loop when necessary, passing the Board's size
     * as arguments.
     * @param width Board's width
     * @param height Board's height
     */
    void init(std::size_t width, std::size_t height);

    private:
    
    // The snake's body is defined by a Coord dqueue
    std::deque<Coord> body;

    // Attribute to store the snake's direction
    Direction current_direction;
};

#endif // SNAKE_H