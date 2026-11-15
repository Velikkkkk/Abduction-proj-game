#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>

using namespace std;

class Player {
private:
    int hp = 3;
    vector<string> inventory;

public:
    int getHP() const;

    void addItem(const string& item);

    void removeItem(const string& item);

    bool hasItem(const string& item) const;

    void showInventory() const;
};

#endif
