#ifndef ITEM_H
#define ITEM_H

#include <string>

using namespace std;

class Item {
private:
    string name;

public:
    // Constructor
    Item(const string& name);

    // Returns the name of the item
    string getName() const;

    // CONCEPT 4: OPERATOR OVERLOADING
    // Compares two items by their names.
    bool operator==(const Item& other) const;

    // Checks if two items have different names.
    bool operator!=(const Item& other) const;

    // Compares item names alphabetically.
    bool operator<(const Item& other) const;
};

#endif
