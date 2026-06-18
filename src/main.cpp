#include <iostream>
#include "board.h"

int main(){

    // Time-based random seed, will be used for some functions
    srand(time(0));

    // Create the snake (which will be placed on the Board)
    Snake snake;
    snake.init(Board::WIDTH, Board::HEIGHT);

    // TODO: Create the food¿?

    Food initial_food;

    // Create the board
    Board board;
    board.init(snake, initial_food);
    
    // Display the initial board
    board.display();

    while(1){

    }

    return 0;
}