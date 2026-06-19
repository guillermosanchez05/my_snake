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
         * @brief Constructs the food by giving a random value chosen from the
         * empty cells of the board's matrix.
         * @param board Reference to the Board object
         */
        Food(const Board& board);

        /** 
         * @brief  Returns the Coord associated with the food's position
        */
        const Coord& get_position() const;

    private:
        // Food is defined by its position (a random position)
        Coord position;

};

#endif // FOOD_H
