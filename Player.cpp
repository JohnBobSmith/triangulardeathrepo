#include "Player.hpp"
#include "TDGameEngine.hpp"
#include "CollisionDetection.hpp"
#include "PropTriangle.hpp"
#include "PropPlatform.hpp"

Player::Player()
{
    TDGameEngine tdgameengine;

    playerTexture = tdgameengine.load_texture_from_disk("textures/player.png");
    playerSprite.setTexture(playerTexture);
    playerSprite.setPosition(100, 300);

    playerBoundingBox = playerSprite.getGlobalBounds();

    gravity.x = 0;
    gravity.y = 9.81;
}

void Player::handle_keyboard_input(sf::Event event)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        playerVector2f.x += playerVelocity * playerMaxVelocity;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        playerVector2f.x -= playerVelocity * playerMaxVelocity;
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

    playerSprite.move(gravity);
}
