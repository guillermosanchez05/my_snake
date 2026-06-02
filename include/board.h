#include <array>
#include <cstddef> // size_t

class Board {
    public:
        // Public constants so other classes can check them
        static constexpr std::size_t WIDTH = 64;
        static constexpr std::size_t HEIGHT = 64;

    private:

        // Characters to draw the actual board
        static constexpr char CHAR_EMPTY = ' ';
        static constexpr char CHAR_WALL = '#';
        static constexpr char CHAR_SNAKE = '█';
        static constexpr char CHAR_FOOD = '●';

        // The board is a 2D fixed-lenght array (defined in stack, vector -> heap)
        std::array<std::array<char, WIDTH>, HEIGHT> matrix;

    public: // methods
        void display();
};