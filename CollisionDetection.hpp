#ifndef COLLISIONDETECTION_H
#define COLLISIONDETECTION_H

#include <SFML/Graphics.hpp>

class CollisionDetection
{
    public:
        bool check_collision(sf::FloatRect rectA, sf::FloatRect rectB);
        bool isXAxisColliding = false;
        bool isYAxisColliding = false;
};

#endif // COLLISIONDETECTION_H
