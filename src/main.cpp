#include <iostream>
#include "board.h"

int main(){

    // TODO:
    /*
    
    Crear Snake (que se inicializa sola con sus posiciones iniciales internas)

    Crear Food (que se inicializa sola con una posición aleatoria interna)

    Crear Board

    Llamar a board.init(snake, food) → el tablero pregunta a snake y food y pinta

    Llamar a board.display() → muestra

    */

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