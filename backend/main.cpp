#include <iostream>
#include "soccar/Field.h"
#include "soccar/Box/NormalBox.h"

int main() {
    Matrix *matrix = new Matrix(9, 18);


    auto *player = new ObstacleBox();
    for (int i = 0; i < 18; i++) {
        matrix->add(0, i, new BoundBox());
        matrix->add(8, i, new BoundBox());
    }
    for (int i = 0; i < 9; ++i) {
        if (i <= 5 and i >= 3) {
            matrix->add(i, 0, new GoalLineBox());
            matrix->add(i, 17, new GoalLineBox());
        } else {
            matrix->add(i, 0, new BoundBox());
            matrix->add(i, 17, new BoundBox());
        }


    }
    for (int i = 3; i < 7; ++i) {
        matrix->add(i, 2, new ObstacleBox());
        matrix->add(i, 15, new ObstacleBox());

    }
    matrix->show();

    return 0;
}
