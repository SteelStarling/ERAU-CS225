//
// Created by thanc on 10/31/2022.
//

#ifndef PROJECTCHAONIA_ROOM_H
#define PROJECTCHAONIA_ROOM_H


#include <iostream>
#include "Object.h"

class Room : public Object {
private:
    Room* adjacentRooms[10];
public:
    enum Direction {
        EMPTY = 0,
        NORTH = 1,
        NORTHEAST = 2,
        EAST = 3,
        SOUTHEAST = 4,
        SOUTH = 5,
        SOUTHWEST = 6,
        WEST = 7,
        NORTHWEST = 8,
        UP = 9,
        DOWN = 10
    };

    Room();

    void setDirection(Room* adjacentRoom, Direction d);

    Room* getDirection(Direction d);

    void deleteDirection(Direction d);
};


#endif //PROJECTCHAONIA_ROOM_H