/**
 * @brief Struct to represent a coordinate in the board,
 * it has an 'x' value, 'y' value and CoordType 'type'.
 */
struct Coord{
    int x;
    int y;
};

/**
 * @brief Gets the char associated to a Coord coordinate so it can be
 * represented: '█' for Snake, '●' for Food and ' ' for empty.
 * 
 * @param coordinate The coordinate whose type will be converted to a character.
 * @return Char associated to the type.
 */
char getPointChar(Coord coordinate);
