#include "CollisionDetection.hpp"

bool CollisionDetection::check_collision(sf::FloatRect rectA, sf::FloatRect rectB)
{
    float rectATop, rectBTop;
    float rectABottom, rectBBottom;
    float rectALeft, rectBLeft;
    float rectARight, rectBRight;

    rectATop = rectA.top;
    rectABottom = rectA.top + rectA.height;
    rectALeft = rectA.left;
    rectARight = rectA.left + rectA.width;

    rectBTop = rectB.top;
    rectBBottom = rectB.top + rectB.height;
    rectBLeft = rectB.left;
    rectBRight = rectB.left + rectB.width;

    if(rectABottom <= rectBTop){
        return false;
    }

    if(rectATop >= rectBBottom){
        return false;
    }

    if(rectARight <= rectBLeft){
        return false;
    }

    if(rectALeft >= rectBRight){
        return false;
    }

    return true;
}
