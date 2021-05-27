//
// Created by eduardozumbadog on 5/14/21.
//

#ifndef BACKEND_PLAYER_H
#define BACKEND_PLAYER_H

#include "string"

using namespace std;

class Player {
private:
    int score = 0;
    string name;
public:
    Player(const string &name) : name(name) {}

    int getScore() const {
        return score;
    }

    void addGoal() {
        this->score++;
    }

    void setScore(int score) {
        Player::score = score;
    }

    const string &getName() const {
        return name;
    }

    void setName(const string &name) {
        Player::name = name;
    }
};


#endif //BACKEND_PLAYER_H
