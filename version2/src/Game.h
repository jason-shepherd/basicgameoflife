#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>

class Game {
    public:
        Game();
        void run();
    private:
        sf::RenderWindow m_window;
        std::vector<bool> m_cells;
        std::vector<bool> m_cellsBuffer;
        std::vector<sf::Vertex> m_cellVertices;
        int m_cellWidth = 3;
        sf::Vector2u m_gridSize;

        void update();
        void initCells();
        int coordsToIndex(int& x, int& y);
        sf::Vector2f indexToCoords(int& index);
        void setCellState(int index, bool state);
        void handleEvents();
};
