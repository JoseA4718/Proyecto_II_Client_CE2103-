//
// Created by eduardozumbadog on 5/14/21.
//

#ifndef BACKEND_BALL_H
#define BACKEND_BALL_H


class Ball {
private:
    int row;
    int column;

public:
    Ball(int row, int column){
        this->row = row;
        this->column = column;
    }

    int getRow(){
        return this->row;
    }

    int getColumn(){
        return this->column;
    }
};


#endif //BACKEND_BALL_H
