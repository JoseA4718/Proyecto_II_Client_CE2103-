#ifndef PROYECTO_II_CLIENT_CE2103__BPGAME_H
#define PROYECTO_II_CLIENT_CE2103__BPGAME_H

#include <SFML/Graphics.hpp>

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
    int start(int goalstoWin, int playerNumber, string Gamemode) {
        this->goals = goalstoWin;
        this->numberOfPlayers = playerNumber;
        this->gamemode = Gamemode;
        this->Player1Score = 0;
        this->Player2Score = 0;
        int width = 1600;
        int height = 900;
        sf::RenderWindow window(sf::VideoMode(width, height), "BP Game");

        sf::Texture bpGamebackground;
        if (!bpGamebackground.loadFromFile(
                "../content/BPGameBackground.png"))
            return EXIT_FAILURE;
        sf::Sprite bpGamebackgroundSprite(bpGamebackground);

        sf::Font font;
        if (!font.loadFromFile(
                "../Fonts/Games/Games-Italic.ttf")) {
            window.close();
        }
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
        selectedPower.setPosition(744, 770);

        //Text of the selectedDirection
        sf::Text selectedDirection;
        selectedDirection.setFont(font);
        selectedDirection.setString(this->direction);
        selectedDirection.setCharacterSize(35);
        selectedDirection.setFillColor(sf::Color::White);
        selectedDirection.setPosition(790, 850);

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::MouseButtonReleased) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        cout << "x: " << event.mouseButton.x << endl;
                        cout << "y: " << event.mouseButton.y << endl << endl;
                    }
                }
                if (event.type == sf::Event::MouseButtonReleased) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        if (event.mouseButton.x >= 50 && event.mouseButton.x <= 102 && event.mouseButton.y >= 88 &&
                            event.mouseButton.y <= 135) {
                            this->power = 20;
                        }
                    }
                }
                if (event.type == sf::Event::MouseButtonReleased) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        if (event.mouseButton.x >= 50 && event.mouseButton.x <= 102 && event.mouseButton.y >= 156 &&
                            event.mouseButton.y <= 204) {
                            this->power = 40;
                        }
                    }
                }
                if (event.type == sf::Event::MouseButtonReleased) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        if (event.mouseButton.x >= 50 && event.mouseButton.x <= 102 && event.mouseButton.y >= 224 &&
                            event.mouseButton.y <= 270) {
                            this->power = 60;
                        }
                    }
                }
                if (event.type == sf::Event::MouseButtonReleased) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        if (event.mouseButton.x >= 50 && event.mouseButton.x <= 102 && event.mouseButton.y >= 290 &&
                            event.mouseButton.y <= 337) {
                            this->power = 80;
                        }
                    }
                }
                if (event.type == sf::Event::MouseButtonReleased) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        if (event.mouseButton.x >= 15 && event.mouseButton.x <= 123 && event.mouseButton.y >= 449 &&
                            event.mouseButton.y <= 533) {
                            this->direction = "leftup";
                        }
                    }
                }
                if (event.type == sf::Event::MouseButtonReleased) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        if (event.mouseButton.x >= 15 && event.mouseButton.x <= 123 && event.mouseButton.y >= 539 &&
                            event.mouseButton.y <= 622) {
                            this->direction = "left";
                        }
                    }
                }
                if (event.type == sf::Event::MouseButtonReleased) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        if (event.mouseButton.x >= 15 && event.mouseButton.x <= 123 && event.mouseButton.y >= 625 &&
                            event.mouseButton.y <= 707) {
                            this->direction = "leftdown";
                        }
                    }
                }
                if (event.type == sf::Event::MouseButtonReleased) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        if (event.mouseButton.x >= 130 && event.mouseButton.x <= 235 && event.mouseButton.y >= 453 &&
                            event.mouseButton.y <= 532) {
                            this->direction = "up";
                        }
                    }
                }
                if (event.type == sf::Event::MouseButtonReleased) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        if (event.mouseButton.x >= 130 && event.mouseButton.x <= 235 && event.mouseButton.y >= 541 &&
                            event.mouseButton.y <= 619) {
                            this->direction = "Pathfinder";
                        }
                    }
                }
                if (event.type == sf::Event::MouseButtonReleased) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        if (event.mouseButton.x >= 130 && event.mouseButton.x <= 235 && event.mouseButton.y >= 625 &&
                            event.mouseButton.y <= 706) {
                            this->direction = "down";
                        }
                    }
                }
                if (event.type == sf::Event::MouseButtonReleased) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        if (event.mouseButton.x >= 242 && event.mouseButton.x <= 348 && event.mouseButton.y >= 451 &&
                            event.mouseButton.y <= 533) {
                            this->direction = "rightup";
                        }
                    }
                }
                if (event.type == sf::Event::MouseButtonReleased) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        if (event.mouseButton.x >= 242 && event.mouseButton.x <= 348 && event.mouseButton.y >= 539 &&
                            event.mouseButton.y <= 620) {
                            this->direction = "right";
                        }
                    }
                }
                if (event.type == sf::Event::MouseButtonReleased) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        if (event.mouseButton.x >= 242 && event.mouseButton.x <= 348 && event.mouseButton.y >= 628 &&
                            event.mouseButton.y <= 706) {
                            this->direction = "righdown";
                        }
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
            window.display();
        }
    }

private:
};

#endif //PROYECTO_II_CLIENT_CE2103__BPGAME_H
