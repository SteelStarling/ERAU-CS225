//
// Created by thanc on 11/06/22.
//

#ifndef PROJECTCHAONIA_CONNECTION_H
#define PROJECTCHAONIA_CONNECTION_H


#include "Room.h"
#include "Map.h"


class Connection {
private:
    static Map& map; // holds the map, meaning you can see every room that exists and find the matching Room*
    string roomToName;
    bool& isOpen;
    bool isWall; // says if the connection is an unopenable wall (isOpen does not matter)
public:
    /**
     * Creates a connection with a custom open parameter
     * @param roomTo the name of the room to connect to
     * @param isOpen if the room is open
     */
    Connection(string& roomTo, bool& isOpen) { this->isWall = false; this->isOpen = isOpen; this->roomToName = roomTo; }

    /**
     * Creates an open connection
     * @param roomTo the name of the room to connect to
     */
    Connection(string& roomTo) { this->isWall = false; this->isOpen = true; this->roomToName = roomTo; }

    /**
     * Creates a closed connection (room (which does not exist) will be called "NULL")
     */
    Connection() { isWall = true; isOpen = false; roomToName = "NULL"; }

    /**
     * Traverses through the connection, providing the name of the room the connection links to
     * @return Name of the room the connection links to
     */
    string traverse() { return roomToName; }

    /**
     * Checks if the connection is open
     * @return true if open, false if not
     */
    bool isOpen() { return isOpen; }

    /**
     * Checks if the connection is a wall
     * @return true if a wall, false if not
     */
    bool isWall() { return isWall; }

    /**
     * Sets the connection to be opened or closed, based on the provided flag pointer (meaning it can be modified elsewhere)
     * @param isOpen
     */
    void setOpen(bool& isOpen) { this->isOpen = isOpen; }

    /**
     * Sets the connection to be opened
     */
    void setOpen() { isOpen = true; }

    /**
     * Sets the connection to be closed
     */
    void setClosed() { isOpen = false; }
};


#endif //PROJECTCHAONIA_CONNECTION_H
