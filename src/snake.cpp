#include "snake.h"
#include "board.h"

// Definition of the Snake class methods

Snake::Direction Snake::get_direction() const {
    return current_direction;
}

const std::deque<Coord>& Snake::get_body() const{
    return body;
}

Snake::Snake(std::size_t width, std::size_t height){
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

void Snake::change_direction(Direction dir){
    // Prevent 180° turn
    if ((current_direction == Direction::UP && dir == Direction::DOWN) ||
        (current_direction == Direction::DOWN && dir == Direction::UP) ||
        (current_direction == Direction::LEFT && dir == Direction::RIGHT) ||
        (current_direction == Direction::RIGHT && dir == Direction::LEFT)) {
        return;
    }
    current_direction = dir;
}

bool Snake::move(const Board& board, const Food& food){
    // Calculate new head position
    Coord head = body.front();
    Coord new_head = head;
    switch (current_direction) {
        case Direction::UP:    new_head.y -= 1; break;
        case Direction::DOWN:  new_head.y += 1; break;
        case Direction::LEFT:  new_head.x -= 1; break;
        case Direction::RIGHT: new_head.x += 1; break;
    }

    // Check wall collision
    if (board.is_wall(new_head.x, new_head.y)) {
        return false; // died
    }

    // Check self‑collision (excluding the tail if we are not eating)
    bool ate = (new_head.x == food.get_position().x &&
                new_head.y == food.get_position().y);
    std::size_t check_end = ate ? body.size() : body.size() - 1;
    for (std::size_t i = 0; i < check_end; ++i) {
        if (body[i].x == new_head.x && body[i].y == new_head.y) {
            return false; // died
        }
    }

    // Insert new head
    body.push_front(new_head);

    // Remove tail if not eating
    if (!ate) {
        body.pop_back();
    }

    return true; // alive
}
