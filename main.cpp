#include <SFML/Graphics.hpp>
#include <thread>
#include "Views/MainWindow.h"



void runClient(){
    Client::getInstance()->initClient();
}

void runGUI(){
    MainWindow *window = new MainWindow();
    window->start();
}

int main() {
    thread Client (runClient);
    thread Interface (runGUI);


    Client.join();
    Interface.join();



    return 0;
}