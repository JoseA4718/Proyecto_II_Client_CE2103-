#ifndef PROYECTO_II_CLIENT_CE2103__BPGAME_H
#define PROYECTO_II_CLIENT_CE2103__BPGAME_H

#include <SFML/Graphics.hpp>
#include "../backend/soccar/Game.h"

class BPGame {
private:
    int goals;
    int numberOfPlayers;
    string gamemode;
    int power;
    string direction;
    int Player1Score;
    int Player2Score;

public:
    //Falta Codigo
    int start(Game *game) {
        this->goals = 1;
        this->numberOfPlayers = 1;
        this->gamemode = "Gamemode";
        this->Player1Score = 0;
        this->Player2Score = 0;
        int width = 1600;
        int height = 900;
        sf::RenderWindow window(sf::VideoMode(width, height), "BP Game");

        //Background resource loading
        sf::Texture bpGamebackground;
        if (!bpGamebackground.loadFromFile(
                "../Resources/BPGameBackground.png"))
            return EXIT_FAILURE;
        sf::Sprite bpGamebackgroundSprite(bpGamebackground);

        //Font resource loading
        sf::Font font;
        if (!font.loadFromFile(
                "../Fonts/Games/Games-Italic.ttf")) {
            window.close();
        }

        //Ball resource loading
        sf::Texture ball;
        if (!ball.loadFromFile(("../Resources/ball.png")))
            return EXIT_FAILURE;
        sf::Sprite ballSprite(ball);

        //Player resource loading
        sf::Texture player;
        if (!player.loadFromFile(("../Resources/Player1Car.png")))
            return EXIT_FAILURE;

        //Text of the player1Score
        sf::Text player1Score;
        player1Score.setFont(font);
        player1Score.setString(to_string(this->Player1Score));
        player1Score.setCharacterSize(80);
        player1Score.setFillColor(sf::Color::Red);
        player1Score.setPosition(900, 16);

        //Text of the player2Score
        sf::Text player2Score;
        player2Score.setFont(font);
        player2Score.setString(to_string(this->Player2Score));
        player2Score.setCharacterSize(80);
        player2Score.setFillColor(sf::Color::Blue);
        player2Score.setPosition(1030, 16);

        //Text of the goalsTowin
        sf::Text goalsTowin;
        goalsTowin.setFont(font);
        goalsTowin.setString(to_string(this->goals));
        goalsTowin.setCharacterSize(40);
        goalsTowin.setFillColor(sf::Color::White);
        goalsTowin.setPosition(1188, 803);

        //Text of the selectedPower
        sf::Text selectedPower;
        selectedPower.setFont(font);
        selectedPower.setString(to_string(this->power));
        selectedPower.setCharacterSize(40);
        selectedPower.setFillColor(sf::Color::White);
        selectedPower.setPosition(735, 770);

        //Text of the selectedDirection
        sf::Text selectedDirection;
        selectedDirection.setFont(font);
        selectedDirection.setString(this->direction);
        selectedDirection.setCharacterSize(35);
        selectedDirection.setFillColor(sf::Color::White);
        selectedDirection.setPosition(780, 850);

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::MouseButtonReleased) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        if (event.mouseButton.x >= 50 && event.mouseButton.x <= 102 && event.mouseButton.y >= 88 &&
                            event.mouseButton.y <= 135) { //Button for 20 of power
                            this->power = 20;
                        } else if (event.mouseButton.x >= 50 && event.mouseButton.x <= 102 &&
                                   event.mouseButton.y >= 156 &&
                                   event.mouseButton.y <= 204) { //Button for 40 of power
                            this->power = 40;
                        } else if (event.mouseButton.x >= 50 && event.mouseButton.x <= 102 &&
                                   event.mouseButton.y >= 224 &&
                                   event.mouseButton.y <= 270) { //Button for 60 of power
                            this->power = 60;
                        } else if (event.mouseButton.x >= 50 && event.mouseButton.x <= 102 &&
                                   event.mouseButton.y >= 290 &&
                                   event.mouseButton.y <= 337) { //Button for 80 of power
                            this->power = 80;
                        } else if (event.mouseButton.x >= 15 && event.mouseButton.x <= 123 &&
                                   event.mouseButton.y >= 449 &&
                                   event.mouseButton.y <= 533) { //Button for leftup direction
                            this->direction = "leftup";
                        } else if (event.mouseButton.x >= 15 && event.mouseButton.x <= 123 &&
                                   event.mouseButton.y >= 539 &&
                                   event.mouseButton.y <= 622) { //Button for left direction
                            this->direction = "left";
                        } else if (event.mouseButton.x >= 15 && event.mouseButton.x <= 123 &&
                                   event.mouseButton.y >= 625 &&
                                   event.mouseButton.y <= 707) { //Button for leftdown direction
                            this->direction = "leftdown";
                        } else if (event.mouseButton.x >= 130 && event.mouseButton.x <= 235 &&
                                   event.mouseButton.y >= 453 &&
                                   event.mouseButton.y <= 532) { //Button for up direction
                            this->direction = "up";
                        } else if (event.mouseButton.x >= 130 && event.mouseButton.x <= 235 &&
                                   event.mouseButton.y >= 541 &&
                                   event.mouseButton.y <= 619) { //Button for pathfinder direction
                            this->direction = "Pathfinder";
                        } else if (event.mouseButton.x >= 130 && event.mouseButton.x <= 235 &&
                                   event.mouseButton.y >= 625 &&
                                   event.mouseButton.y <= 706) { //Button for down direction
                            this->direction = "down";
                        } else if (event.mouseButton.x >= 242 && event.mouseButton.x <= 348 &&
                                   event.mouseButton.y >= 451 &&
                                   event.mouseButton.y <= 533) { //Button for rightup direction
                            this->direction = "rightup";
                        } else if (event.mouseButton.x >= 242 && event.mouseButton.x <= 348 &&
                                   event.mouseButton.y >= 539 &&
                                   event.mouseButton.y <= 620) { //Button for right direction
                            this->direction = "right";
                        } else if (event.mouseButton.x >= 242 && event.mouseButton.x <= 348 &&
                                   event.mouseButton.y >= 628 &&
                                   event.mouseButton.y <= 706) { //Button for rightdown direction
                            this->direction = "righdown";
                        }
                    }
                }

                //Escape binding to close program
                if (event.type == sf::Event::KeyReleased) {
                    if (event.key.code == sf::Keyboard::Escape) {
                        window.close();
                    }
                }
                //Binding to close program
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            window.clear();
            window.draw(bpGamebackgroundSprite);
            player1Score.setString(to_string(this->Player1Score));
            player2Score.setString(to_string(this->Player2Score));
            goalsTowin.setString(to_string(this->goals));
            selectedPower.setString(to_string(this->power));
            selectedDirection.setString(this->direction);
            window.draw(player1Score);
            window.draw(player2Score);
            window.draw(goalsTowin);
            window.draw(selectedPower);
            window.draw(selectedDirection);

            //Drawing of the obstacles
            for (int i = 1; i <= game->getMatrix()->getRows(); i++) {
                for (int j = 1; j <= game->getMatrix()->getColumns(); j++) {
                    Box *box = game->getMatrix()->get(i, j);
                    int x = box->getPosX();
                    int y = box->getPosY();
                    sf::RectangleShape obstacles(sf::Vector2f(70, 70));
                    obstacles.setPosition(x, y);
                    obstacles.setFillColor(sf::Color::Transparent);
                    obstacles.setOutlineColor(sf::Color::Black);
                    obstacles.setOutlineThickness(1);
                    if (dynamic_cast<GoalLineBox *>(box) != nullptr) {
                        obstacles.setFillColor(sf::Color::Red);
                    }
                    if (dynamic_cast<ObstacleBox *>(box) != nullptr) {
                        sf::Sprite playerSprite(player);
                        playerSprite.setPosition(x + 3, y + 3);
                        window.draw(playerSprite);
                    }
                    if (dynamic_cast<BoundBox *>(box) != nullptr) {
                        obstacles.setFillColor(sf::Color::White);
                    }
                    if (dynamic_cast<NormalBox *>(box) != nullptr) {
                        obstacles.setFillColor(sf::Color::Green);
                    }
                    window.draw(obstacles);
                }
            }

            //Drawing of the ball
            Box *ballBox = game->getMatrix()->get(game->getBall()->getRow(), game->getBall()->getColumn());
            ballSprite.setPosition(ballBox->getPosX() + 3, ballBox->getPosY() + 3);
            window.draw(ballSprite);

            window.display();
        }
    }
};

#endif //PROYECTO_II_CLIENT_CE2103__BPGAME_H
