#ifndef TDGAMEENGINE_H
#define TDGAMEENGINE_H

#include <SFML/Graphics.hpp>
#include <string>

class TDGameEngine
{
    public:
        sf::Texture load_texture_from_disk(std::string path);
};

#endif // TDGAMEENGINE_H
