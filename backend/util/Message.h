//
// Created by eduardozumbadog on 5/19/21.
//

#ifndef PROYECTO_II_CLIENT_CE2103__MESSAGE_H
#define PROYECTO_II_CLIENT_CE2103__MESSAGE_H

#include "string"
#include "../lib/rapidjson/rapidjson.h"
#include "../lib/rapidjson/document.h"
#include "../lib/rapidjson/writer.h"
#include "../lib/rapidjson/stringbuffer.h"
using namespace std;

class Message {
private:
    string body;
    string request;
public:
    const string &getBody() const {
        return body;
    }

    void setBody(const string &body) {
        Message::body = body;
    }

    const string &getRequest() const {
        return request;
    }

    void setRequest(const string &request) {
        Message::request = request;
    }

public:
    bool Serialize(rapidjson::Writer <rapidjson::StringBuffer> *writer) {
        writer->StartObject();

        writer->String("body");
        writer->String(this->getBody().c_str());
        writer->String("request");
        writer->String(this->getRequest().c_str());

        writer->EndObject();

        return true;
    }

    bool Deserialize(const string& string1) {
        rapidjson::Document obj;
        obj.Parse(string1.c_str());
        this->setBody(obj["body"].GetString());
        this->setRequest(obj["request"].GetString());

        return true;
    }
};


#endif //PROYECTO_II_CLIENT_CE2103__CLIENT_H
