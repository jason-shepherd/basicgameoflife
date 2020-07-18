#include "Game.h"

Game::Game()
    : m_window({1920, 1080}, "Conway's Game of Life")
{
    m_window.setFramerateLimit(0);
    m_gridSize = {m_window.getSize().x / m_cellWidth, m_window.getSize().y / m_cellWidth};
    m_cells.resize(m_gridSize.x * m_gridSize.y);
    m_cellsBuffer.resize(m_gridSize.x * m_gridSize.y);
    m_cellVertices.resize(m_cells.size() * 4);

    std::srand(std::time(NULL));
}

void Game::run() {
    initCells();
    while(m_window.isOpen()) {
        handleEvents();

        m_window.clear();
        update();
        m_window.draw(&m_cellVertices[0], m_cellVertices.size(), sf::Quads);
        m_window.display();
    }
}

void Game::update() {
     m_cellsBuffer = m_cells;

    for(int i = 0; i < m_gridSize.x; i++) {
        for(int j = 0; j < m_gridSize.y; j++) {
            int liveNeighbors = 0;
            for(int x = i - 1; x <= i + 1; x++) {
                for(int y = j - 1; y <= j + 1; y++) {
                    if(x >= 0 && x < m_gridSize.x && y >= 0 && y < m_gridSize.y && !(x == i && y == j) && m_cells[coordsToIndex(x, y)])
                        liveNeighbors++;
                }
            }

            int index = coordsToIndex(i, j);
            bool state = m_cells[index];
            if(liveNeighbors == 3 || (state && liveNeighbors == 2)) 
                setCellState(index, true);
            else
                setCellState(index, false);
        }
    }
    m_cells.swap(m_cellsBuffer);
}

void Game::initCells() {
   for(int i = 0; i < m_gridSize.x; i++) {
        for(int j = 0; j < m_gridSize.y; j++) {
            int index = coordsToIndex(i, j) * 4;
            m_cellVertices[index  ].position = sf::Vector2f(i * m_cellWidth,               j * m_cellWidth);
            m_cellVertices[index+1].position = sf::Vector2f(i * m_cellWidth + m_cellWidth, j * m_cellWidth);
            m_cellVertices[index+2].position = sf::Vector2f(i * m_cellWidth + m_cellWidth, j * m_cellWidth + m_cellWidth);
            m_cellVertices[index+3].position = sf::Vector2f(i * m_cellWidth,               j * m_cellWidth + m_cellWidth);
            m_cells[index/4] = bool(std::rand() % 2);
        }
   }
}

void Game::setCellState(int index, bool state) {
    m_cellsBuffer[index] = state;
    for(int i = 0; i < 4; i++) {
        m_cellVertices[index * 4 + i].color = state ? sf::Color::White : sf::Color::Black;
    }
}

int Game::coordsToIndex(int& x, int& y) {
    return y * m_gridSize.x + x;
}

sf::Vector2f Game::indexToCoords(int& index) {
    return sf::Vector2f(index % m_gridSize.x, index / m_gridSize.x);
}

void Game::handleEvents() {
    sf::Event event;
    while(m_window.pollEvent(event)) {
        if(event.type == sf::Event::Closed)
            m_window.close();
    }
}
