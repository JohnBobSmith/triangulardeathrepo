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
    sf::Clock clock;

    window.setFramerateLimit(60);
    window.setKeyRepeatEnabled(false);

    while(window.isOpen()){
        sf::Time elapsed = clock.restart();
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            }
            player.handle_keyboard_input(event);
        }

        window.clear(sf::Color::Black);
        player.move_player(elapsed);
        window.draw(player.playerSprite);
        window.draw(proptriangle.triangle);

        for(int i = 0; i < propplatform.maxPlatforms; i++){
            window.draw(propplatform.platformStorage[i]->objectSprite);
        }

        window.display();
    }
}
