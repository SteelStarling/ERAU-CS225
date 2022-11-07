//
// Created by thanc on 10/31/2022.
//

#ifndef PROJECTCHAONIA_ITEM_H
#define PROJECTCHAONIA_ITEM_H


#include "Object.h"
#include <iostream>

class Item : public Object {
    private:
        std::string name;
        std::string description;
    public:
        Item();
        void setName(string name);
        void setDescription(string description);
        string getName();
        string getDescription();
};


#endif //PROJECTCHAONIA_ITEM_H