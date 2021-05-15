#include <iostream>

#include "soccar/Game.h"

int main() {


    auto *settings = new GameSettings();
    settings->setMaxGoals(3)
            ->setObstacles(11)
            ->setPlayer1Name("Edu")
            ->setPlayer2Name("Jose");


    Game::getInstance(settings);
    Game::getInstance()->buildField();

    Game::getInstance()->show();




    return 0;
}
