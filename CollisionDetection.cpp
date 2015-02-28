#include "CollisionDetection.hpp"

bool CollisionDetection::check_collision(sf::FloatRect rectA, sf::FloatRect rectB)
{
    //I need to check collision only on one axis.
    //So what I've done is have 2 booleans, that
    //should be able to detect collision on one
    //axis, but this is not the case. Both boool's
    //become true using the current algorithm.

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
        return false;
    }

    if(topA >= bottomB){
        return false;
    }

    if(rightA <= leftB){
        return false;
    }

    if(leftA >= rightB){
        return false;
    }

    return true;
}
