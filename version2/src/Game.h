#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>

class Game {
    private:
        sf::RenderWindow m_window;

        int m_cellWidth;
        std::vector<bool> m_cells;
        std::vector<bool> m_cellsBuffer;
        std::vector<sf::Vertex> m_cellVertices;
        sf::Vector2u m_gridSize;

        void initCells();
        void update();
        void setCellColor(int& index, sf::Color color);
        int coordsToIndex(int& x, int& y);
        void handleEvents();
    public:
        Game(int cellWidth, sf::VideoMode windowMode, uint32_t windowSettings = sf::Style::Default);
        void run();
};
