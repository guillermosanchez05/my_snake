#include "board.h"
#include <iostream>

void Board::init(){
    // Optimise cache hits
    for (int j = 0; j < static_cast<int>(HEIGHT); j++){
        for (int i = 0; i < static_cast<int>(WIDTH); i++){
            matrix[i][j] = CHAR_EMPTY;
        }
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
