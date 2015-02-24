#include "TDGameEngine.hpp"
#include "Player.hpp"
#include "PropTriangle.hpp"
#include "PropPlatform.hpp"

int main()
{
    Player player;
    PropTriangle proptriangle;
    PropPlatform propplatform;

    int screenWidth = 800;
    int screenHeight = 600;

    sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Triangular Death");
    sf::Event event;

    window.setFramerateLimit(60);
    window.setKeyRepeatEnabled(false);

    propplatform.create_platform();

    while(window.isOpen()){
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            }
            player.handle_keyboard_input(event);
        }

        window.clear(sf::Color::Black);

        player.move_player();

        window.draw(player.playerSprite);
        window.draw(proptriangle.triangle);
        window.draw(propplatform.platformStorage[0].object);

        window.display();
    }
}