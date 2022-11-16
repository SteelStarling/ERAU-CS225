//
// Created by thanc on 10/31/2022.
//

#ifndef PROJECTCHAONIA_PLAYER_H
#define PROJECTCHAONIA_PLAYER_H


#include <iostream>
#include "Character.h"
#include "Room.h"
#include "Map.h"


class Player : public Character {
private:
    Room& location;
    int points;
    int health;
public:
    Room& getLocation() const {
        return location;
    }

    void setLocation(Room& location) {
        Player::location = location;
    }

    int getPoints() const {
        return points;
    }

    void setPoints(int points) {
        Player::points = points;
    }

    int getHealth() const {
        return health;
    }

    void setHealth(int health) {
        Player::health = health;
    }
};


#endif //PROJECTCHAONIA_PLAYER_H
