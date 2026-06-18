#ifndef FOOD_H
#define FOOD_H
#include "coord.h"

// Forward declaration to avoid circular dependency
class Board;

/**
 * @brief Class to represent the position of Food in the Board.
 * Food is just a Coord with a different char in it. 
 * There's only one food at a time.
 */
class Food{
    public:
        /**
         * @brief Initializes the food by giving a random value chosen from the
         * empty cells of the board's matrix. It should be called in the main 
         * loop when necessary, passing a reference to the Board.
         * @param board Reference to the Board object
         */
        void init(const Board& board);

    private:
        // Food is defined by its position (a random position)
        Coord position;

};

#endif // FOOD_H
