#include <stdio.h>

// To get the view of a square in a terminal, width has to be twice the height
#define BOARD_WIDTH 32 // 32 x 16 board
#define BOARD_HEIGHT 16



void displayBoard(){

    // Draw the top border
    for (int i = 0; i < BOARD_WIDTH; i++){
        printf("─");
    }
    printf("\n"); // Go onto next line

    // For each line, we gotta print '|' at indexes 0 and (BOARD_WIDTH - 1)
    for (int i = 0; i < BOARD_HEIGHT; i++){
        for (int j = 0; j < BOARD_WIDTH; j++){
            if (j == 0 or j == (BOARD_WIDTH - 1)){
                printf("|");
            } else {
                printf(" ");
            }

        }
        printf("\n");
    }

    for (int i = 0; i < BOARD_WIDTH; i++){
        printf("─");
    }

    printf("\n");
}

int main(){
    displayBoard();
    return 0;
}