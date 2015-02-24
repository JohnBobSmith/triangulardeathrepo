#include "PropPlatform.hpp"
#include "TDGameEngine.hpp"

PropPlatform::PropPlatform()
{
    TDGameEngine tdgameengine;

    platformStorage.resize(1);
    platformTexture = tdgameengine.load_texture_from_disk("textures/platform.png");
}

void PropPlatform::create_platform()
{
    platform.objectTexture = platformTexture;
    platform.objectPosition.x = 250;
    platform.objectPosition.y = 250;
    platform.object.setTexture(platform.objectTexture);
    platform.object.setPosition(platform.objectPosition);
    platform.objectBoundingBox = platform.object.getGlobalBounds();

    platformStorage[0] = platform;
}

