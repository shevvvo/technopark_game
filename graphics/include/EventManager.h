//
// Created by ivan_lemon on 12/2/21.
//

#ifndef TEST_EVENTMANAGER_H
#define TEST_EVENTMANAGER_H


#include <vector>


#include "DrawHandlers.h"
namespace Draw {

    class EventManager {
    public:
        EventManager() {

            moveHandler = new MoveHandler;
            mapHandler = new MapHandler;
            zoneHandler = new ZoneHandler;
            objectHandler = new ObjectHandler;
            healthHandler = new HealthHandler;
            deleteHandler = new DeleteHandler;
            playerHandler = new PlayerHandler;

            Register(moveHandler);
            Register(mapHandler);
            Register(zoneHandler);
            Register(objectHandler);
            Register(healthHandler);
            Register(deleteHandler);
            Register(playerHandler);

        }

        ~EventManager(){
            delete moveHandler;
            delete mapHandler;
            delete zoneHandler;
            delete objectHandler;
            delete deleteHandler;
            delete healthHandler;

            delete playerHandler;



        }
        void EventHandle(EventMessage *event, DrawMap *map) {
            for (auto i: mHandlers) {
                if (i->CanHandle(event)) {
                    i->Handler(event, map);
                }
            }
        }



        void Register(EventHandler *handler) {
            mHandlers.push_back(handler);
        }

    private:
        MoveHandler *moveHandler;
        MapHandler *mapHandler;
        ZoneHandler *zoneHandler;
        HealthHandler *healthHandler;
        ObjectHandler *objectHandler;
        DeleteHandler *deleteHandler;

        PlayerHandler *playerHandler;
        std::vector<EventHandler *> mHandlers;
    };

}
#endif //TEST_EVENTMANAGER_H
