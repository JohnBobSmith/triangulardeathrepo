#include "PropPlatform.hpp"
#include "TDGameEngine.hpp"

PropPlatform::PropPlatform()
{
    TDGameEngine tdgameengine;

    platformStorage.resize(maxPlatforms);
    platformTexture = tdgameengine.load_texture_from_disk("textures/platform.png");

    for(int i = 0; i < maxPlatforms; i++){
        platformStorage[i] = new gameObjectBase;
    }
}

PropPlatform::~PropPlatform()
{
    for(int i = 0; i < maxPlatforms; i++){
        delete platformStorage[i];
    }
}

void PropPlatform::create_platform()
{
    for(int i = 0; i < maxPlatforms; i++){
        platformStorage[i]->objectTexture = platformTexture;
        platformStorage[i]->objectPosition.x = 250;
        platformStorage[i]->objectPosition.y = 250;
        platformStorage[i]->objectSprite.setPosition(platformStorage[i]->objectPosition);
        platformStorage[i]->objectSprite.setTexture(platformStorage[i]->objectTexture);
        platformBoundingBox = platformStorage[0]->objectSprite.getGlobalBounds();
    }
}

