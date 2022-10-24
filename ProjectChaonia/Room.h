#include <iostream>

class Room {
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
};