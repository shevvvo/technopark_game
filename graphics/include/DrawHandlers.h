#ifndef TEST_DRAWHANDLERS_H
#define TEST_DRAWHANDLERS_H



#include "Map.h"
#include "Handler.h"
#include "message.h"
namespace Draw {
    class EventHandler : public BaseEventHandler<EventMessage, DrawMap> {
    };

    class MoveHandler : public EventHandler {
    public:
        enum MoveType {
            MOVE = 4
        };

        bool CanHandle(EventMessage *event) override {
            if (event->getType() == MoveHandler::MOVE) {
                return true;
            } else return false;
        }

        void Handler(EventMessage *event, DrawMap *map) override {
            map->SetUnits(event->getID(), event->getX(), event->getY());
        }


    };

    class MapHandler : public EventHandler {
    public:
        enum Type {
            CREATE_MAP = 0
        };

        bool CanHandle(EventMessage *event) override {
            if (event->getType() == MapHandler::CREATE_MAP) {
                return true;
            } else return false;
        }

        void Handler(EventMessage *event, DrawMap *map) override {
            map->DrawMapInit(event->getX(), event->getY(), event->getData());
        }


    };

    class PlayerHandler : public EventHandler {
    public:
        enum Type {
            CREATE_PLAYER = 1
        };

        bool CanHandle(EventMessage *event) override {
            if (event->getType() == PlayerHandler::CREATE_PLAYER) {
                return true;
            } else return false;
        }

        void Handler(EventMessage *event, DrawMap *map) override {
           map->DrawPlayerInit(event->getID(),event->getX(), event->getY(), event->getData());
        }


    };

    class ObjectHandler : public EventHandler {
    public:
        enum Type {
            CREATE_OBJECT = 2
        };

        bool CanHandle(EventMessage *event) override {
            if (event->getType() == ObjectHandler::CREATE_OBJECT) {
                return true;
            } else return false;
        }

        void Handler(EventMessage *event, DrawMap *map) override {
            map->SetBlocks(10, event->getX(), event->getY());
        }


    };

    class HealthHandler : public EventHandler {
    public:
        enum Type {
            SET_HEALTH = 3
        };

        bool CanHandle(EventMessage *event) override {
            if (event->getType() == HealthHandler::SET_HEALTH) {
                return true;
            } else return false;
        }

        void Handler(EventMessage *event, DrawMap *map) override {
            map->SetHp(0, event->getData());
        }


    };

    class DeleteHandler : public EventHandler {
    public:
        enum Type {
            DELETE = 5
        };

        bool CanHandle(EventMessage *event) override {
            if (event->getType() == DeleteHandler::DELETE) {
                return true;
            } else return false;
        }

        void Handler(EventMessage *event, DrawMap *map) override {
            map->SetBlocks(0, event->getX(), event->getY());
        }


    };
}

#endif //TEST_DRAWHANDLERS_H
