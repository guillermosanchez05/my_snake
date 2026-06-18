#include <iostream>
#include <cstdlib>
#include <ctime>
#include "board.h"

int main(){

    // Time-based random seed, will be used for some functions
    srand(time(0));

    // Create the snake (which will be placed on the Board)
    Snake snake;
    snake.init(Board::WIDTH, Board::HEIGHT);

    // Create both the board and the food
    Board board;
    Food initial_food;

    // Initialize them
    board.init(snake, initial_food);
    initial_food.init(board);
    
    // Display the initial board
    board.display();

    while(1){

    }

    return 0;
}
