#include "board.h"
#include <iostream>

void Board::init(const Snake& snake, const Food& food){
    // First, fill the matrix with empty chars while optimising cache hits
    for (int j = 0; j < static_cast<int>(HEIGHT); j++){
        for (int i = 0; i < static_cast<int>(WIDTH); i++){
            if (j == 0 or i == 0 or j == (HEIGHT - 1) or i == (WIDTH - 1)){
                // It's a wall
                matrix[j][i] = CHAR_WALL;
            } else {
                matrix[j][i] = CHAR_EMPTY;
            }
        }
    }

    // Obtain snake's body
    std::deque<Coord> body = snake.get_body();

    // Place the snake over the board
    for (const auto& segment : body){
        matrix[segment.y][segment.x] = CHAR_SNAKE;
    }
}

void Board::display() const {
    // Iterate over rows
    for (std::size_t i = 0; i < HEIGHT; ++i) {
        
        // Iterate over the columns of that row
        for (std::size_t j = 0; j < WIDTH; ++j) {
            std::cout << matrix[i][j];
        }
        
        // When we end a row, we add a newline
        std::cout << '\n';
    }
}

Coord Board::get_random_coord() const{}

bool Board::is_coord_empty(int x, int y) const{}
