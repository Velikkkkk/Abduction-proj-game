#include "Location.h"
#include <iostream>

// LOCATION

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

// FOREST

Forest::Forest()
    : Location("FOREST", "[Forest entrance story ]") {
}

void Forest::showLocation() const {
    cout << "\n================================\n";
    cout << "              " << name << "\n";
    cout << "================================\n";

    cout << description << "\n\n";
}

// BOOTH

Booth::Booth()
    : Location("BOOTH", "[Booth story ]") {
}

void Booth::showLocation() const {
    cout << "\n================================\n";
    cout << "              " << name << "\n";
    cout << "================================\n";

    cout << description << "\n\n";
}
