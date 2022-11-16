//
// Created by thanc on 10/31/2022.
//

#ifndef PROJECTCHAONIA_PLAYER_H
#define PROJECTCHAONIA_PLAYER_H


#include <iostream>
#include "Character.h"
#include "Room.h"


class Player : public Character {
private:
    Room* location;
    int points;
    int health;
public:
    Room* getLocation() const {
        return location;
    }

    void setLocation(Room* location) {
        this->location = location;
    }

    int getPoints() const {
        return points;
    }

    void setPoints(int points) {
        this->points = points;
    }

    int getHealth() const {
        return health;
    }

    void setHealth(int health) {
        this->health = health;
    }
};


#endif //PROJECTCHAONIA_PLAYER_H
