#include "Item.h"

// Constructor
Item::Item(const string& name) {
    this->name = name;
}

// Returns item name
string Item::getName() const {
    return name;
}

// CONCEPT 4: OPERATOR OVERLOADING

// Equality comparison
bool Item::operator==(const Item& other) const {
    return name == other.name;
}

// Inequality comparison
bool Item::operator!=(const Item& other) const {
    return name != other.name;
}

// Alphabetical comparison
bool Item::operator<(const Item& other) const {
    return name < other.name;
}
