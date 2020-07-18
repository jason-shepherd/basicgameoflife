#include "Game.h"

Game::Game(int cellWidth, sf::VideoMode windowMode, uint32_t windowStyle)
    : m_window(windowMode, "Conway's Game of Life", windowStyle), m_cellWidth(cellWidth) 
{
    //Init and size the grid of cells and their vertices
    m_gridSize = {windowMode.width / m_cellWidth, windowMode.height / m_cellWidth};
    m_cells.resize(m_gridSize.x * m_gridSize.y);
    m_cellsBuffer.resize(m_gridSize.x * m_gridSize.y);
    m_cellVertices.resize(m_gridSize.x * m_gridSize.y * 4);

    //Seed the pseudo random generator on time
    std::srand(std::time(NULL));
}

void Game::run() {
    initCells();

    //Main game loop
    while(m_window.isOpen()) {
        handleEvents();
        update();

        //Draw the array of vertices
        m_window.clear();
        m_window.draw(&m_cellVertices[0], m_cellVertices.size(), sf::Quads);
        m_window.display();
    }
}

void Game::initCells() {
   //Position the cell vertices, there might be a slightly better way to do this 
   for(int i = 0; i < m_gridSize.x; i++) {
        for(int j = 0; j < m_gridSize.y; j++) {
            int index = coordsToIndex(i, j);
            m_cellVertices[index*4  ].position = sf::Vector2f(i * m_cellWidth,               j * m_cellWidth);
            m_cellVertices[index*4+1].position = sf::Vector2f(i * m_cellWidth + m_cellWidth, j * m_cellWidth);
            m_cellVertices[index*4+2].position = sf::Vector2f(i * m_cellWidth + m_cellWidth, j * m_cellWidth + m_cellWidth);
            m_cellVertices[index*4+3].position = sf::Vector2f(i * m_cellWidth,               j * m_cellWidth + m_cellWidth);

            //Assign the cell a pseudo random state
            m_cells[index] = bool(std::rand() % 2);
        }
   }
}

void Game::update() {
     m_cellsBuffer = m_cells;

    //Loop through all the cells and apply game logic
    for(int i = 0; i < m_gridSize.x; i++) {
        for(int j = 0; j < m_gridSize.y; j++) {
            //Determine number of live neighbors. That if statement is messy, I know.
            int liveNeighbors = 0;
            for(int x = i - 1; x <= i + 1; x++) {
                for(int y = j - 1; y <= j + 1; y++) {
                    if(x >= 0 && x < m_gridSize.x && y >= 0 && y < m_gridSize.y && !(x == i && y == j) && m_cells[coordsToIndex(x, y)])
                        liveNeighbors++;
                }
            }
            
            //Apply game rules
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

void Game::setCellState(int& index, bool state) {
    //Simple function to change the color of the cell vertices and the state in the buffer
    m_cellsBuffer[index] = state;
    for(int i = 0; i < 4; i++) {
        m_cellVertices[index * 4 + i].color = state ? sf::Color::White : sf::Color::Black;
    }
}

int Game::coordsToIndex(int& x, int& y) {
    return y * m_gridSize.x + x;
}

void Game::handleEvents() {
    sf::Event event;
    while(m_window.pollEvent(event)) {
        if(event.type == sf::Event::Closed)
            m_window.close();
    }
}
