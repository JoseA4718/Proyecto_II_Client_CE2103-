#ifndef PROYECTO_II_CLIENT_CE2103__BPGAME_H
#define PROYECTO_II_CLIENT_CE2103__BPGAME_H

#include <stdio.h>
#include <stdlib.h>

#include <SFML/Graphics.hpp>
#include "../backend/soccar/Game.h"
#include "../backend/util/Response.h"
#include "../backend/util/Message.h"
#include "../backend/soccar/Route.h"
#include "../backend/soccar/Shoot.h"
#include "../backend/util/Json.h"
#include "../Socket/ServerConnection .h"
#include "../backend/soccar/Data Structures/LinkedList.h"
#include "../backend/soccar/Path.h"


using namespace std;

class BPGame {
private:
    int goals = Game::getInstance()->getMaxgoals();
    int numberOfPlayers;
    string gamemode;
    int power;
    string direction;
    int dirX;
    int dirY;
    int Player1Score;
    int Player2Score;
    Route *route1;
    Player *actualPlayer;
    Route *pathfindingAroute;

public:
    void *Shot() {

        Shoot *shoot1 = new Shoot();
        shoot1->setDirX(dirX);
        shoot1->setDirY(dirY);
        shoot1->setStrength(power / 10);
        string shotJson = Json::convertShot(shoot1);

        Message *msg = new Message();
        msg->setBody(shotJson);
        msg->setRequest("shot");

        string msgJson = Json::convertMessage(msg);

        Response *response = ServerConnection::sendMessage(msgJson);

        Route *route = new Route();
        route->Deserialize(response->getMessage());
        route1 = route;
    }

    void *calculatePathfinding(){
        Path* path = new Path();
        path->setStartY(Game::getInstance()->getBall()->getColumn());
        path->setStartX(Game::getInstance()->getBall()->getRow());
        if(this->actualPlayer->getName() == "Player 1"){
            path->setEndY(18);
            path->setEndX(5);
        }else{
            path->setEndY(1);
            path->setEndX(5);
        }
        Message *msg = new Message();
        msg->setBody(Json::convertPath(path));
        msg->setRequest("star");

        string msgJson = Json::convertMessage(msg);
        cerr<<"msgJson: " << msgJson << endl;
        Response *response = ServerConnection::sendMessage(msgJson);

        Route *pathfinding = new Route();
        pathfinding->Deserialize(response->getMessage());
        pathfinding->show();
        this->pathfindingAroute = pathfinding;
    }

