//
// Created by eduardozumbadog on 5/14/21.
//

#ifndef BACKEND_FIELD_H
#define BACKEND_FIELD_H

#include "Data Structures/Matrix.h"
#include "Box/Box.h"
#include "Box/NormalBox.h"
#include "Box/ObstacleBox.h"
#include "Box/GoalLineBox.h"
#include "Box/BoundBox.h"
#include "string"

using namespace std;

class Field {
private:
    Matrix *matrix;
    int length;
    int height;

public:
    Field(int height, int length) {
        this->height = height;
        this->length = length;
        this->matrix = new Matrix(this->height, this->length);
    }

    void generateField() {


        for (int i = 0; i < this->length; i++) {
            matrix->add(0, i, new BoundBox());
            matrix->add(this->height-1, i, new BoundBox());
        }
        for (int i = 0; i < this->height; ++i) {
            //todo: ajustar dependiendo del tamaño fijo de la cancha.
            if (i <= 5 and i >= 3) {
                matrix->add(i, 0, new GoalLineBox());
                matrix->add(i, this->length-1, new GoalLineBox());
            } else {
                matrix->add(i, 0, new BoundBox());
                matrix->add(i, this->length-1, new BoundBox());
            }


        }
    }

    void show() {
        this->matrix->show();

    }
};


#endif //BACKEND_FIELD_H
