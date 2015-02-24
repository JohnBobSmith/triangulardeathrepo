#ifndef GAMEOBJECTBASE_H
#define GAMEOBJECTBASE_H

#include <SFML/Graphics.hpp>
#include <vector>

class GameObject
{
    public:
        typedef struct GameObjectBase
        {
            sf::Texture objectTexture;
            sf::Vector2f objectPosition;
            sf::FloatRect objectBoundingBox;
            sf::Sprite object;

        } gameObjectBase;
};

#endif // GAMEOBJECTBASE_H
