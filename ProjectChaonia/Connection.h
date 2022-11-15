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
    Room* roomToPtr;
    bool connected; // states if the connection has been completed
    bool& isOpen;
    bool& isWall;
public:
    /**
     * Creates a connection with a custom open parameter
     * @param roomTo the name of the room to connect to
     * @param isOpen if the room is open
     */
    Connection(string& roomTo, bool& isOpen) {

    }

    /**
     * Creates an open connection
     * @param roomTo the name of the room to connect to
     */
    Connection(string& roomTo) {
        this->isWall = false;
        this->isOpen = true;

        this->connected = false;

        this->roomToName = roomTo;
    }

    /**
     * Creates a closed connection (room (which does not exist) will be called "NULL")
     */
    Connection() { isWall = true; isOpen = false; roomToPtr = NULL; roomToName = "NULL"; connected = true; }

    /**
     * Traverses through the connection, providing the room the connection links to
     * @return Reference to the room the connection links to
     */
    Room& traverse();

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

    // TODO: Determine if using these makes sense, since most flags should be global to allow for multiple use? This could work if it means it affects both sides of the door too

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
