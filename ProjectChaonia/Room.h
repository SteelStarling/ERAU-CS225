#ifndef ROOM_H
#define ROOM_H

#include <iostream>

class Room extends Item {
    private:
        Room* adjacentRooms[10];
    public:
        enum Direction {
            NORTH = 0,
            NORTHEAST = 1,
            EAST = 2,
            SOUTHEAST = 3,
            SOUTH = 4,
            SOUTHWEST = 5,
            WEST = 6,
            NORTHWEST = 7,
            UP = 8,
            DOWN = 9
        };

        Room();

        void setDirection(Room* adjacentRoom, Direction d);

        Room* getDirection(Direction d);

        void deleteDirection(Direction d);
};

#endif // ROOM_H