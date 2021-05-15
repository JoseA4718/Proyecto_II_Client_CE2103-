#ifndef PROYECTO_II_CLIENT_CE2103__GENETICPUZZLESETTINGS_H
#define PROYECTO_II_CLIENT_CE2103__GENETICPUZZLESETTINGS_H

#include <SFML/Graphics.hpp>
#include "GeneticPuzzle.h"

class GeneticPuzzleSettings{
public:
    int start(){
        int width = 1600;
        int height = 900;
        sf::RenderWindow window(sf::VideoMode(width, height), "Genetic Puzzle Settings");

        sf::Font font;
        if (!font.loadFromFile(
                "/home/joseandres216/Escritorio/Jose Andres/TEC/Semestre V/Datos II/Proyecto II - Games/Client/Proyecto_II_Client_CE2103-/Fonts/Games/Games-Italic.ttf")) {
            window.close();
        }

        sf::Text text;
        text.setFont(font);
        text.setString("Genetic Puzzle Settings Window");
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
                if (event.type == sf::Event::KeyReleased) {
                    if (event.key.code == sf::Keyboard::B) {
                        window.close();
                        GeneticPuzzle *window = new GeneticPuzzle();
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

#endif //PROYECTO_II_CLIENT_CE2103__GENETICPUZZLESETTINGS_H
