#ifndef PROYECTO_II_CLIENT_CE2103__BPGAMESETTINGS_H
#define PROYECTO_II_CLIENT_CE2103__BPGAMESETTINGS_H

#include <SFML/Graphics.hpp>
#include "BPGame.h"

class BPGameSettings{
public:
    int start(){
        int width = 1600;
        int height = 900;
        sf::RenderWindow window(sf::VideoMode(width, height), "BP Game Settings");

        sf::Font font;
        if (!font.loadFromFile(
                "/home/joseandres216/Escritorio/Jose Andres/TEC/Semestre V/Datos II/Proyecto II - Games/Client/Proyecto_II_Client_CE2103-/Fonts/Games/Games-Italic.ttf")) {
            window.close();
        }

        sf::Text text;
        text.setFont(font);
        text.setString("BPGame Settings Window");
        text.setCharacterSize(50);
        text.setFillColor(sf::Color::Red);
        text.setOutlineColor(sf::Color::White);
        text.setOutlineThickness(5);
        text.setPosition(100, 100);

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::KeyReleased) {
                    if (event.key.code == sf::Keyboard::Escape) {
                        window.close();
                    }
                }
                if (event.type == sf::Event::KeyReleased) {
                    if (event.key.code == sf::Keyboard::A) {
                        window.close();
                        BPGame *window = new BPGame();
                        window->start();
                    }
                }
            }
            window.clear();
            window.draw(text);
            window.display();
        }
    }
private:
};

#endif //PROYECTO_II_CLIENT_CE2103__BPGAMESETTINGS_H
