#include "Game.h"

Game::Game() 
    : m_window({1920, 1080}, "Conway's Game of Life")
{
    m_windowSize = m_window.getSize();
    m_window.setFramerateLimit(10);

    m_cells.resize(m_windowSize.x / 10, std::vector<Cell>(m_windowSize.y / 10));
    std::srand(std::time(NULL));
    initCells();
}

void Game::run() {
    while(m_window.isOpen()) {
        handleEvent();
        m_window.clear();
        updateCells();
        m_window.display();
    }
}

void Game::initCells() {
    for(int i = 0; i < m_cells.size(); i++) {
        for(int j = 0; j < m_cells[i].size(); j++) {
            m_cells[i][j].setPosition({i*10.0f, j*10.0f});
            m_cells[i][j].setSize({10, 10});
            m_cells[i][j].setState(bool(std::rand() % 2));
            m_cells[i][j].draw(m_window);
        }
    }
}

void Game::updateCells() {
    std::vector<std::vector<Cell>>buffer(m_cells);
    for(int i = 0; i < m_cells.size(); i++) {
        for(int j = 0; j < m_cells[i].size(); j++) {
            int liveNeighbors = getLiveNeighbors(i, j);
            bool state = m_cells[i][j].getState();

            if(state && liveNeighbors == 2 || liveNeighbors == 3)
                buffer[i][j].setState(true);
            else if(!state && liveNeighbors == 3)
                buffer[i][j].setState(true);
            else
                buffer[i][j].setState(false);
            buffer[i][j].draw(m_window);
        }
    }
    m_cells.swap(buffer);
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
