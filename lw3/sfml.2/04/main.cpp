#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
//#include <SFML/System.hpp>
#include <cmath>
//#include <iostream>

constexpr unsigned WINDOW_WIDTH = 800;
constexpr unsigned WINDOW_HEIGHT = 600;

int main()
{
    constexpr int pointCount = 40; //Change this parameter to get circle made of angles
    constexpr float circleRadius = 200;

    sf::RenderWindow window(sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), "Circle");

    sf::ConvexShape shape;
    shape.setPosition({400, 320});
    shape.setFillColor(sf::Color(0xFF, 0xFF, 0xFF));

    shape.setPointCount(pointCount);
    for (int pointNo = 0; pointNo < pointCount; ++pointNo)
    {
        float angle = float(2 * M_PI * pointNo) / float(pointCount);
        sf::Vector2f point = sf::Vector2f{
            circleRadius * std::sin(angle),
            circleRadius * std::cos(angle)};
        shape.setPoint(pointNo, point);
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        // Рисование текущего состояния
        window.clear();
        window.draw(shape);
        window.display();
    }
}