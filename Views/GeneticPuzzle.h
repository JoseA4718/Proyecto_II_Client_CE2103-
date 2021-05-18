#ifndef PROYECTO_II_CLIENT_CE2103__GENETICPUZZLE_H
#define PROYECTO_II_CLIENT_CE2103__GENETICPUZZLE_H

#include <SFML/Graphics.hpp>

class GeneticPuzzle {
public:
    int start() {
        int width = 1600;
        int height = 900;
        sf::RenderWindow window(sf::VideoMode(width, height), "Genetic Puzzle");

        sf::Font font;
        if (!font.loadFromFile(
                "../Fonts/Games/Games-Italic.ttf")) {
            window.close();
        }

        sf::Text text;
        text.setFont(font);
        text.setString("Genetic Puzzle Window");
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

#endif //PROYECTO_II_CLIENT_CE2103__GENETICPUZZLE_H
