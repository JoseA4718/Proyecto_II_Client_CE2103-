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
        this->generateField();
    }

    void generateField() {
        for (int i = 1; i <= this->length; i++) {
            BoundBox *bound1 = new BoundBox();
            BoundBox *bound2 = new BoundBox();
            bound1->setRow(1);
            bound1->setColumn(i);

            bound2->setRow(this->height);
            bound2->setColumn(i);

            matrix->add(1, i, bound1);
            matrix->add(this->height, i, bound2);
        }
        for (int i = 1; i <= this->height; i++) {
            if (i <= 6 and i >= 4) {
                GoalLineBox *goal1 = new GoalLineBox();
                GoalLineBox *goal2 = new GoalLineBox();

                goal1->setRow(i);
                goal1->setColumn(1);
                goal2->setRow(i);
                goal2->setColumn(this->length);

                matrix->add(i, 1, goal1);
                matrix->add(i, this->length, goal2);

            } else {
                BoundBox *bound1 = new BoundBox();
                BoundBox *bound2 = new BoundBox();
                bound1->setRow(i);
                bound1->setColumn(1);

                bound2->setRow(i);
                bound2->setColumn(this->height);

                matrix->add(i, 1, bound1);
                matrix->add(i, this->length, new BoundBox());
            }
        }
    }

    void setPositions(){
        double height = 144;
        double width = 358;
        for (int i = 1; i <= this->height; i++) {
            for (int j = 1; j <= this->length; j++) {
                matrix->get(i, j)->setCoordinates(width, height);
                width += 68.85;
                //matrix->get(i, j)->show();
            }
            height += 68.85;
            width = 358;
        }
    }

    Matrix *getMatrix(){
        return this->matrix;
    }

    void show() {
        this->matrix->show();

    }
    void generateObstacles(LinkedList<Box*> *list){
        for (int i = 0; i < list->len; i++) {

            ObstacleBox *ob1;
            ob1 = new ObstacleBox();

            Box *pBox = list->get(i);
            pBox->show();

            int row = pBox->getRow();
             int column = pBox->getColumn();

            ob1->setRow(row);
            ob1->setColumn(column);

            matrix->add(row, column, ob1);
        }
    }
};


#endif //BACKEND_FIELD_H
