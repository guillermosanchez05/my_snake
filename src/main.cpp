#include <iostream>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <ncurses.h>
#include "board.h"

int main(){

    // Time-based random seed, will be used for some functions
    srand(time(0));

    // Ncurses
    initscr(); // Initialize ncurses
    cbreak(); // Keyboard input instantly available
    noecho(); // Avoid printing pressed keys
    keypad(stdscr, TRUE); // Enable special key reading
    timeout(0);   // Non-blocking input, returns ERR immediately if no key is pressed
    curs_set(0);  // Hide cursor

    // Create the snake (which will be placed on the Board)
    Snake snake(Board::WIDTH, Board::HEIGHT);

    // Create the board (with the snake placed)
    Board board(snake);

    // Create the food (needs the board to find an empty cell)
    Food food(board);

    // Place the food on the board
    board.place_food(food);

    // Display initial board
    board.display();
    refresh();

    // Flags for game state
    bool game_over = false;
    bool game_won = false;

    // Buffer queue to store pending movements, fixes the issue with simultaneous keystrokes
    std::queue<int> input_queue;

    // Main game loop
    while (!game_over) {
        // Collect all available inputs in this frame
        int ch;
        while ((ch = getch()) != ERR) {
            // Press q to quit the game
            if (ch == 'q') {
                game_over = true;
            }
            
            // Queue valid direction keys, capping the size at 2 to prevent input lag
            if (ch == KEY_UP || ch == KEY_DOWN || ch == KEY_LEFT || ch == KEY_RIGHT) {
                if (input_queue.empty()) {
                    input_queue.push(ch);
                } else if (input_queue.size() < 2 && input_queue.back() != ch) {
                    // Avoid duplicating the same key if held down
                    input_queue.push(ch);
                }
            }
        }

        // Process only ONE input from the queue per game tick
        if (!input_queue.empty()) {
            int current_ch = input_queue.front();
            input_queue.pop();
            
            // Evaluate the current pressed key
            switch (current_ch) {
                case KEY_UP:    snake.change_direction(Snake::Direction::UP);    break;
                case KEY_DOWN:  snake.change_direction(Snake::Direction::DOWN);  break;
                case KEY_LEFT:  snake.change_direction(Snake::Direction::LEFT);  break;
                case KEY_RIGHT: snake.change_direction(Snake::Direction::RIGHT); break;
            }
        }

        // Move the snake, game ends if it collides against a wall or itself
        if (!snake.move(board, food)) {
            game_over = true;
            break;
        }

        // Update the snake on the matrix
        board.update(snake, food);

        // Check if the snake ate the food
        if (snake.get_body().front().x == food.get_position().x &&
            snake.get_body().front().y == food.get_position().y) {
            
            // Check win condition to prevent an infinite loop in food generation
            std::size_t max_cells = (Board::WIDTH - 2) * (Board::HEIGHT - 2);
            if (snake.get_body().size() >= max_cells) {
                game_won = true;
                game_over = true;
                break;
            }

            // Generate new food
            Food new_food(board);
            food = new_food; // Update local variable
            
            // Update again so the food appears on the matrix
            board.update(snake, food);
        }

        // Redraw the board
        clear();
        board.display();

        // Control game speed by pausing the execution for 200 ms
        napms(200);
    }

    // Clean up ncurses, restores the terminal configuration
    endwin();

    // Print final game result
    if (game_won) {
        std::cout << "Congratulations! You won!" << std::endl;
    } else {
        std::cout << "Game Over!" << std::endl;
    }

    return 0;
}