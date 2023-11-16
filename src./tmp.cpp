#include <SFML/Graphics.hpp>
#include <cmath>

void drawRoundedRectangle(sf::RenderWindow& window, float x, float y, float width, float height, float cornerRadius, const sf::Color& color) {
    sf::VertexArray vertices(sf::Quads, 16);

    for (int i = 0; i < 4; ++i) {
        float angle1 = i * 90.f * 3.14159265358979323846f / 180.f;
        float angle2 = (i + 1) * 90.f * 3.14159265358979323846f / 180.f;

        float xOffset = i % 2 == 0 ? -cornerRadius : 0;
        float yOffset = i < 2 ? -cornerRadius : 0;

        for (int j = 0; j < 4; ++j) {
            float xCos = std::cos(angle1);
            float xSin = std::sin(angle1);
            float yCos = std::cos(angle2);
            float ySin = std::sin(angle2);

            float xPos = xOffset + (j % 2 == 0 ? width - cornerRadius : width);
            float yPos = yOffset + (j < 2 ? height - cornerRadius : height);

            vertices[i * 4 + j].position.x = x + xCos * xPos - xSin * yPos;
            vertices[i * 4 + j].position.y = y + xSin * xPos + xCos * yPos;
            vertices[i * 4 + j].color = color;
        }
    }

    window.draw(vertices);
}

int main() {
    sf::RenderWindow window(sf::VideoMode(400, 300), "Rounded Rectangle");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();

        drawRoundedRectangle(window, 50, 50, 300, 200, 20, sf::Color::Green);

        window.display();
    }

    return 0;
}

