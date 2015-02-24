#ifndef PROPPLATFORM_H
#define PROPPLATFORM_H

#include <SFML/Graphics.hpp>
#include "GameObjectBase.hpp"
#include <vector>

class PropPlatform : public GameObject
{
    public:
        PropPlatform();
        void create_platform();
        std::vector<gameObjectBase> platformStorage;

    private:
        gameObjectBase platform;
        sf::Texture platformTexture;

};

#endif // PROPPLATFORM_H
