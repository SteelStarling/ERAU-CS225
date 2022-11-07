//
// Created by thanc on 10/31/2022.
//

#ifndef PROJECTCHAONIA_OBJECT_H
#define PROJECTCHAONIA_OBJECT_H

#include <iostream>
#include "CommandList.h"
using namespace std;

class Object {
private:
    string name;
    string description;
    unordered_map<string, &Command> commandList;

public:
    Object(string name, string description, unordered_map<string, &Command> commandList) {
        this->name = name;
        this->description = description;
        this->commandList = commandList;
    }

    Object(string name, string description) {
        this->name = name;
        this->description = description;
        this->commandList = new unordered_map<string, &Command>();
    }

    Object(string name) {
        this->name = name;
        this->description = "Just a perfectly normal " + name + "\n";
        this->commandList = new unordered_map<string, &Command>();
    }

};


#endif //PROJECTCHAONIA_OBJECT_H
