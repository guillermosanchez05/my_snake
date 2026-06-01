#include <coord.h>

char getPointChar(Coord coordinate){
    switch (coordinate.type)
    {
    case FOOD:
        /* The coordinate is FOOD */
        return '●';
        break;
    case SNAKE:
        /* The coordinate is part of the snake */
        return '█';
        break;

    default:
        /* The coordinate is empty */
        return ' ';
        break;
    }
}