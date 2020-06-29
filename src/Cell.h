#include "SFML/Graphics/RenderTarget.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

class Cell {
    private:
        sf::Vector2f m_position;
        bool m_state = false;
        int m_neighbors;
    public:
        sf::RectangleShape m_square;
        void setState(const bool& state);
        const bool& getState();
        void setPosition(const sf::Vector2f& position);
        void setSize(const sf::Vector2f& size);
        void draw(sf::RenderTarget& renderer);
};
