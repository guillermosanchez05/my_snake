#ifndef BOARD_H
#define BOARD_H

#include <array>
#include <cstddef> // size_t

#include "snake.h"
#include "food.h"

class Board {
    public:
        // Public constants so other classes can check them
        static constexpr std::size_t WIDTH = 32;
        static constexpr std::size_t HEIGHT = 16;

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
         * @brief Constructs the board: filling the board matrix with empty or
         * filled characters and the snake's initial position 
         * (centered, length = 3, direction = RIGHT for the snake).
         * @param snake Reference to the Snake object (already constructed)
        */
        Board(const Snake& snake);

        /** 
         * @brief Places the food on the board after it has been constructed.
         * @param food Reference to the Food object (already constructed)
        */
        void place_food(const Food& food);

        /** 
         * @brief Updates the board on the screen
        */
        void display() const;

        /**
         * @brief Returns a random Coord inside of the Board
         */
        Coord get_random_coord() const;

        /**
         * @brief Checks if a Coord is empty by looking at its content
         */
        bool is_coord_empty(int x, int y) const;

};

#endif // BOARD_H
