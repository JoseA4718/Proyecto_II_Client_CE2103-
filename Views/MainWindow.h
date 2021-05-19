#ifndef PROYECTO_II_CLIENT_CE2103__MAINWINDOW_H
#define PROYECTO_II_CLIENT_CE2103__MAINWINDOW_H

#include "BPGameSettings.h"
#include "GeneticPuzzleSettings.h"

#include <SFML/Graphics.hpp>

class MainWindow {
private:

public:
    int start() {
        int width = 1600;
        int height = 900;
        sf::RenderWindow window(sf::VideoMode(width, height), "Let's Play");

        //Background resource loading
        sf::Texture menuBackground;
        if (!menuBackground.loadFromFile(
                "../Resources/MenuBackground.png"))
            return EXIT_FAILURE;
        sf::Sprite menuBackgroundsprite(menuBackground);

        //Font resource loading
        sf::Font font;
        if (!font.loadFromFile(
                "../Fonts/Games/Games-Italic.ttf")) {
            window.close();
        }

        //Text of the BP Game option
        sf::Text bpGametext;
        bpGametext.setFont(font);
        bpGametext.setString("Press A to play BP Game");
        bpGametext.setCharacterSize(50);
        bpGametext.setFillColor(sf::Color::Red);
        bpGametext.setOutlineColor(sf::Color::White);
        bpGametext.setOutlineThickness(5);
        bpGametext.setPosition(50, 800);

        //Text of Genetic Puzzle option
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
                    if (event.key.code == sf::Keyboard::A) { //A binding to go to next window
                        window.close();
                        BPGameSettings *window = new BPGameSettings();
                        window->start();
                    }else if (event.key.code == sf::Keyboard::B) { //B binding to go to next window
                        window.close();
                        GeneticPuzzleSettings *window = new GeneticPuzzleSettings();
                        window->start();
                    }else if (event.key.code == sf::Keyboard::Escape) { //Escape binding to close program
                    window.close();
                    }
                }
                //Binding to close program
                if (event.type == sf::Event::Closed)
                    window.close();
            }
            window.clear();
            window.draw(menuBackgroundsprite);
            window.draw(bpGametext);
            window.draw(geneticPuzzletext);
            window.display();
        }
    }
};

#endif //PROYECTO_II_CLIENT_CE2103__MAINWINDOW_H