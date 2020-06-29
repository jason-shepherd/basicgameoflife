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

        float m_cellWidth = 5.0f;
        std::vector<std::vector<Cell>> m_cells;
        std::vector<std::vector<Cell>> m_cellsBuffer;

        void handleEvent();
        void initCells();
        void updateCells();
        int getLiveNeighbors(int& x, int& y);
};
