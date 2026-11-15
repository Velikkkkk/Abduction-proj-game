#include "Player.h"
#include <iostream>

int Player::getHP() const {
    return hp;
}

// ADD ITEM TO INVENTORY

void Player::addItem(const string& item) {
    inventory.push_back(item);
}

// REMOVE ITEM FROM INVENTORY

void Player::removeItem(const string& item) {
    for (size_t i = 0; i < inventory.size(); i++) {
        if (inventory[i] == item) {
            inventory.erase(inventory.begin() + i);
            return;
        }
    }
}

// CHECK IF PLAYER HAS AN ITEM

bool Player::hasItem(const string& item) const {
    for (const string& currentItem : inventory) {
        if (currentItem == item) {
            return true;
        }
    }

    return false;
}

// SHOW INVENTORY

void Player::showInventory() const {
    cout << "Inventory: ";

    if (inventory.empty()) {
        cout << "Empty";
    } else {
        for (size_t i = 0; i < inventory.size(); i++) {
            if (i > 0) {
                cout << ", ";
            }

            cout << inventory[i];
        }
    }

    cout << '\n';
}