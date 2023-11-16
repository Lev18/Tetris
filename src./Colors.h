#ifndef  COLOR_H
#define COLOR_H

#include <SFML/Graphics.hpp>

extern const sf::Color darkGrey;
extern const sf::Color green;
extern const sf::Color red;
extern const sf::Color orange;
extern const sf::Color yellow;
extern const sf::Color purple;
extern const sf::Color cyan;
extern const sf::Color blue;
extern const sf::Color lightBlue;

std::vector<sf::Color> get_cell_color();

#endif
