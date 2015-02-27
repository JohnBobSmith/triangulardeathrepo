#ifndef GAMEOBJECTBASE_H
#define GAMEOBJECTBASE_H

#include <SFML/Graphics.hpp>

class GameObject
{
    public:
        typedef struct GameObjectBase
        {
            sf::Texture objectTexture;
            sf::Vector2f objectPosition;
            sf::Sprite objectSprite;

        } gameObjectBase;
};

#endif // GAMEOBJECTBASE_H
