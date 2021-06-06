#ifndef PROYECTO_II_CLIENT_CE2103__GENETICPUZZLESETTINGS_H
#define PROYECTO_II_CLIENT_CE2103__GENETICPUZZLESETTINGS_H

#include <SFML/Graphics.hpp>
#include "GeneticPuzzle.h"

class GeneticPuzzleSettings {
private:
    string difficulty = "2X2";
    string imageState = "Waiting for\nimage...";
public:
    int start() {
        int width = 1600;
        int height = 900;
        sf::RenderWindow window(sf::VideoMode(width, height), "Genetic Puzzle Settings");

        //Background resource loading
        sf::Texture geneticPuzzlesettingsBackground;
        if (!geneticPuzzlesettingsBackground.loadFromFile(
                "../Resources/GeneticPuzzleSettingsBackground.png"))
            return EXIT_FAILURE;
        sf::Sprite geneticPuzzlesettingsBackgroudsprite(geneticPuzzlesettingsBackground);

        sf::Texture selectedImage;

        //Font resource loading
        sf::Font font;
        if (!font.loadFromFile(
                "../Fonts/Games/Games-Italic.ttf")) {
            window.close();
        }

        //Text of the selected difficulty
        sf::Text selectedDifficulty;
        selectedDifficulty.setFont(font);
        selectedDifficulty.setString(this->difficulty);
        selectedDifficulty.setCharacterSize(35);
        selectedDifficulty.setFillColor(sf::Color::White);
        selectedDifficulty.setPosition(795, 625);

        //Text of the selected difficulty
        sf::Text loadImage;
        loadImage.setFont(font);
        loadImage.setString(this->imageState);
        loadImage.setCharacterSize(25);
        loadImage.setFillColor(sf::Color::White);
        loadImage.setPosition(1100, 610);

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::MouseButtonReleased) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        if (event.mouseButton.x >= 455 && event.mouseButton.x <= 605 && event.mouseButton.y >= 360 &&
                            event.mouseButton.y <= 500) { //Button for 2X2 difficulty
                            this->difficulty = "2X2";
                        } else if (event.mouseButton.x >= 655 && event.mouseButton.x <= 805 &&
                                   event.mouseButton.y >= 360 &&
                                   event.mouseButton.y <= 500) { //Button for 3X3 difficulty
                            this->difficulty = "3X3";
                        } else if (event.mouseButton.x >= 855 && event.mouseButton.x <= 1005 &&
                                   event.mouseButton.y >= 360 &&
                                   event.mouseButton.y <= 500) { //Button for 4X4 difficulty
                            this->difficulty = "4X4";
                        } else if (event.mouseButton.x >= 1065 && event.mouseButton.x <= 1220 &&
                                   event.mouseButton.y >= 360 &&
                                   event.mouseButton.y <= 500) { //Button for 5X5 difficulty
                            this->difficulty = "5X5";
                        } else if (event.mouseButton.x >= 890 && event.mouseButton.x <= 1070 &&
                                  event.mouseButton.y >= 595 &&
                                  event.mouseButton.y <= 675) { //Button for image loading
                            string imagePath;
                            cin >> imagePath;
                            if (!selectedImage.loadFromFile(
                                    imagePath)){
                                loadImage.setString("Couldn't load\nimage");
                            }else{
                                loadImage.setString("Image loaded\nsuccesfully!");
                            }
                        }
                    }
                }
                
                if (event.type == sf::Event::KeyReleased) {
                    if (event.key.code == sf::Keyboard::Enter) { //Enter binding to go to the next window
                        window.close();
                        GeneticPuzzle *window = new GeneticPuzzle();
                        window->start();
                    } else if (event.key.code == sf::Keyboard::Escape) { //Escape binding to close program
                        window.close();
                    }
                }

                //Binding to close program
                if (event.type == sf::Event::Closed)
                    window.close();
            }
            window.clear();
            window.draw(geneticPuzzlesettingsBackgroudsprite);
            selectedDifficulty.setString(this->difficulty);
            window.draw(selectedDifficulty);
            loadImage.setString(this->imageState);
            window.draw(loadImage);
            window.display();
        }
        return 0;
    }

private:
};

#endif //PROYECTO_II_CLIENT_CE2103__GENETICPUZZLESETTINGS_H
