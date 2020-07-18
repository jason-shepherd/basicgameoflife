#include "Game.h"

int main() {
    Game life(5, {1920, 1080}, sf::Style::Fullscreen);
    life.run();
}
