#include <iostream>
#include <cstdlib>
#include <ctime>
#include <ncurses.h>
#include "board.h"

int main(){

    // Time-based random seed, will be used for some functions
    srand(time(0));

    // Initialize ncurses
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    timeout(100); // wait up to 100 ms for a key press

    // Create the snake (which will be placed on the Board)
    Snake snake(Board::WIDTH, Board::HEIGHT);

    // Create the board (with the snake placed)
    Board board(snake);

    // Create the food (needs the board to find an empty cell)
    Food food(board);

    // Place the food on the board
    board.place_food(food);

    bool game_over = false;

    while (!game_over) {
        // Handle input
        int ch = getch();
        if (ch != ERR) {
            switch (ch) {
                case KEY_UP:    snake.change_direction(Snake::Direction::UP);    break;
                case KEY_DOWN:  snake.change_direction(Snake::Direction::DOWN);  break;
                case KEY_LEFT:  snake.change_direction(Snake::Direction::LEFT);  break;
                case KEY_RIGHT: snake.change_direction(Snake::Direction::RIGHT); break;
                case 'q':       game_over = true;                                break;
            }
        }

        // Move the snake
        if (!snake.move(board, food)) {
            game_over = true;
            break;
        }

        // Check if the snake ate the food
        if (snake.get_body().front().x == food.get_position().x &&
            snake.get_body().front().y == food.get_position().y) {
            // Generate new food
            Food new_food(board);
            board.place_food(new_food);
            food = new_food; // update local variable
        }

        // Redraw the board
        clear();
        board.display();

        // Control game speed
        napms(200);
    }

    // Clean up ncurses
    endwin();

    std::cout << "Game Over!" << std::endl;

    return 0;
}
