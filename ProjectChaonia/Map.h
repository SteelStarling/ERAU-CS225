//
// Created by thanc on 10/31/2022.
//

#ifndef PROJECTCHAONIA_MAP_H
#define PROJECTCHAONIA_MAP_H

#include <unordered_map>
#include <vector>
#include "Room.h"

class Map {
private:
    static vector<Room> rooms; // holds every room
    static unordered_map<string, Room&> map; // helps find every room
public:
    void addRoom(string name, Room& room) {
        rooms.push_back(room);
        map[name] = room;
    }
};


#endif //PROJECTCHAONIA_MAP_H
