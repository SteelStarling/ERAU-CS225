//
// Created by thanc on 11/06/22.
//

#include "Connection.h"

Connection::Connection(Room& roomTo, bool& openFlag) {
    this->roomTo = roomTo;
    this->roomToName = roomTo.getName();
}

Room& Connection::traverse();

bool Connection::getFlag();

void Connection::setFlag(bool& openFlag);