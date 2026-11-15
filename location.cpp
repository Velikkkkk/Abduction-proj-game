
#include "Location.h"
#include <iostream>

Location::Location(const string& name, const string& description) {
    this->name = name;
    this->description = description;
}

string Location::getName() const {
    return name;
}

string Location::getDescription() const {
    return description;
}

void Location::showLocation() const {
    cout << "\n================================\n";
    cout << "          " << name << "\n";
    cout << "================================\n";

    cout << description << "\n";
}
