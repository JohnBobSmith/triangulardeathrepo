#include "Player.hpp"
#include "TDGameEngine.hpp"
#include "CollisionDetection.hpp"
#include "PropTriangle.hpp"
#include "PropPlatform.hpp"
#include <iostream>

Player::Player()
{
    TDGameEngine tdgameengine;
    PropPlatform propplatform;

    playerTexture = tdgameengine.load_texture_from_disk("textures/player.png");
    playerSprite.setTexture(playerTexture);
    playerSprite.setPosition(250, 0);

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

    playerBoundingBox = playerSprite.getGlobalBounds();

    playerSprite.move(playerVector2f);

    if(collisiondetection.check_collision(playerBoundingBox, propplatform.platformBoundingBox)){
        std::cout << "Collision detected!!!" << std::endl;
        playerVector2f -= playerVector2f;
    }
}
