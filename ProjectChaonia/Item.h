#ifndef ITEM_H
#define ITEM_H

#include <iostream>

class Item {
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

#endif // ITEM_H