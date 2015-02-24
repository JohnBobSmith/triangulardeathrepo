#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

class Player
{
    public:
        sf::Sprite playerSprite;

        Player();
        void handle_keyboard_input(sf::Event event);
        void move_player();

    private:
        sf::Texture playerTexture;
        sf::Vector2f playerVector2f;
        sf::Vector2f gravity;
        sf::FloatRect playerBoundingBox;

        float playerVelocity = 0.1;
        float playerMaxVelocity = 0.5;
        float playerJumpHeight = 6.5;
        bool isGrounded = false;
};

#endif // PLAYER_H
