//
// Created by eduardozumbadog on 31/5/21.
//

#ifndef PROYECTO_II_CLIENT_CE2103__PATH_H
#define PROYECTO_II_CLIENT_CE2103__PATH_H
#include "Route.h"
#include "string"
#include "../soccar/Data Structures/Matrix.h"
#include "../soccar/Ball.h"
#include "../soccar/Field.h"

class Path {
    int start_x;
    int start_y;
public:

    int getStartX() const {
        return start_x;
    }

    void setStartX(int startX) {
        start_x = startX;
    }

    int getStartY() const {
        return start_y;
    }

    void setStartY(int startY) {
        start_y = startY;
    }

    int getEndX() const {
        return end_x;
    }

    void setEndX(int endX) {
        end_x = endX;
    }

    int getEndY() const {
        return end_y;
    }

    void setEndY(int endY) {
        end_y = endY;
    }

    bool Deserialize(const string &basicString) {
        rapidjson::Document obj;
        obj.Parse(basicString.c_str());
        this->setStartX(obj["start_x"].GetInt());
        this->setStartY(obj["start_y"].GetInt());

        this->setEndX(obj["end_x"].GetInt());
        this->setEndY(obj["end_y"].GetInt());
        return true;
    }

    bool Serialize(rapidjson::Writer <rapidjson::StringBuffer> *writer) {
        writer->StartObject();

        writer->String("start_x");
        writer->Int(this->getStartX());
        writer->String("start_y");
        writer->Int(this->getStartY());


        writer->String("end_x");
        writer->Int(this->getEndX());
        writer->String("end_y");
        writer->Int(this->getEndY());

        writer->EndObject();

        return true;
    }

private:

    int end_x;
    int end_y;
};


#endif //PROYECTO_II_CLIENT_CE2103__PATH_H
