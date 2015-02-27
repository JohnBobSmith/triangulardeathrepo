#include "Player.hpp"
#include "TDGameEngine.hpp"
#include "CollisionDetection.hpp"
#include "PropTriangle.hpp"
#include "PropPlatform.hpp"
#include <iostream>

Player::Player()
{
    TDGameEngine tdgameengine;

    playerTexture = tdgameengine.load_texture_from_disk("textures/player.png");
    playerSprite.setTexture(playerTexture);
    playerSprite.setPosition(250, 0);

    playerBoundingBox = playerSprite.getGlobalBounds();

    gravity.x = 0;
    gravity.y = 1.905;
}

void Player::handle_keyboard_input(sf::Event event)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        playerVector2f.x += playerVelocity * playerMaxVelocity;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        playerVector2f.x -= playerVelocity * playerMaxVelocity;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        playerVector2f.y += playerVelocity * playerMaxVelocity;
    }

    if(event.type == sf::Event::KeyPressed){
        if(event.key.code == sf::Keyboard::Up){
            playerVector2f.y -= playerJumpHeight;
        }
    }
}

void Player::move_player()
{
    CollisionDetection collisiondetection;
    PropTriangle proptriangle;
    PropPlatform propplatform;

    playerSprite.move(playerVector2f);

    //std::cout << propplatform.platformBoundingBox.width << " " << propplatform.platformBoundingBox.height << std::endl;
    std::cout << playerBoundingBox.width << " " << playerBoundingBox.height << std::endl;

    if(collisiondetection.check_collision(playerBoundingBox, propplatform.platformBoundingBox)){
        std::cout << "Collision detected!!!" << std::endl;
        playerVector2f -= playerVector2f;
    }
}
