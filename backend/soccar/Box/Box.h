//
// Created by eduardozumbadog on 5/14/21.
//

#ifndef BACKEND_BOX_H
#define BACKEND_BOX_H


#include <ostream>

class Box {
private:
    //Position to draw the box in
    int pos_x;
    //Position to draw the box in
    int pos_y;
public:
    virtual ~Box() = default;
    friend ostream &operator<<(ostream &os, const Box &box) {
        os << "pos_x: " << box.pos_x << " pos_y: " << box.pos_y;
        return os;
    }

public:
    int getPosX() const {
        return pos_x;
    }

    int getPosY() const {
        return pos_y;
    }
};


#endif //BACKEND_BOX_H
