//
// Created by josea4718 on 5/20/21.
//

#ifndef PROYECTO_II_CLIENT_CE2103__SERVERCONNECTION_H
#define PROYECTO_II_CLIENT_CE2103__SERVERCONNECTION_H

#include "Client.h"
#include "../backend/util/Response.h"

class ServerConnection {
    /**
     * Receives a Message.h in Json format, send it to the server and waits for its response.
     * @param message Json format of Message.
     * @return Response from the server.
     */
public:
    static Response *sendMessage(string message) {

        Client::getInstance()->Send(message.c_str());
        string response;
        while (response.empty()) {
            response = Client::getInstance()->getMessage();
        }
        Client::getInstance()->setMessage("");

        Response *result = new Response();
        result->Deserialize(response);
        return result;
    }
};

#endif //PROYECTO_II_CLIENT_CE2103__SERVERCONNECTION_H
