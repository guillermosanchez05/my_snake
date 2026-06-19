#include "food.h"
#include "board.h"

// Definition of the Food class methods

Food::Food(const Board& board){
    do {
        // Obtain a random coordinate that is not a wall and assign the Food's position
        position = board.get_random_coord();
        // Repeat while the cell is not an empty one
    } while (!board.is_coord_empty(position.x, position.y));
}

const Coord& Food::get_position() const{
    return position;
}

