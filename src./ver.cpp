#include <SFML/Graphics.hpp>
#include <vector>

class Grid {
public:
    Grid(int cellSize, int rows, int columns) : cellSize(cellSize), rows(rows), columns(columns) {
        rectangles.resize(rows * columns);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                rectangles[i * columns + j].setSize(sf::Vector2f(cellSize, cellSize));
                rectangles[i * columns + j].setPosition(j * cellSize, i * cellSize);
                if ((i + j) % 2 == 0) {
                    rectangles[i * columns + j].setFillColor(color1);
                } else {
                    rectangles[i * columns + j].setFillColor(color2);
                }
            }
        }
    }

    void draw(sf::RenderWindow &window) {
        for (auto &rectangle : rectangles) {
            window.draw(rectangle);
        }
    }

private:
    std::vector<sf::RectangleShape> rectangles;
    int cellSize;
    int rows;
    int columns;
    sf::Color color1 = sf::Color::White; // Change to the first color
    sf::Color color2 = sf::Color::Black; // Change to the second color
};

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Lattice Board");
    int cellSize = 50; // Size of each cell
    int rows = window.getSize().y / cellSize;
    int columns = window.getSize().x / cellSize;

    Grid grid(cellSize, rows, columns);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();
        grid.draw(window);
        window.display();
    }

    return 0;
}

