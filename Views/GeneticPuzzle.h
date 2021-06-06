#ifndef PROYECTO_II_CLIENT_CE2103__GENETICPUZZLE_H
#define PROYECTO_II_CLIENT_CE2103__GENETICPUZZLE_H

#include <SFML/Graphics.hpp>

class GeneticPuzzle {
private:
public:
    int start() {
        int width = 1600;
        int height = 900;
        sf::RenderWindow window(sf::VideoMode(width, height), "Genetic Puzzle");

        //Background resource loading
        sf::Texture geneticPuzzlebackground;
        if (!geneticPuzzlebackground.loadFromFile(
                "../Resources/GeneticPuzzleBackground.png"))
            return EXIT_FAILURE;
        sf::Sprite geneticPuzzlebackgroundSprite(geneticPuzzlebackground);

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::MouseButtonReleased) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        if (event.mouseButton.x >= 535 && event.mouseButton.x <= 760 &&
                            event.mouseButton.y >= 780 && event.mouseButton.y <= 865) { //Previous button
                            cout << "Prev";
                        } else if (event.mouseButton.x >= 915 && event.mouseButton.x <= 1135 &&
                                   event.mouseButton.y >= 780 && event.mouseButton.y <= 865) { //Next button
                            cout << "Nest";
                        }
                    }
                }

                if (event.type == sf::Event::KeyReleased) {
                    if (event.key.code == sf::Keyboard::Escape) { //Escape binding to close program
                        window.close();
                    }
                }
                //Binding to close program
                if (event.type == sf::Event::Closed)
                    window.close();
            }
            window.clear();
            window.draw(geneticPuzzlebackgroundSprite);
            window.display();
        }
        return 0;
    }
};

#endif //PROYECTO_II_CLIENT_CE2103__GENETICPUZZLE_H
