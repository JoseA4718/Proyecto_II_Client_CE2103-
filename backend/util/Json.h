//
// Created by josea4718 on 5/20/21.
//

#ifndef PROYECTO_II_CLIENT_CE2103__JSON_H
#define PROYECTO_II_CLIENT_CE2103__JSON_H


#include "../lib/rapidjson/stringbuffer.h"
#include "../lib/rapidjson/writer.h"
#include "../lib/rapidjson/document.h"
#include "Response.h"
#include "Message.h"
#include "../soccar/Path.h"

using namespace std;
using namespace rapidjson;

class Json {
public:

    /**
     * @brief Convert from Path.h to string json.
     * @param path instance to convert
     * @return Json format of the instance.
     */
    static string convertPath(Path *path) {
        Document generated_json;
        generated_json.SetArray();
        Document::AllocatorType &allocator = generated_json.GetAllocator();
        StringBuffer strbuf;
        Writer<rapidjson::StringBuffer> writer(strbuf);
        path->Serialize(&writer);

        return strbuf.GetString();

    }

    /**
     * @brief Convert from Route.h to string
     * @param route instance to convert
     * @return Json format of the instance.
     */
    static string convertRoute(Route *route) {

        Document generated_json;
        generated_json.SetArray();
        Document::AllocatorType &allocator = generated_json.GetAllocator();
        StringBuffer strbuf;
        Writer<rapidjson::StringBuffer> writer(strbuf);
        route->Serialize(&writer);

        return strbuf.GetString();
    }

    /**
     * @brief Convert from Response.h to string json.
     * @param response instance to convert
     * @return Json format of the instance.
     */
    static string convertResponse(Response *response) {
        Document generated_json;
        generated_json.SetArray();
        Document::AllocatorType &allocator = generated_json.GetAllocator();
        StringBuffer strbuf;
        Writer<rapidjson::StringBuffer> writer(strbuf);
        response->Serialize(&writer);

        return strbuf.GetString();
    }

    /**
     * @brief Convert from Message.h to string json.
     * @param response instance to convert
     * @return Json format of the instance.
     */
    static string convertMessage(Message *message) {
        Document generated_json;
        generated_json.SetArray();
        Document::AllocatorType &allocator = generated_json.GetAllocator();
        StringBuffer strbuf;
        Writer<rapidjson::StringBuffer> writer(strbuf);
        message->Serialize(&writer);

        return strbuf.GetString();
    }

    /**
     * @brief Convert from Shoot.h to string json.
     * @param response instance to convert
     * @return Json format of the instance.
     */
    static string convertShot(Shoot *shoot) {
        Document generated_json;
        generated_json.SetArray();
        Document::AllocatorType &allocator = generated_json.GetAllocator();
        StringBuffer strbuf;
        Writer<rapidjson::StringBuffer> writer(strbuf);
        shoot->Serialize(&writer);

        return strbuf.GetString();
    }
};


#endif //PROYECTO_II_CLIENT_CE2103__JSON_H
