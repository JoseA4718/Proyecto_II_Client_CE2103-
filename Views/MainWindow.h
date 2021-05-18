#ifndef PROYECTO_II_CLIENT_CE2103__MAINWINDOW_H
#define PROYECTO_II_CLIENT_CE2103__MAINWINDOW_H

#include "BPGameSettings.h"
#include "GeneticPuzzleSettings.h"

#include <SFML/Graphics.hpp>

class MainWindow {
public:
    int start() {
        int width = 1600;
        int height = 900;
        sf::RenderWindow window(sf::VideoMode(width, height), "Let's Play");

        sf::Texture menuBackground;
        if (!menuBackground.loadFromFile(
                "../content/MenuBackground.png"))
            return EXIT_FAILURE;
        sf::Sprite menuBackgroundsprite(menuBackground);

        sf::Font font;
        if (!font.loadFromFile(
                "../Fonts/Games/Games-Italic.ttf")) {
            window.close();
        }

        sf::Text bpGametext;
        bpGametext.setFont(font);
        bpGametext.setString("Press A to play BP Game");
        bpGametext.setCharacterSize(50);
        bpGametext.setFillColor(sf::Color::Red);
        bpGametext.setOutlineColor(sf::Color::White);
        bpGametext.setOutlineThickness(5);
        bpGametext.setPosition(50, 800);

        sf::Text geneticPuzzletext;
        geneticPuzzletext.setFont(font);
        geneticPuzzletext.setString("Press B to play Genetic Puzzle");
        geneticPuzzletext.setCharacterSize(45);
        geneticPuzzletext.setFillColor(sf::Color::Red);
        geneticPuzzletext.setOutlineColor(sf::Color::White);
        geneticPuzzletext.setOutlineThickness(5);
        geneticPuzzletext.setPosition(825, 800);

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::KeyReleased) {
                    if (event.key.code == sf::Keyboard::Escape) {
                        window.close();
                    }
                }
                if (event.type == sf::Event::Closed)
                    window.close();
                if (event.type == sf::Event::KeyReleased) {
                    if (event.key.code == sf::Keyboard::A) {
                        window.close();
                        BPGameSettings *window = new BPGameSettings();
                        window->start();
                    }
                }
                if (event.type == sf::Event::KeyReleased) {
                    if (event.key.code == sf::Keyboard::B) {
                        window.close();
                        GeneticPuzzleSettings *window = new GeneticPuzzleSettings();
                        window->start();
                    }
                }
            }
            window.clear();
            window.draw(menuBackgroundsprite);
            window.draw(bpGametext);
            window.draw(geneticPuzzletext);
            window.display();
        }
    }

private:
};

#endif //PROYECTO_II_CLIENT_CE2103__MAINWINDOW_H