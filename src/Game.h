#include <vector>
#include <cstdlib>
#include <ctime>

#include "Cell.h"

class Game {
    public:
        Game();
        void run();

    private:
        sf::RenderWindow m_window;
        sf::Vector2u m_windowSize;
        std::vector<std::vector<Cell>> m_cells;

        void handleEvent();
        void initCells();
        void updateCells();
        int getLiveNeighbors(int& x, int& y);
};
