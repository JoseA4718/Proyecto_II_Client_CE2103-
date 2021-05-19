#ifndef PROYECTO_II_CLIENT_CE2103__GENETICPUZZLESETTINGS_H
#define PROYECTO_II_CLIENT_CE2103__GENETICPUZZLESETTINGS_H

#include <SFML/Graphics.hpp>
#include "GeneticPuzzle.h"

class GeneticPuzzleSettings {
public:
    int start() {
        int width = 1600;
        int height = 900;
        sf::RenderWindow window(sf::VideoMode(width, height), "Genetic Puzzle Settings");

        sf::Texture geneticPuzzlesettingsBackground;
        if (!geneticPuzzlesettingsBackground.loadFromFile(
                "../Resources/GeneticPuzzleSettingsBackground.png"))
            return EXIT_FAILURE;
        sf::Sprite geneticPuzzlesettingsBackgroudsprite(geneticPuzzlesettingsBackground);

        sf::Font font;
        if (!font.loadFromFile(
                "../Fonts/Games/Games-Italic.ttf")) {
            window.close();
        }

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::MouseButtonReleased) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        cout << "x: " << event.mouseButton.x << endl;
                        cout << "y: " << event.mouseButton.y << endl << endl;
                    }
                }
                //PvP Button
                if (event.type == sf::Event::MouseButtonReleased) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        if (event.mouseButton.x >= 290 && event.mouseButton.x <= 520 && event.mouseButton.y >= 190 &&
                            event.mouseButton.y <= 390) {

                        }
                    }
                }
                //Enter button for going to next window
                if (event.type == sf::Event::KeyReleased) {
                    if (event.key.code == sf::Keyboard::Enter) {
                        window.close();
                        GeneticPuzzle *window = new GeneticPuzzle();
                        window->start();
                    }
                }

                //Program closing bindings
                if (event.type == sf::Event::KeyReleased) {
                    if (event.key.code == sf::Keyboard::Escape) {
                        window.close();
                    }
                }
                if (event.type == sf::Event::Closed)
                    window.close();
            }
            window.clear();
            window.draw(geneticPuzzlesettingsBackgroudsprite);
            window.display();
        }
    }

private:
};

#endif //PROYECTO_II_CLIENT_CE2103__GENETICPUZZLESETTINGS_H
