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
}

void Player::handle_keyboard_input(sf::Event event)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        playerVector2f.x += playerVelocity;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        playerVector2f.x -= playerVelocity;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        playerVector2f.y += playerVelocity;
    }

    if(event.type == sf::Event::KeyPressed){
        if(event.key.code == sf::Keyboard::Up){
            playerVector2f.y -= playerJumpHeight;
        }
    }
}

void Player::move_player(sf::Time elapsedTime)
{
    CollisionDetection collisiondetection;
    PropTriangle proptriangle;
    PropPlatform propplatform;

    float accelerationDueToGravity;

    accelerationDueToGravity = gravity / elapsedTime.asSeconds();
    playerVector2f.y += gravity;

    playerBoundingBox = playerSprite.getGlobalBounds();

    if(collisiondetection.check_collision(playerBoundingBox, propplatform.platformBoundingBox)){
        playerVector2f -= playerVector2f;
    }

    playerSprite.move(playerVector2f);
}
