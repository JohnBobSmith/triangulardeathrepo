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

    if(leftA <= rightB){
        return false;
    }

    if(rightA >= leftB){
        return false;
    }

    if(topA >= bottomB){
        return false;
    }

    if(bottomA <= topB){
        return false;
    }

    return true;
}
