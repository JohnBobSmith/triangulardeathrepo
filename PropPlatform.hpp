#ifndef PROPPLATFORM_H
#define PROPPLATFORM_H

#include <SFML/Graphics.hpp>
#include "GameObjectBase.hpp"
#include <vector>

class PropPlatform : public GameObject
{
    public:
        const int maxPlatforms = 1;

        sf::FloatRect platformBoundingBox;
        std::vector<gameObjectBase*> platformStorage;

        PropPlatform();
        ~PropPlatform();

    private:
        sf::Texture platformTexture;

};

#endif // PROPPLATFORM_H
