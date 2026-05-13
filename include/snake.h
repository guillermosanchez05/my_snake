#include <point.h>

#define MAX_SIZE 8 // The maximum lenght of the snake will be 8 (win condition)

/* Struct to represent the snake (a set of Points in our board) */

struct Snake{
    Point snake[16];
}