    int start() {
        Game::getInstance()->getField()->setPositions();
        this->gamemode = "Gamemode";
        this->Player1Score = 0;
        this->Player2Score = 0;
        this->actualPlayer = Game::getInstance()->getPlayer1();
        int width = 1600;
        int height = 900;
        sf::RenderWindow window(sf::VideoMode(width, height), "BP Game");

        //Background resource loading
        srand(time(0));
        int teams = rand() % 5 + 1;
        sf::Texture bpGamebackground;
        switch (teams) {
            case 1:
                bpGamebackground.loadFromFile("../Resources/BPGameBackgroundLDAvSAP.png");
                break;
            case 2:
                bpGamebackground.loadFromFile("../Resources/BPGameBackgroundFCBvRMA.png");
                break;
            case 3:
                bpGamebackground.loadFromFile("../Resources/BPGameBackgroundFCBvBVB.png");
                break;
            case 4:
                bpGamebackground.loadFromFile("../Resources/BPGameBackgroundRIVvBOC.png");
                break;
            case 5:
                bpGamebackground.loadFromFile("../Resources/BPGameBackgroundACMvINT.png");
                break;
        }
        sf::Sprite bpGamebackgroundSprite(bpGamebackground);

        //Font resource loading
        sf::Font font;
        if (!font.loadFromFile(
                "../Fonts/Games/Games-Italic.ttf")) {
            window.close();
        }

        //Ball resource loading
        sf::Texture ball;
        if (!ball.loadFromFile(("../Resources/Ball2.png")))
            return EXIT_FAILURE;
        sf::Sprite ballSprite(ball);

        //Player resource loading
        sf::Texture player1;
        if (!player1.loadFromFile(("../Resources/Car3.png")))
            return EXIT_FAILURE;

        sf::Texture player2;
        if (!player2.loadFromFile(("../Resources/Car5.png")))
            return EXIT_FAILURE;

        //Text of the player1Name
        sf::Text player1Name;
        player1Name.setFont(font);
        player1Name.setString("Player 1");
        player1Name.setCharacterSize(80);
        player1Name.setFillColor(sf::Color::Red);
        player1Name.setPosition(425, 16);

        //Text of the player2Name
        sf::Text player2Name;
        player2Name.setFont(font);
        player2Name.setString("Player 2");
        player2Name.setCharacterSize(80);
        player2Name.setFillColor(sf::Color::White);
        player2Name.setPosition(1200, 16);

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
                            this->dirX = -1;
                            this->dirY = 1;
                        } else if (event.mouseButton.x >= 15 && event.mouseButton.x <= 123 &&
                                   event.mouseButton.y >= 539 &&
                                   event.mouseButton.y <= 622) { //Button for left direction
                            this->direction = "left";
                            this->dirX = -1;
                            this->dirY = 0;
                        } else if (event.mouseButton.x >= 15 && event.mouseButton.x <= 123 &&
                                   event.mouseButton.y >= 625 &&
                                   event.mouseButton.y <= 707) { //Button for leftdown direction
                            this->direction = "leftdown";
                            this->dirX = -1;
                            this->dirY = -1;
                        } else if (event.mouseButton.x >= 130 && event.mouseButton.x <= 235 &&
                                   event.mouseButton.y >= 453 &&
                                   event.mouseButton.y <= 532) { //Button for up direction
                            this->direction = "up";
                            this->dirX = 0;
                            this->dirY = 1;
                        } else if (event.mouseButton.x >= 130 && event.mouseButton.x <= 235 &&
                                   event.mouseButton.y >= 541 &&
                                   event.mouseButton.y <= 619) { //Button for pathfinding direction
                            this->direction = "Pro tip";
                            calculatePathfinding();
                        } else if (event.mouseButton.x >= 130 && event.mouseButton.x <= 235 &&
                                   event.mouseButton.y >= 625 &&
                                   event.mouseButton.y <= 706) { //Button for down direction
                            this->direction = "down";
                            this->dirX = 0;
                            this->dirY = -1;
                        } else if (event.mouseButton.x >= 242 && event.mouseButton.x <= 348 &&
                                   event.mouseButton.y >= 451 &&
                                   event.mouseButton.y <= 533) { //Button for rightup direction
                            this->direction = "rightup";
                            this->dirX = 1;
                            this->dirY = 1;
                        } else if (event.mouseButton.x >= 242 && event.mouseButton.x <= 348 &&
                                   event.mouseButton.y >= 539 &&
                                   event.mouseButton.y <= 620) { //Button for right direction
                            this->direction = "right";
                            this->dirX = 1;
                            this->dirY = 0;
                        } else if (event.mouseButton.x >= 242 && event.mouseButton.x <= 348 &&
                                   event.mouseButton.y >= 628 &&
                                   event.mouseButton.y <= 706) { //Button for rightdown direction
                            this->direction = "righdown";
                            this->dirX = 1;
                            this->dirY = -1;
                        }
                    }
                }

                //Escape binding to close program
                if (event.type == sf::Event::KeyReleased) {
                    if (event.key.code == sf::Keyboard::Escape) {
                        window.close();
                    }
                    if (event.key.code == sf::Keyboard::Enter) {
                        Shot();
                        LinkedList<Box *> *routeList = route1->getRoute();
                        Box *ballBox;
                        route1->show();
                        for (int i = 0; i < routeList->len; ++i) {

                            Box *box1 = routeList->get(i);

                            Game::getInstance()->getBall()->setRow(box1->getRow());
                            Game::getInstance()->getBall()->setColumn(box1->getColumn());

                            window.clear();
                            window.draw(bpGamebackgroundSprite);
                            player1Score.setString(to_string(this->Player1Score));
                            player2Score.setString(to_string(this->Player2Score));
                            goalsTowin.setString(to_string(this->goals));
                            selectedPower.setString(to_string(this->power));
                            selectedDirection.setString(this->direction);
                            window.draw(player1Name);
                            window.draw(player2Name);
                            window.draw(player1Score);
                            window.draw(player2Score);
                            window.draw(goalsTowin);
                            window.draw(selectedPower);
                            window.draw(selectedDirection);

                            for (int i = 1; i <= Game::getInstance()->getMatrix()->getRows(); i++) {
                                for (int j = 1; j <= Game::getInstance()->getMatrix()->getColumns(); j++) {
                                    Box *box = Game::getInstance()->getMatrix()->get(i, j);
                                    int x = box->getPosX();
                                    int y = box->getPosY();
                                    sf::RectangleShape obstacles(sf::Vector2f(70, 70));
                                    obstacles.setPosition(x, y);
                                    obstacles.setFillColor(sf::Color::Transparent);
                                    if (dynamic_cast<ObstacleBox *>(box) != nullptr) {
                                        if (j <= 9){
                                            sf::Sprite player1Sprite(player1);
                                            player1Sprite.setPosition(x, y);
                                            window.draw(player1Sprite);
                                        }
                                        else{
                                            sf::Sprite player2Sprite(player2);
                                            player2Sprite.setPosition(x, y);
                                            window.draw(player2Sprite);
                                        }

                                    }
                                    window.draw(obstacles);
                                }
                            }
                            ballBox = Game::getInstance()->getMatrix()->get(Game::getInstance()->getBall()->getRow(),
                                                                            Game::getInstance()->getBall()->getColumn());
                            ballSprite.setPosition(ballBox->getPosX(), ballBox->getPosY());
                            window.draw(ballSprite);
                            window.display();
                            sf::sleep(sf::milliseconds(500));
                        }

                        //Goal check
                        if (dynamic_cast<GoalLineBox *>(ballBox) != nullptr) {
                            //Drawing of the goal screen
                            window.clear();
                            sf::RectangleShape goalBackground(sf::Vector2f(1600, 900));
                            sf::Text goalText;
                            goalText.setFont(font);
                            
                            if(Game::getInstance()->getBall()->getColumn() != 1){
                                auto pPlayer = Game::getInstance()->getPlayer1();
                                pPlayer->addGoal();
                                goalBackground.setFillColor(sf::Color::Red);
                                goalText.setString("Player 1 scored!");
                            }else{
                                auto player2 = Game::getInstance()->getPlayer2();
                                player2->addGoal();
                                goalBackground.setFillColor(sf::Color::Blue);
                                goalText.setString("Player 2 scored!");
                            }
                            
                            goalText.setCharacterSize(150);
                            goalText.setFillColor(sf::Color::White);
                            goalText.setPosition(150, 350);
                            window.draw(goalBackground);
                            window.draw(goalText);
                            window.display();
                            sf::sleep(sf::milliseconds(2000));

                            //Update of the scores
                            this->Player1Score = Game::getInstance()->getPlayer1()->getScore();
                            this->Player2Score = Game::getInstance()->getPlayer2()->getScore();

                            //Update ball position
                            Game::getInstance()->getBall()->setRow(5);
                            Game::getInstance()->getBall()->setColumn(9);
                        }

                        //Winner check
                        if(Game::getInstance()->scoreCheck()) {
                            window.clear();
                            sf::RectangleShape winnerBackground(sf::Vector2f(1600, 900));
                            sf::Text winnerText;
                            winnerText.setFont(font);
                            if(Game::getInstance()->getPlayer1()->getScore() == Game::getInstance()->getMaxgoals()){
                                winnerText.setString("Player 1 wins!");
                                winnerBackground.setFillColor(sf::Color::Red);
                            }else{
                                winnerText.setString("Player 2 wins!");
                                winnerBackground.setFillColor(sf::Color::Blue);
                            }
                            winnerText.setCharacterSize(150);
                            winnerText.setFillColor(sf::Color::White);
                            winnerText.setPosition(200, 350);
                            window.draw(winnerBackground);
                            window.draw(winnerText);
                            window.display();
                            sf::sleep(sf::milliseconds(2000));
                            window.close();
                        }

                        //Next player1
                        this->actualPlayer = Game::getInstance()->getNextPlayer(this->actualPlayer);
                        if (actualPlayer->getName() == "Player 1") {
                            player1Name.setFillColor(sf::Color::Red);
                            player2Name.setFillColor(sf::Color::White);
                        } else {
                            player2Name.setFillColor(sf::Color::Blue);
                            player1Name.setFillColor(sf::Color::White);
                        }
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
            window.draw(player1Name);
            window.draw(player2Name);
            window.draw(player1Score);
            window.draw(player2Score);
            window.draw(goalsTowin);
            window.draw(selectedPower);
            window.draw(selectedDirection);

            //Drawing of the obstacles
            for (int i = 1; i <= Game::getInstance()->getMatrix()->getRows(); i++) {
                for (int j = 1; j <= Game::getInstance()->getMatrix()->getColumns(); j++) {
                    Box *box = Game::getInstance()->getMatrix()->get(i, j);
                    int x = box->getPosX();
                    int y = box->getPosY();
                    sf::RectangleShape obstacles(sf::Vector2f(70, 70));
                    obstacles.setPosition(x, y);
                    obstacles.setFillColor(sf::Color::Transparent);
                    if (dynamic_cast<ObstacleBox *>(box) != nullptr) {
                        if (j <= 9){
                            sf::Sprite player1Sprite(player1);
                            player1Sprite.setPosition(x, y);
                            window.draw(player1Sprite);
                        }
                        else{
                            sf::Sprite player2Sprite(player2);
                            player2Sprite.setPosition(x, y);
                            window.draw(player2Sprite);
                        }

                    }
                    window.draw(obstacles);
                }
            }

            //Drawing of the ball
            Box *ballBox = Game::getInstance()->getMatrix()->get(Game::getInstance()->getBall()->getRow(), Game::getInstance()->getBall()->getColumn());
            ballSprite.setPosition(ballBox->getPosX(), ballBox->getPosY());
            window.draw(ballSprite);

            window.display();
        }
    }
};

#endif //PROYECTO_II_CLIENT_CE2103__BPGAME_H
