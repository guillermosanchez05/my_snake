#include "board.h"
#include <iostream>
#include <cstdlib>   // srand()                                    
#include <ctime>     // time()

Board::Board(const Snake& snake){
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

void Board::place_food(const Food& food){
    // Obtain food's position
    Coord food_pos = food.get_position();

    // Place it on the board
    matrix[food_pos.y][food_pos.x] = CHAR_FOOD;
}

void Board::display() const {
    // Iterate over rows
    for (std::size_t i = 0; i < HEIGHT; ++i) {
        
        // Iterate over the columns of that row
        for (std::size_t j = 0; j < WIDTH; ++j) {
            std::cout << matrix[i][j];
        }
        
        // When a row ends, add a newline
        std::cout << '\n';
    }
}

Coord Board::get_random_coord() const{

    // First, obtain random indexes
    int random_x = rand() % (WIDTH - 2) + 1; // make sure its not a Wall
    int random_y = rand() % (HEIGHT - 2) + 1;

    // Return the coord
    Coord random_coord = {random_x, random_y};

    return random_coord;
}

bool Board::is_coord_empty(int x, int y) const{
    // Check the matrix[y][x] CHAR
    return (matrix[y][x] == CHAR_EMPTY);
}
