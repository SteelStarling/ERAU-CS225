//
// Created by thanc on 10/31/2022.
//

#include <iostream>
#include "Room.h"

void Room::setDirection(Room* adjacentRoom, Direction d) {
    adjacentRooms[d] = new Connection(adjacentRoom);
}

Connection& Room::getDirection(Direction d) {
    return adjacentRooms[d];
}

void Room::deleteDirection(Direction d) {
    adjacentRooms[d] = nullptr;
}
