#include "Game.h"

Game::Game() 
    : m_window({1920, 1080}, "Conway's Game of Life")
{
    m_windowSize = m_window.getSize();
    m_window.setFramerateLimit(0);

    m_cells.resize(m_windowSize.x / m_cellWidth, 
            std::vector<Cell>(m_windowSize.y / m_cellWidth));
    m_cellsBuffer.resize(m_windowSize.x / m_cellWidth, 
            std::vector<Cell>(m_windowSize.y / m_cellWidth));
    std::srand(std::time(NULL));
    initCells();
}

void Game::run() {
    sf::Clock clock;
    float lastTime = 0;
    while(m_window.isOpen()) {
        handleEvent();

        std::cout << 1.f / clock.getElapsedTime().asSeconds() << std::endl;
        clock.restart().asSeconds();

        m_window.clear();
        updateCells();
        m_window.display();
    }
}

void Game::initCells() {
    for(int i = 0; i < m_cells.size(); i++) {
        for(int j = 0; j < m_cells[i].size(); j++) {
            m_cells[i][j].setPosition({i*m_cellWidth, j*m_cellWidth});
            m_cells[i][j].setSize(m_cellWidth);
            m_cells[i][j].setState(bool(std::rand() % 2));
            m_cells[i][j].draw(m_window);
        }
    }
}

void Game::updateCells() {
    m_cellsBuffer = m_cells;
    for(int i = 0; i < m_cells.size(); i++) {
        for(int j = 0; j < m_cells[i].size(); j++) {
            int liveNeighbors = getLiveNeighbors(i, j);
            bool state = m_cells[i][j].getState();

            if(state && liveNeighbors == 2 || liveNeighbors == 3)
                m_cellsBuffer[i][j].setState(true);
            else if(!state && liveNeighbors == 3)
                m_cellsBuffer[i][j].setState(true);
            else
                m_cellsBuffer[i][j].setState(false);
            m_cellsBuffer[i][j].draw(m_window);
        }
    }
    m_cells.swap(m_cellsBuffer);
}

int Game::getLiveNeighbors(int& x, int& y) {
    int liveNeighbors = 0;
    for(int i = x-1; i <= x+1; i++) {
        for(int j = y-1; j <= y+1; j++) {
            if(i >= 0 && i < m_cells.size() && j >= 0 && j < m_cells[0].size()) {
                if(!(i == x && j == y)) {
                    if(m_cells[i][j].getState())
                        liveNeighbors++;
                }
            }
        }
    }
    return liveNeighbors;
}


void Game::handleEvent() {
    sf::Event event;
    while(m_window.pollEvent(event)) {
        if(event.type == sf::Event::Closed)
            m_window.close();
    }
}
