#ifndef SNAKE_H
#define SNAKE_H
#include "coord.h"
#include "food.h"
#include <deque>

// Forward declaration to avoid circular dependency
class Board;

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

    /**
     * @brief Changes the snake's direction, preventing a 180° turn.
     * @param dir New direction
     */
    void change_direction(Direction dir);

    /**
     * @brief Moves the snake one step in its current direction.
     *        Checks collisions with walls and its own body.
     * @param board Reference to the Board (to check walls)
     * @param food  Reference to the current Food (to detect eating)
     * @return true if the snake is still alive, false if it died
     */
    bool move(const Board& board, const Food& food);

    private:
    
    // The snake's body is defined by a Coord dqueue
    std::deque<Coord> body;

    // Attribute to store the snake's direction
    Direction current_direction;
};

#endif // SNAKE_H
