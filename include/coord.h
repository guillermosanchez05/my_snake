
/**
 * @brief Types that Coord can have: EMPTY, SNAKE or FOOD
 */
typedef enum {
    EMPTY,
    SNAKE,
    FOOD
} CoordType;

/**
 * @brief Struct to represent a coordinate in the board,
 * it has an 'x' value, 'y' value and CoordType 'type'.
 */
struct Coord{
    int x;
    int y;
    CoordType type;
};

/**
 * @brief Gets the char associated to a Coord coordinate
 * '█' for Snake, '●' for Food and ' ' for empty.
 * 
 * @param coordinate The coordinate whose type will be converted to a character.
 * @return Char associated to the type.
 */
char getPointChar(Coord coordinate);
