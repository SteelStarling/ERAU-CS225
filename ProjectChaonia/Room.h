//
// Created by thanc on 10/31/2022.
//

#ifndef PROJECTCHAONIA_ROOM_H
#define PROJECTCHAONIA_ROOM_H


#include <iostream>
#include "Object.h"
#include "Connection.h"

class Room : public Object {
private:
    Connection adjacentRooms[10];
public:
    enum Direction {
        NORTH,
        NORTHEAST,
        EAST,
        SOUTHEAST,
        SOUTH,
        SOUTHWEST,
        WEST,
        NORTHWEST,
        UP,
        DOWN
    };

    Room(string name, string desc) {

    }

    Room(string name) {

    }

    /**
     * Set connected room
     * @param adjacentRoom the room to add to the connection
     * @param d the direction to add the room to
     * @param open if the connection is currently open
     */
    void setConnectedRoom(Room& adjacentRoom, Direction d, bool& open = true) {

    }

    /**
     * Sets the connection
     * @param connection the connection to set
     * @param d the direction of the connection to set
     */
    void setConnection(Connection& connection, Direction d) {
        adjacentRooms[d] = connection;
    }

    int updateConnections() {
        int numBad = 0;

        for(Direction dir = NORTH; dir <= DOWN; dir++) {
            if(!adjacentRoom[dir].isWall() && adjacentRoom[dir].) { // only worry about invalid passages, walls are fine (should never be traversed)
                numBad +=
            }
        }

        return numBad;
    }


    /**
     * Gets the room in the corresponding direction
     * @param d Direction to delete connection in
     * @return Reference to room the
     */
    Room& getConnectedRoom(Direction d);

    /**
     * Deletes the connection in the corresponding direction
     * @param d Direction to delete connection in
     */
    void deleteConnection(Direction d);
};


#endif //PROJECTCHAONIA_ROOM_H