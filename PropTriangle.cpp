#include "PropTriangle.hpp"

PropTriangle::PropTriangle()
{
    triangle.setRadius(50);
    triangle.setPointCount(3);
    triangle.setFillColor(sf::Color::Red);

    triangle.setPosition(50, 50);
    triangleRect = triangle.getGlobalBounds();
}
