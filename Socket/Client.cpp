//
// Created by josea4718 on 5/20/21.
//

#include "Client.h"

Client* Client::unique_instance = NULL;
Client::Client() {}


/**
 * Singleton instance of the client
 * @return returns the unique instance of the client
 */
Client *Client::getInstance() {
    if (unique_instance == NULL){
        unique_instance = new Client();
    }
    return unique_instance;
}

const string &Client::getMessage() const {
    return message;
}

void Client::setMessage(const string &message) {
    Client::message = message;
}
