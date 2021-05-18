using namespace std;

#include "iostream"
#include "../backend/soccar/Game.h"
#include "../backend/soccar/GameSettings.h"

#ifndef PROYECTO_II_CLIENT_CE2103__BPGAMESETTINGS_H
#define PROYECTO_II_CLIENT_CE2103__BPGAMESETTINGS_H

#include <SFML/Graphics.hpp>
#include "BPGame.h"

class BPGameSettings {
private:
    string gamemode = "PvAI";
    int goalsTowin = 0;
    int playersPerteam = 0;

public:
    int start() {
        int width = 1600;
        int height = 900;
        sf::RenderWindow window(sf::VideoMode(width, height), "BP Game Settings");

        sf::Texture bpGamebackground;
        if (!bpGamebackground.loadFromFile(
                "../content/BPGameSettingsBackground.png"))
            return EXIT_FAILURE;
        sf::Sprite bpGamebackgroundSprite(bpGamebackground);

        sf::Font font;
        if (!font.loadFromFile(
                "../Fonts/Games/Games-Italic.ttf")) {
            window.close();
        }

        //Text of the selected gamemode
        sf::Text selectedGamemode;
        selectedGamemode.setFont(font);
        selectedGamemode.setString(this->gamemode);
        selectedGamemode.setCharacterSize(25);
        selectedGamemode.setFillColor(sf::Color::Black);
        selectedGamemode.setPosition(1390, 390);

        //Text of the selected goals to win
        sf::Text selectedGTW;
        selectedGTW.setFont(font);
        selectedGTW.setString(to_string(this->goalsTowin));
        selectedGTW.setCharacterSize(30);
        selectedGTW.setFillColor(sf::Color::Black);
        selectedGTW.setPosition(1405, 505);

        //Text of the selected players per team
        sf::Text selectedPPT;
        selectedPPT.setFont(font);
        selectedPPT.setString(to_string(this->playersPerteam));
        selectedPPT.setCharacterSize(30);
        selectedPPT.setFillColor(sf::Color::Black);
        selectedPPT.setPosition(1405, 640);

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
                            this->gamemode = "PvP";
                        }
                    }
                }
                //PvAI Button
                if (event.type == sf::Event::MouseButtonReleased) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        if (event.mouseButton.x >= 705 && event.mouseButton.x <= 935 && event.mouseButton.y >= 190 &&
                            event.mouseButton.y <= 390) {
                            this->gamemode = "PvAI";
                        }
                    }
                }
                //1GTW Button
                if (event.type == sf::Event::MouseButtonReleased) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        if (event.mouseButton.x >= 55 && event.mouseButton.x <= 145 && event.mouseButton.y >= 470 &&
                            event.mouseButton.y <= 555) {
                            this->goalsTowin = 1;
                        }
                    }
                }
                //2GTW Button
                if (event.type == sf::Event::MouseButtonReleased) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        if (event.mouseButton.x >= 170 && event.mouseButton.x <= 260 && event.mouseButton.y >= 470 &&
                            event.mouseButton.y <= 555) {
                            this->goalsTowin = 2;
                        }
                    }
                }
                //3GTW Button
                if (event.type == sf::Event::MouseButtonReleased) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        if (event.mouseButton.x >= 285 && event.mouseButton.x <= 375 && event.mouseButton.y >= 470 &&
                            event.mouseButton.y <= 555) {
                            this->goalsTowin = 3;
                        }
                    }
                }
                //4GTW Button
                if (event.type == sf::Event::MouseButtonReleased) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        if (event.mouseButton.x >= 405 && event.mouseButton.x <= 495 && event.mouseButton.y >= 470 &&
                            event.mouseButton.y <= 555) {
                            this->goalsTowin = 4;
                        }
                    }
                }
                //5GTW Button
                if (event.type == sf::Event::MouseButtonReleased) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        if (event.mouseButton.x >= 520 && event.mouseButton.x <= 605 && event.mouseButton.y >= 470 &&
                            event.mouseButton.y <= 555) {
                            this->goalsTowin = 5;
                        }
                    }
                }
                //6GTW Button
                if (event.type == sf::Event::MouseButtonReleased) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        if (event.mouseButton.x >= 635 && event.mouseButton.x <= 720 && event.mouseButton.y >= 470 &&
                            event.mouseButton.y <= 555) {
                            this->goalsTowin = 6;
                        }
                    }
                }
                //7GTW Button
                if (event.type == sf::Event::MouseButtonReleased) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        if (event.mouseButton.x >= 750 && event.mouseButton.x <= 835 && event.mouseButton.y >= 470 &&
                            event.mouseButton.y <= 555) {
                            this->goalsTowin = 7;
                        }
                    }
                }
                //8GTW Button
                if (event.type == sf::Event::MouseButtonReleased) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        if (event.mouseButton.x >= 870 && event.mouseButton.x <= 955 && event.mouseButton.y >= 470 &&
                            event.mouseButton.y <= 555) {
                            this->goalsTowin = 8;
                        }
                    }
                }
                //9GTW Button
                if (event.type == sf::Event::MouseButtonReleased) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        if (event.mouseButton.x >= 980 && event.mouseButton.x <= 1070 && event.mouseButton.y >= 470 &&
                            event.mouseButton.y <= 555) {
                            this->goalsTowin = 9;
                        }
                    }
                }
                //10GTW Button
                if (event.type == sf::Event::MouseButtonReleased) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        if (event.mouseButton.x >= 1100 && event.mouseButton.x <= 1185 && event.mouseButton.y >= 470 &&
                            event.mouseButton.y <= 555) {
                            this->goalsTowin = 10;
                        }
                    }
                }
                //1PPT Button
                if (event.type == sf::Event::MouseButtonReleased) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        if (event.mouseButton.x >= 335 && event.mouseButton.x <= 425 && event.mouseButton.y >= 655 &&
                            event.mouseButton.y <= 735) {
                            this->playersPerteam = 1;
                        }
                    }
                }
                //2PPT Button
                if (event.type == sf::Event::MouseButtonReleased) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        if (event.mouseButton.x >= 455 && event.mouseButton.x <= 540 && event.mouseButton.y >= 655 &&
                            event.mouseButton.y <= 735) {
                            this->playersPerteam = 2;
                        }
                    }
                }
                //3PPT Button
                if (event.type == sf::Event::MouseButtonReleased) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        if (event.mouseButton.x >= 570 && event.mouseButton.x <= 655 && event.mouseButton.y >= 655 &&
                            event.mouseButton.y <= 735) {
                            this->playersPerteam = 3;
                        }
                    }
                }
                //4PPT Button
                if (event.type == sf::Event::MouseButtonReleased) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        if (event.mouseButton.x >= 685 && event.mouseButton.x <= 775 && event.mouseButton.y >= 655 &&
                            event.mouseButton.y <= 735) {
                            this->playersPerteam = 4;
                        }
                    }
                }
                //5PPT Button
                if (event.type == sf::Event::MouseButtonReleased) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        if (event.mouseButton.x >= 800 && event.mouseButton.x <= 890 && event.mouseButton.y >= 655 &&
                            event.mouseButton.y <= 735) {
                            this->playersPerteam = 5;
                        }
                    }
                }
                //Enter input to change to BP Game Window
                if (event.type == sf::Event::KeyReleased) {
                    if (event.key.code == sf::Keyboard::Enter) {
                        GameSettings *gameSettings = new GameSettings();
                        gameSettings->setMaxGoals(this->goalsTowin)->setObstacles(this->playersPerteam)->setPlayer1Name(
                                "Player 1");
                        if(this->gamemode == "PvAI"){
                            gameSettings->setPlayer2Name("AI");
                        }else{
                            gameSettings->setPlayer2Name("Player 2");
                        }
                        Game *game = new Game(gameSettings);
                        window.close();
                        BPGame *window = new BPGame();
                        window->start(game);
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
            window.draw(bpGamebackgroundSprite);
            selectedGamemode.setString(this->gamemode);
            selectedGTW.setString(to_string(this->goalsTowin));
            selectedPPT.setString(to_string(this->playersPerteam));
            window.draw(selectedGamemode);
            window.draw(selectedGTW);
            window.draw(selectedPPT);
            window.display();
        }
    }
};

#endif //PROYECTO_II_CLIENT_CE2103__BPGAMESETTINGS_H
