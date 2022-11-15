//
// Created by thanc on 10/31/2022.
//

#ifndef PROJECTCHAONIA_OBJECT_H
#define PROJECTCHAONIA_OBJECT_H

#include <iostream>
#include "Command.h"
#include <unordered_map>
using namespace std;

class Object {
private:
    string name;
    string description;
    unordered_map<string, &Command> commandList;

public:
    /**
     * Creates a new object with a given name, description, and list of commands
     * @param name
     * @param description
     * @param commandList
     */
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

    string getName() { return name; }

    string getDescription() { return description; }

    void addCommand(Command command, string name) { commandList[name] = command; }

    unordered_map<string, &Command> getCommandList() { return commandList; }

    Command& getCommand(string name) { return commandList[name]; }


};


#endif //PROJECTCHAONIA_OBJECT_H
