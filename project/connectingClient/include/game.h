//
// Created by ilyas on 07.12.2021.
//

#ifndef PROJECT_TP_GAME_H
#define PROJECT_TP_GAME_H

#include "Application.h"
#include "clientNetwork.h"

class Game {
public:
    Game();
    ~Game();
    void Iteration();

private:
    enum State {
        INIT = 0,
        WAITING_FOR_GAME = 1,
        STARTED = 2,
        GAME_OVER = 3,
        END_OF_GAME = 4
    };

    Client *client;
    State state;
    Application app;
    std::queue<EventMessage> *event;
    std::queue<BaseMessage> *request;
};

#endif //PROJECT_TP_GAME_H
