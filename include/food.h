#ifndef FOOD_H
#define FOOD_H
#include "coord.h"
#include <cstddef> // for size_t

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
         * loop when necessary, passing the Board's size as arguments.
         * @param width Board's width
         * @param height Board's height
         */
        void init(std::size_t width, std::size_t height);

    private:
        // Food is defined by its position (a random position)
        Coord position;

};

#endif // FOOD_H
