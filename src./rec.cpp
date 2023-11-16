#include <SFML/Graphics.hpp>
#include <math.h>
#define POINTS 5

void RoundRect(sf::ConvexShape& rrect,float x, float y, float rectHeight, float rectWidth, float radius) {
  float X = 0, Y = 0;
	for(int i = 0; i < POINTS; i++) {
		X += radius / POINTS;
		Y = sqrt(radius * radius - X * X);
		rrect.setPoint(i, sf::Vector2f(X + x + rectWidth-radius, y - Y + radius));
	}

	Y=0;
	for(int i = 0; i < POINTS; i++)
	{
		Y += radius / POINTS;
		X = sqrt(radius * radius - Y * Y);
		rrect.setPoint(i + POINTS, sf::Vector2f(x + rectWidth + X-radius, y + rectHeight - radius+ Y));
	}

	X=0;
	for(int i=0; i < POINTS; i++)
	{
		X += radius / POINTS;
		Y = sqrt(radius * radius - X * X);
		rrect.setPoint(i + 2 * POINTS, sf::Vector2f(x + radius - X, y + rectHeight - radius + Y));
	}

	Y=0;
	for(int i=0; i < POINTS; i++)
	{
		Y += radius / POINTS;
		X = sqrt(radius * radius - Y * Y);
		rrect.setPoint(i + 3 * POINTS , sf::Vector2f(x - X + radius, y + radius - Y));
	}
}

int main() {
    sf::RenderWindow window(sf::VideoMode(500, 620), "Rounded Rectangle");

  sf::ConvexShape roundedRectangle(4 * POINTS );
  RoundRect(roundedRectangle, 375, 10, 50, 70, 20.f);

  roundedRectangle.setFillColor(sf::Color::Cyan);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();
        window.draw(roundedRectangle);
        window.display();
    }

    return 0;
}

