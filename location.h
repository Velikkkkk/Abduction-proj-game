#ifndef LOCATION_H
#define LOCATION_H

#include <string>

using namespace std;

// CONCEPT 1: ABSTRACT CLASS
// Base class for all game locations.
class Location {
protected:
    string name;
    string description;

public:
    Location(const string& name, const string& description);

    string getName() const;
    string getDescription() const;

    // Pure virtual method makes Location an abstract class.
    virtual void showLocation() const = 0;

    virtual ~Location() = default;
};

// CONCEPT 2: INHERITANCE
// Forest inherits from Location.
class Forest : public Location {
public:
    Forest();

    void showLocation() const override;
};

// CONCEPT 2: INHERITANCE
// Booth inherits from Location.
class Booth : public Location {
public:
    Booth();

    void showLocation() const override;
};

#endif
