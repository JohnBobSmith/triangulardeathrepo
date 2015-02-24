#include "TDGameEngine.hpp"
#include <iostream>

sf::Texture TDGameEngine::load_texture_from_disk(std::string path)
{
    sf::Texture tempTexture;
    if(!tempTexture.loadFromFile(path.c_str())) {
        std::cout << "File " << path.c_str() << " cannot be found!";
    }

    return tempTexture;
}
