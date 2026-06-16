#ifndef BOARD_H
#define BOARD_H

#include <array>
#include <cstddef> // size_t

#include "snake.h"
#include "food.h"

class Board {
    public:
        // Public constants so other classes can check them
        static constexpr std::size_t WIDTH = 64;
        static constexpr std::size_t HEIGHT = 64;

    private:

        // Characters to draw the actual board
        static constexpr char CHAR_EMPTY = ' ';
        static constexpr char CHAR_WALL = '#';
        static constexpr char CHAR_SNAKE = '0';
        static constexpr char CHAR_FOOD = '+';

        // The board is a 2D fixed-length array (defined in stack)
        std::array<std::array<char, WIDTH>, HEIGHT> matrix;

    public: // methods
        /** 
         * @brief Initializes the board: filling the board matrix with empty or
         * filled characters and both the snake's and food's initial positions 
         * (centered, length = 3, direction = RIGHT for the snake and random for
         * the food).
        */
        void init(const Snake& snake, const Food& food); // Readonly parameters

        /** 
         * @brief Updates the board on the screen
        */
        void display() const;

};

#endif // BOARD_H