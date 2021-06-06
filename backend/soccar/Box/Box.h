//
// Created by eduardozumbadog on 5/14/21.
//

#ifndef BACKEND_BOX_H
#define BACKEND_BOX_H


#include <ostream>
#include "../../lib/rapidjson/rapidjson.h"
#include "../../lib/rapidjson/document.h"
#include "../../lib/rapidjson/writer.h"
#include "../../lib/rapidjson/stringbuffer.h"
/**
 * @brief Abstract class for the different types of segments in the field.
 */
class Box {
private:
    //Position to draw the box in
    int pos_x;
    //Position to draw the box in
    int pos_y;
    //
    int row;
    int column;
    bool hasBall = false;
public:
    bool isHasBall() const {
        return hasBall;
    }

    void setHasBall(bool hasBall) {
        this->hasBall = hasBall;
    }

    int getRow() const {
        return row;
    }

    void setRow(int row) {
        Box::row = row;
    }

    int getColumn() const {
        return column;
    }

    void setColumn(int column) {
        Box::column = column;
    }

    void setCoordinates(int x, int y) {
        this->pos_x = x;
        this->pos_y = y;
    }

    int getX() {
        return this->pos_x;
    }

    int getY() {
        return this->pos_y;
    }

    virtual ~Box() = default;
/**
 * @brief Method for loading the information of a json string into the object
 * @param obj rapidjson object of the string parsed into a json.
 * @return true if success
 */
    bool Deserialize(const rapidjson::Value &obj) {
        this->setRow(obj["row"].GetInt());
        this->setColumn(obj["column"].GetInt());
        return true;
    }
/**
 * @brief Method for loading the object's information into a json
 * @param writer rapidjson writer instance.
 * @return true is success.
 */
    bool Serialize(rapidjson::Writer<rapidjson::StringBuffer> *writer) {
        writer->StartObject();
        writer->String("row");
        writer->Int(this->getRow());
        writer->String("column");
        writer->Int(this->getColumn());
        writer->EndObject();
        return true;
    }

    friend ostream &operator<<(ostream &os, const Box &box) {
        os << "pos_x: " << box.pos_x << " pos_y: " << box.pos_y;
        return os;
    }

    int getPosX() const {
        return pos_x;
    }

    int getPosY() const {
        return pos_y;
    }

    void show() {
        cout << "{column: " << this->column << " row: " << this->row << " }";
    }
};


#endif //BACKEND_BOX_H
