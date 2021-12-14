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
            MOVE = 5
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

    class ZoneHandler : public EventHandler {
    public:
        enum Type {
            CREATE_ZONE = 1
        };

        bool CanHandle(EventMessage *event) override {
            if (event->getType() == ZoneHandler::CREATE_ZONE) {
                return true;
            } else return false;
        }

        void Handler(EventMessage *event, DrawMap *map) override {
            map->SetZone(event->getX(),event->getY(),event->getData());
        }


    };

    class PlayerHandler : public EventHandler {
    public:
        enum Type {
            CREATE_PLAYER = 2
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
            CREATE_OBJECT = 3
        };

        bool CanHandle(EventMessage *event) override {
            if (event->getType() == ObjectHandler::CREATE_OBJECT) {
                return true;
            } else return false;
        }

        void Handler(EventMessage *event, DrawMap *map) override {
            map->SetBlocks(event->getID() , event->getX(), event->getY());
        }


    };

    class HealthHandler : public EventHandler {
    public:
        enum Type {
            SET_HEALTH = 4
        };

        bool CanHandle(EventMessage *event) override {
            if (event->getType() == HealthHandler::SET_HEALTH) {
                return true;
            } else return false;
        }

        void Handler(EventMessage *event, DrawMap *map) override {
            map->SetHp(event->getID(), event->getData());
        }


    };

    class DeleteHandler : public EventHandler {
    public:
        enum Type {
            DELETE = 6
        };

        bool CanHandle(EventMessage *event) override {
            if (event->getType() == DeleteHandler::DELETE) {
                return true;
            } else return false;
        }

        void Handler(EventMessage *event, DrawMap *map) override {
            map->SetBlocks(event->getID(), event->getX(), event->getY());
        }


    };

    class WinHandler : public EventHandler {
    public:
        enum Type {
            WIN_TEAM = 7
        };

        bool CanHandle(EventMessage *event) override {
            if (event->getType() == WinHandler::WIN_TEAM) {
                return true;
            } else return false;
        }

        void Handler(EventMessage *event, DrawMap *map) override {

        }


    };


}

#endif //TEST_DRAWHANDLERS_H
