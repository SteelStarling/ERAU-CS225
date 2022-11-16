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
    static Connection wallConnection = new Connection(); // set a static wall connection to prevent *too much* memory hogging
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

    /**
     * Creates a new Room, with the given name and description, and all directions blocked off
     * @param name the name of the room
     * @param desc the room's description
     */
    Room(string name, string desc) : Object(name, desc) {
        for(Direction dir = NORTH; dir <= DOWN; dir++) { // default to all rooms being a wall
            adjacentRooms[dir] = wallConnection;
        }
    }

    /**
     * Creates a new room, with the given name and default description, and all directions blocked off
     * @param name
     */
    Room(string name) : Object(name) {
        for(Direction dir = NORTH; dir <= DOWN; dir++) { // default to all rooms being a wall
            adjacentRooms[dir] = wallConnection;
        }
    }

    /**
     * Set connected room
     * @param adjacentRoom the room to add to the connection
     * @param d the direction to add the room to
     * @param open if the connection is currently open
     */
    void setConnectedRoom(Room& adjacentRoom, Direction d, bool& open = true) {
        Connection c(adjacentRoom
    }

    /**
     * Sets the connection
     * @param connection the connection to set
     * @param d the direction of the connection to set
     */
    void setConnection(Connection& connection, Direction d) { adjacentRooms[d] = connection; }

    /**
     * Gets the room in the corresponding direction
     * @param d Direction to delete connection in
     * @return Reference to room the
     */
    Room& getConnectedRoom(Direction d) const {}

    /**
     * Deletes the connection in the corresponding direction
     * @param d Direction to delete connection in
     */
    void deleteConnection(Direction d) {}
};


#endif //PROJECTCHAONIA_ROOM_H