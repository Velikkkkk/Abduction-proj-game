
#ifndef LOCATION_H
#define LOCATION_H

#include <string>

using namespace std;

class Location {
private:
    string name;
    string description;

public:
    Location(const string& name, const string& description);

    string getName() const;

    string getDescription() const;

    void showLocation() const;
};

#endif
