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
    void setRow(int row) {
        Ball::row = row;
    }

    void setColumn(int column) {
        Ball::column = column;
    }

private:
    int posX;
    int posY;

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
    int getPosX() const {
        return posX;
    }

    void setPosX(int posX) {
        Ball::posX = posX;
    }

    int getPosY() const {
        return posY;
    }

    void setPosY(int posY) {
        Ball::posY = posY;
    }

};


#endif //BACKEND_BALL_H
