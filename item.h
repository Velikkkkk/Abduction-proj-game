
#ifndef ITEM_H
#define ITEM_H

#include <string>

using namespace std;

class Item {
private:
    string name;

public:
    Item(const string& name);

    string getName() const;
};

#endif
