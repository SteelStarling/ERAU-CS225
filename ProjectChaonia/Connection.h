//
// Created by thanc on 11/06/22.
//

#ifndef PROJECTCHAONIA_CONNECTION_H
#define PROJECTCHAONIA_CONNECTION_H


#include "Room.h"
#include "Map.h"

class Connection {
private:
    static Map* map; // holds the map, meaning you can see every room that exists and find the matching Room*
    string roomToName;
    Room* roomToPtr;
    bool* openFlag;
public:
    Connection(string* roomTo);
    Connection(string* roomTo, bool* openFlag);

    Room* traverse();



    bool getFlag();

    void setFlag(bool* openFlag);
};


#endif //PROJECTCHAONIA_CONNECTION_H
