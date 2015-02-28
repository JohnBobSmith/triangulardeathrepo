#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <vector>

class Player
{
    public:
        sf::Sprite playerSprite;

        Player();
        void handle_keyboard_input(sf::Event event);
        void move_player(sf::Time elapsedTime);

    private:
        sf::Texture playerTexture;
        sf::Vector2f playerVector2f;
        sf::FloatRect playerBoundingBox;

        const float gravity = 0.05;
        float playerVelocity = 0.1;
        float playerJumpHeight = 3.25;
        bool isGrounded;
};

#endif // PLAYER_H
