#ifndef PROYECTO_II_CLIENT_CE2103__BPGAME_H
#define PROYECTO_II_CLIENT_CE2103__BPGAME_H

#include <SFML/Graphics.hpp>

class BPGame{
public:
    int start(){
        int width = 1600;
        int height = 900;
        sf::RenderWindow window(sf::VideoMode(width, height), "BP Game");

        sf::Font font;
        if (!font.loadFromFile(
                "/home/joseandres216/Escritorio/Jose Andres/TEC/Semestre V/Datos II/Proyecto II - Games/Client/Proyecto_II_Client_CE2103-/Fonts/Games/Games-Italic.ttf")) {
            window.close();
        }

        sf::Text text;
        text.setFont(font);
        text.setString("BPGame Window");
        text.setCharacterSize(50);
        text.setFillColor(sf::Color::Red);
        text.setOutlineColor(sf::Color::White);
        text.setOutlineThickness(5);
        text.setPosition(100, 100);

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
            }
            window.clear();
            window.draw(text);
            window.display();
        }
    }
private:
};

#endif //PROYECTO_II_CLIENT_CE2103__BPGAME_H
