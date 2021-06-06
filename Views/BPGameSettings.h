using namespace std;

#include "iostream"
#include "../backend/soccar/Game.h"
#include "../backend/soccar/GameSettings.h"

#ifndef PROYECTO_II_CLIENT_CE2103__BPGAMESETTINGS_H
#define PROYECTO_II_CLIENT_CE2103__BPGAMESETTINGS_H

#include <SFML/Graphics.hpp>
#include "BPGame.h"
#include "../backend/soccar/Game.h"

class BPGameSettings {
private:
    string gamemode = "PvAI";
    int goalsTowin = 0;
    int playersPerteam = 0;
    Route *route1;

public:
    int start() {
        int width = 1600;
        int height = 900;
        sf::RenderWindow window(sf::VideoMode(width, height), "BP Game Settings");

        //Background resource loading
        sf::Texture bpGamesettingsBackground;
        if (!bpGamesettingsBackground.loadFromFile(
                "../Resources/BPGameSettingsBackground.png"))
            return EXIT_FAILURE;
        sf::Sprite bpGamesettingsBackgroundsprite(bpGamesettingsBackground);

        //Font resource loading
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
                        if (event.mouseButton.x >= 290 && event.mouseButton.x <= 520 && event.mouseButton.y >= 190 &&
                            event.mouseButton.y <= 390) { //Button for PvP gamemode
                            this->gamemode = "PvP";
                        } else if (event.mouseButton.x >= 705 && event.mouseButton.x <= 935 &&
                                   event.mouseButton.y >= 190 &&
                                   event.mouseButton.y <= 390) { //Button for PvAI gamemode
                            this->gamemode = "PvAI";
                        } else if (event.mouseButton.x >= 55 && event.mouseButton.x <= 145 &&
                                   event.mouseButton.y >= 470 &&
                                   event.mouseButton.y <= 555) { //Button for 1 goal to win
                            this->goalsTowin = 1;
                        } else if (event.mouseButton.x >= 170 && event.mouseButton.x <= 260 &&
                                   event.mouseButton.y >= 470 &&
                                   event.mouseButton.y <= 555) { //Button for 2 goal to win
                            this->goalsTowin = 2;
                        } else if (event.mouseButton.x >= 285 && event.mouseButton.x <= 375 &&
                                   event.mouseButton.y >= 470 &&
                                   event.mouseButton.y <= 555) { //Button for 3 goal to win
                            this->goalsTowin = 3;
                        } else if (event.mouseButton.x >= 405 && event.mouseButton.x <= 495 &&
                                   event.mouseButton.y >= 470 &&
                                   event.mouseButton.y <= 555) { //Button for 4 goal to win
                            this->goalsTowin = 4;
                        } else if (event.mouseButton.x >= 520 && event.mouseButton.x <= 605 &&
                                   event.mouseButton.y >= 470 &&
                                   event.mouseButton.y <= 555) { //Button for 5 goal to win
                            this->goalsTowin = 5;
                        } else if (event.mouseButton.x >= 635 && event.mouseButton.x <= 720 &&
                                   event.mouseButton.y >= 470 &&
                                   event.mouseButton.y <= 555) { //Button for 6 goal to win
                            this->goalsTowin = 6;
                        } else if (event.mouseButton.x >= 750 && event.mouseButton.x <= 835 &&
                                   event.mouseButton.y >= 470 &&
                                   event.mouseButton.y <= 555) { //Button for 7 goal to win
                            this->goalsTowin = 7;
                        } else if (event.mouseButton.x >= 870 && event.mouseButton.x <= 955 &&
                                   event.mouseButton.y >= 470 &&
                                   event.mouseButton.y <= 555) { //Button for 8 goal to win
                            this->goalsTowin = 8;
                        } else if (event.mouseButton.x >= 980 && event.mouseButton.x <= 1070 &&
                                   event.mouseButton.y >= 470 &&
                                   event.mouseButton.y <= 555) { //Button for 9 goal to win
                            this->goalsTowin = 9;
                        } else if (event.mouseButton.x >= 1100 && event.mouseButton.x <= 1185 &&
                                   event.mouseButton.y >= 470 &&
                                   event.mouseButton.y <= 555) { //Button for 10 goal to win
                            this->goalsTowin = 10;
                        } else if (event.mouseButton.x >= 335 && event.mouseButton.x <= 425 &&
                                   event.mouseButton.y >= 655 &&
                                   event.mouseButton.y <= 735) { //Button for 1 player per team
                            this->playersPerteam = 1;
                        } else if (event.mouseButton.x >= 455 && event.mouseButton.x <= 540 &&
                                   event.mouseButton.y >= 655 &&
                                   event.mouseButton.y <= 735) { //Button for 2 player per team
                            this->playersPerteam = 2;
                        } else if (event.mouseButton.x >= 570 && event.mouseButton.x <= 655 &&
                                   event.mouseButton.y >= 655 &&
                                   event.mouseButton.y <= 735) { //Button for 3 player per team
                            this->playersPerteam = 3;
                        } else if (event.mouseButton.x >= 685 && event.mouseButton.x <= 775 &&
                                   event.mouseButton.y >= 655 &&
                                   event.mouseButton.y <= 735) { //Button for 4 player per team
                            this->playersPerteam = 4;
                        } else if (event.mouseButton.x >= 800 && event.mouseButton.x <= 890 &&
                                   event.mouseButton.y >= 655 &&
                                   event.mouseButton.y <= 735) { //Button for 5 player per team
                            this->playersPerteam = 5;
                        }
                    }
                }
                if (event.type == sf::Event::KeyReleased) {
                    if (event.key.code == sf::Keyboard::Enter) {

                        //Enter binding to go to next window
                        GameSettings *gameSettings = new GameSettings();
                        gameSettings->setMaxGoals(this->goalsTowin)->setObstacles(this->playersPerteam)->setPlayer1Name(
                                "Player 1");
                        if (this->gamemode == "PvAI") {
                            gameSettings->setPlayer2Name("AI");
                        } else {
                            gameSettings->setPlayer2Name("Player 2");
                        }
                        //Game *game = new Game(gameSettings);
                        Game::getInstance(gameSettings);

                        Message *msg = new Message();

                        msg->setBody(to_string(playersPerteam));
                        msg->setRequest("obstacles");

                        string msgJson = Json::convertMessage(msg);

                        Response *response = ServerConnection::sendMessage(msgJson);

                        Route *route = new Route();
                        route->Deserialize(response->getMessage());

                        route1 = route;
                        route1->show();

                        Game::getInstance()->getField()->generateObstacles(route1->getRoute());

                        window.close();
                        BPGame *window = new BPGame();
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
            window.draw(bpGamesettingsBackgroundsprite);
            selectedGamemode.setString(this->gamemode);
            selectedGTW.setString(to_string(this->goalsTowin));
            selectedPPT.setString(to_string(this->playersPerteam));
            window.draw(selectedGamemode);
            window.draw(selectedGTW);
            window.draw(selectedPPT);
            window.display();
        }
        return 0;
    }
};

#endif //PROYECTO_II_CLIENT_CE2103__BPGAMESETTINGS_H
