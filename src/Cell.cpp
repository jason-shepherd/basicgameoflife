#include "Cell.h"

void Cell::setState(const bool& state) {
    m_state = state;
}

const bool& Cell::getState() {
    return m_state;
}

void Cell::setPosition(const sf::Vector2f& position) {
    m_position = position;
    m_square.setPosition(m_position);
}

void Cell::setSize(const sf::Vector2f& size) {
    m_square.setSize(size); 
}

void Cell::draw(sf::RenderTarget& renderer) {
    if(m_state)
        m_square.setFillColor(sf::Color(255, 255, 255));
    else
        m_square.setFillColor(sf::Color(0, 0, 0));

    renderer.draw(m_square);
}
