#include "Cell.h"

void Cell::setState(const bool& state) {
    m_state = state; 
    if(m_state)
        m_square.setFillColor(sf::Color(255, 255, 255));
    else
        m_square.setFillColor(sf::Color(0, 0, 0));

}

const bool& Cell::getState() {
    return m_state;
}

void Cell::setPosition(const sf::Vector2f& position) {
    m_square.setPosition(position);
}

void Cell::setSize(const float& size) {
    m_square.setSize(sf::Vector2f(size, size)); 
}

void Cell::draw(sf::RenderTarget& renderer) {
    renderer.draw(m_square);
}
