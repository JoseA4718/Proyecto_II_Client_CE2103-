//
// Created by eduardozumbadog on 5/14/21.
//

#ifndef BACKEND_GAME_H
#define BACKEND_GAME_H

#include "Player.h"
#include "Ball.h"
#include "Field.h"
#include "string"
#include "GameSettings.h"

using namespace std;

class Game {
private:
    Player *player_1;
    Player *player_2;
    Ball *ball;
    int max_goals;
    Field *field;
    int obstacles;
    string actualPlayer;
    static Game *instance;
    int field_height = 9;
    int field_lenght = 18;

    explicit Game(GameSettings *settings) {
        this->field = new Field(this->field_height, this->field_lenght);
        this->ball = new Ball();
        this->player_1 = new Player(settings->getPlayer1Name());
        this->player_2 = new Player(settings->getPlayer2Name());
        this->max_goals = settings->getMaxGoals();
        this->obstacles = settings->getObstacles();
    };

public:
    static Game *getInstance(GameSettings *settings = nullptr);

    void show() {
        cout << "Game information: " << endl
             << "Max score: " + to_string(this->max_goals) << endl
             << "Player 1: " + this->player_1->getName() << endl
             << "Player 2: " + this->player_2->getName() << endl
             << "Number of players (obstacles): " + to_string(this->obstacles) << endl
             << "*** Field***" << endl;
        this->field->show();

    }
    /**
     * @brief Method for generating the field, do not adds the players.
     */
    void buildField() {
        this->field->generateField();
    }
};

Game *Game::instance = nullptr;

Game *Game::getInstance(GameSettings *settings) {
    if (Game::instance == nullptr)
        Game::instance = new Game(settings);
    return Game::instance;
}


#endif //BACKEND_GAME_H
