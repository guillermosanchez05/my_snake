#include <iostream>
#include <cstdlib>
#include <ctime>
#include "board.h"

int main(){

    // Time-based random seed, will be used for some functions
    srand(time(0));

    // Create the snake (which will be placed on the Board)
    Snake snake(Board::WIDTH, Board::HEIGHT);

    // Create the board (with the snake placed)
    Board board(snake);

    // Create the food (needs the board to find an empty cell)
    Food initial_food(board);

    // Place the food on the board
    board.place_food(initial_food);
    
    // Display the initial board
    board.display();

    while(1){

    }

    return 0;
}
