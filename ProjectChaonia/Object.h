//
// Created by thanc on 10/31/2022.
//

#ifndef PROJECTCHAONIA_OBJECT_H
#define PROJECTCHAONIA_OBJECT_H

#include <iostream>
#include <unordered_map>
#include "Command.h"
using namespace std;

class Object {
private:
    string name;
    string description;
    unordered_map<string, &Command> commandList;

public:
    /**
     * Creates a new object with a given name, description, and list of commands
     * @param name the name of the object
     * @param description the description of the object
     * @param commandList
     */
    Object(string name, string description, unordered_map<string, &Command> commandList) {
        this->name = name;
        this->description = description;
        this->commandList = commandList;
    }

    /**
     * Creates a new object with a given name and description
     * @param name the name of the object
     * @param description the description of the object
     */
    Object(string name, string description) {
        this->name = name;
        this->description = description;
    }

    /**
     * Creates a new object with a given name, and the default description for something unremarkable
     * @param name the name of the object
     */
    Object(string name) {
        this->name = name;
        this->description = "Just a perfectly normal " + name + ", it is completely unremarkable.\n";
    }

    /**
     * Gets the name of the object
     * @return the name of the object
     */
    string getName() const { return name; }

    /**
     * Gets the description of the object
     * @return the description of the object
     */
    string getDescription() const { return description; }

    /**
     *
     * @param command
     * @param name
     */
    void addCommand(Command command, string name) { commandList[name] = command; }

    unordered_map<string, &Command> getCommandList() { return commandList; }

    Command& getCommand(string name) const { return commandList[name]; }


};


#endif //PROJECTCHAONIA_OBJECT_H
