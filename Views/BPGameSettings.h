using namespace std;
#include "iostream"

#ifndef PROYECTO_II_CLIENT_CE2103__BPGAMESETTINGS_H
#define PROYECTO_II_CLIENT_CE2103__BPGAMESETTINGS_H

#include <SFML/Graphics.hpp>
#include "BPGame.h"

class BPGameSettings{
private:
    string player1 = "";
    string player2 = "";
    int playersPerteam = 0;
    int goalsTowin = 0;
public:
    int start(){
        int width = 1600;
        int height = 900;
        sf::RenderWindow window(sf::VideoMode(width, height), "BP Game Settings");

        sf::Texture background;
        if (!background.loadFromFile(
                "/home/joseandres216/Escritorio/Jose Andres/TEC/Semestre V/Datos II/Proyecto II - Games/Client/Proyecto_II_Client_CE2103-/content/BPGameSettingsBackground.png"))
            return EXIT_FAILURE;
        sf::Sprite backgroundSprite(background);

        sf::Font font;
        if (!font.loadFromFile(
                "/home/joseandres216/Escritorio/Jose Andres/TEC/Semestre V/Datos II/Proyecto II - Games/Client/Proyecto_II_Client_CE2103-/Fonts/Ubuntu/Ubuntu-Regular.ttf")) {
            window.close();
        }

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::KeyReleased) {
                    if (event.key.code == sf::Keyboard::Enter) {
                        window.close();
                        BPGame *window = new BPGame();
                        window->start();
                    }
                }
                if (event.type == sf::Event::KeyReleased) {
                    if (event.key.code == sf::Keyboard::Escape) {
                        window.close();
                    }
                }
                if (event.type == sf::Event::Closed)
                    window.close();
            }
            window.clear();
            window.draw(backgroundSprite);
            window.display();
        }
    }
};

#endif //PROYECTO_II_CLIENT_CE2103__BPGAMESETTINGS_H
