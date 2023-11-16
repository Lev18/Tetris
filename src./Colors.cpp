#include "Colors.h"
#include <SFML/Graphics.hpp>

const sf::Color darkGrey = {26, 31, 40, 225};
const sf::Color green = {47, 230, 23, 255};
const sf::Color red = {232, 18, 18, 255};
const sf::Color orange = {226, 116, 17, 255};
const sf::Color yellow = {237, 234, 4, 255};
const sf::Color purple = {166, 0, 247, 255};
const sf::Color cyan = {21, 204, 209, 255};
const sf::Color blue = {13, 64, 216, 255};
const sf::Color lightBlue = {173, 216, 230};

std::vector<sf::Color> get_cell_color() {
   return std::vector<sf::Color> {darkGrey, green, red, orange, yellow, purple, cyan, blue};
}
