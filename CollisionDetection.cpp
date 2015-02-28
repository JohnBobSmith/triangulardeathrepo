#include "CollisionDetection.hpp"

bool CollisionDetection::check_collision(sf::FloatRect rectA, sf::FloatRect rectB)
{
    float leftA, leftB;
    float rightA, rightB;
    float topA, topB;
    float bottomA, bottomB;

    leftA = rectA.left;
    rightA = rectA.left + rectA.width;
    topA = rectA.top;
    bottomA = rectA.top + rectA.height;

    leftB = rectB.left;
    rightB = rectB.left + rectB.width;
    topB = rectB.top;
    bottomB = rectB.top + rectB.height;

    if(bottomA <= topB){
        isYAxisColliding = false;
        return false;
    } else {
        isYAxisColliding = true;
    }

    if(topA >= bottomB){
        isYAxisColliding = false;
        return false;
    } else {
        isYAxisColliding = true;
    }

    if(rightA <= leftB){
        isXAxisColliding = false;
        return false;
    } else {
        isXAxisColliding = true;
    }

    if(leftA >= rightB){
        isXAxisColliding = false;
        return false;
    } else {
        isXAxisColliding = true;
    }

    return true;
}
