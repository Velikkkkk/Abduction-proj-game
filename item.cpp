
#include "Item.h"

Item::Item(const string& name) {
    this->name = name;
}

string Item::getName() const {
    return name;
}
