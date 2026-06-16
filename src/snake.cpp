#include "snake.h"

// Definition of the Snake class methods

Snake::Direction Snake::get_direction() const {
    return current_direction;
}

const std::deque<Coord>& Snake::get_body() const{
    return body;
}

void Snake::init(std::size_t width, std::size_t height){
    // Clear its body in case it was already initialized
    body.clear();

    // Establish the direction to right
    current_direction = Direction::RIGHT;

    // Establish the centered position
    int startX = static_cast<int>(width/2);
    int startY = static_cast<int>(height/2);

    // Place the 3 initial Coords
    body.push_back(Coord{startX, startY});
    body.push_back(Coord{startX - 1, startY});
    body.push_back(Coord{startX - 2, startY});

}
