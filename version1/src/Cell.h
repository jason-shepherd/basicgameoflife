#include <SFML/Graphics.hpp>
#include <iostream>

class Cell {
    private:
        bool m_state = false;
        sf::RectangleShape m_square;

    public:
        void setState(const bool& state);
        const bool& getState();
        void setPosition(const sf::Vector2f& position);
        void setSize(const float& size);
        void draw(sf::RenderTarget& vertices);
};
