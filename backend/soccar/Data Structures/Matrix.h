//
// Created by eduardozumbadog on 5/14/21.
//
#include "LinkedList.h"

#ifndef BACKEND_MATRIX_H
#define BACKEND_MATRIX_H

template<typename T>
class Matrix {

private:
    int columns;// vertical lines in the matrix

    int rows; // horizontal lines in the matrix

    LinkedList<LinkedList<T> *> *list;
public:
    Matrix(int rows, int columns) {
        this->rows = rows;
        this->columns = columns;
        this->list = new LinkedList<LinkedList<T> *>();
        //add the horizontal rows
        for (int i = 0; i < rows; ++i) {
            auto *newRow = new LinkedList<T>();
            for (int j = 0; j < columns; ++j) {
                newRow->append(0);
            }
            this->list->append((newRow));
        }
        //las horizontales se manejan revisando que el len de las listas no exceda el de la cantidad de columnas.
        // quedaría algo como asi:
        // [a, b, c]
        // [d, e, f]
        // [g, h, i]
    }

    /**
     * Method for adding an element in the matrix position (i, j)
     * @param row i position of the new element on the matrix, must be minor to the rows field set in the constructor
     * @param column j position of the element.
     * @param element to be added on the matrix
     */
    void add(int row, int column, T element) {
        if (row >= this->rows or column >= this->columns) {
            cerr << "Element: " << element << " not added, index out of range" << endl;
            return;
        }

        else {
            LinkedList<T> *matrix_row = this->list->get(row);
            matrix_row->append(element, column);
        }
    }

    void show() {
        for (int i = 0; i < this->rows; i++) {
            this->list->get(i)->show();

        }
    }
};


#endif //BACKEND_MATRIX_H
