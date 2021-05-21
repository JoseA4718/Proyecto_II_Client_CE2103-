//
// Created by eduardozumbadog on 20/5/21.
//

#ifndef BACKEND_SHOOT_H
#define BACKEND_SHOOT_H
#include "string"
#include "../lib/rapidjson/rapidjson.h"
#include "../lib/rapidjson/document.h"
#include "../lib/rapidjson/writer.h"
#include "../lib/rapidjson/stringbuffer.h"

class Shoot {
    int strength;
    int dir_x;
public:
    int getStrength() const {
        return strength;
    }

    void setStrength(int strength) {
        Shoot::strength = strength;
    }

    int getDirX() const {
        return dir_x;
    }

    void setDirX(int dirX) {
        dir_x = dirX;
    }

    int getDirY() const {
        return dir_y;
    }

    void setDirY(int dirY) {
        dir_y = dirY;
    }

    bool Deserialize(string str) {
        rapidjson::Document obj;
        obj.Parse(str.c_str());
        this->setDirX(obj["dir_x"].GetInt());
        this->setDirY(obj["dir_y"].GetInt());
        this->setStrength(obj["strength"].GetInt());


        return true;
    }

    bool Serialize(rapidjson::Writer<rapidjson::StringBuffer> *writer) {

        writer->StartObject();

        writer->String("dir_x");
        writer->Int(this->dir_x);
        writer->String("dir_y");
        writer->Int(this->dir_y);
        writer->String("strength");
        writer->Int(this->strength);

        writer->EndObject();

        return true;
    }

private:
    int dir_y;
};



#endif //BACKEND_SHOOT_H