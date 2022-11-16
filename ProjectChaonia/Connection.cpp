//
// Created by thanc on 11/06/22.
//

#include "Connection.h"

Connection::Connection(string& roomTo, bool* isOpen) {
    this->isWall = false;
    this->isOpen = isOpen; // store pointer
    this->roomToName = roomTo;
}

Connection::Connection(string& roomTo) : isOpen(){
    this->isWall = false;
    *(this->isOpen) = true;
    this->roomToName = roomTo;
}

Connection::Connection() {
    isWall = true;
    *(isOpen) = false;
    roomToName = "NULL";
}

Room& Connection::traverse() {
    if(map.find(roomToName) == map.end()) {
        throw "Room Does Not Exist";
    } else {
        return map[roomToName];
    }
}