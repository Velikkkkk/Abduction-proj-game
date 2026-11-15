
#include "MainGame.h"

#include <iostream>
#include <limits>

using namespace std;

// GET CHOICE

int MainGame::getChoice() {
    int choice;

    if (!(cin >> choice)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        return -1;
    }

    return choice;
}

// LOCATION INFO

void MainGame::showLocationInfo() const {
    player.showInventory();
    cout << "HP: " << player.getHP() << "\n\n";
}

// TITLE

void MainGame::showTitle() const {
    cout << "\n================================\n";
    cout << "          Happiest Day\n";
    cout << "================================\n";
    cout << "1. Start\n";
    cout << "0. Exit\n";
    cout << "> ";
}

// BRANCH 1

void MainGame::branch1() {
    cout << "\n================================\n";
    cout << "            prestory\n";
    cout << "================================\n";

    showLocationInfo();

    cout << "Where do you want to go?\n\n";
    cout << "1. Forest\n";
    cout << "2. Booth\n";
    cout << "0. Exit\n";
    cout << "> ";

    int choice = getChoice();

    if (forestAvailable) {
        if (choice == 1) {
            currentLocation = LocationType::FirstForest;
        } else if (choice == 2) {
            cout << "\nYou cannot enter the Booth yet.\n";
            cout << "You are redirected to the Forest.\n";

            currentLocation = LocationType::FirstForest;
        } else if (choice == 0) {
            running = false;
        } else {
            cout << "\nInvalid choice. Try again.\n";
        }
    } else {
        if (choice == 1) {
            cout << "\nThe first Forest is no longer accessible.\n";
            cout << "You can only enter the Booth.\n";
        } else if (choice == 2) {
            currentLocation = LocationType::Booth;
        } else if (choice == 0) {
            running = false;
        } else {
            cout << "\nInvalid choice. Try again.\n";
        }
    }
}

// FIRST FOREST

void MainGame::firstForest() {

    if (forestStage == 0) {
        cout << "\n================================\n";
        cout << "              FOREST\n";
        cout << "================================\n";

        cout << "[Forest entrance story goes here]\n\n";

        cout << "You found:\n";
        cout << "- 2 Candles\n";
        cout << "- Stone\n";
        cout << "- Stick\n\n";

        player.addItem("Candle");
        player.addItem("Candle");
        player.addItem("Stone");
        player.addItem("Stick");

        forestStage = 1;
    }

    // STAGE 1: CHOOSE AN ITEM

    if (forestStage == 1) {
        showLocationInfo();

        cout << "[A wolf is blocking your way]\n\n";

        cout << "What do you want to use?\n";
        cout << "1. Use stone\n";
        cout << "2. Use stick\n";
        cout << "> ";

        int choice = getChoice();

        if (choice == 1) {
            player.removeItem("Stone");

            cout << "\nYou used the Stone.\n";

            forestStage = 2;
        }
        else if (choice == 2) {
            player.removeItem("Stick");

            cout << "\nYou used the Stick.\n";

            forestStage = 2;
        }
        else {
            cout << "\nInvalid choice. Try again.\n";
        }
    }

    // STAGE 2: THE NOTE

    if (forestStage == 2) {
        cout << "\n================================\n";
        cout << "            THE NOTE\n";
        cout << "================================\n";

        cout << "[You find a note attached to a tree]\n\n";

        cout << "What do you want to do?\n";
        cout << "1. Read the note\n";
        cout << "2. Ignore the note\n";
        cout << "> ";

        int choice = getChoice();

        if (choice == 1) {
            cout << "\n[Note text goes here]\n";
            forestStage = 3;
        }
        else if (choice == 2) {
            forestStage = 3;
        }
        else {
            cout << "\nInvalid choice. Try again.\n";
        }
    }

    // STAGE 3: BLOCK A

    if (forestStage == 3) {
        cout << "\n================================\n";
        cout << "             MOVING FORVARD\n";
        cout << "================================\n";

        cout << "[You finish forest]\n\n";

        cout << "1. Continue to the Booth\n";
        cout << "> ";

        int choice = getChoice();

        if (choice == 1) {
            forestAvailable = false;
            currentLocation = LocationType::Booth;
        }
        else {
            cout << "\nInvalid choice. Try again.\n";
        }
    }
}

// BOOTH

void MainGame::booth() {
    cout << "\n================================\n";
    cout << "              BOOTH\n";
    cout << "================================\n";

    showLocationInfo();

    cout << "[Booth story goes here]\n\n";

    cout << "1. Continue to the Ghost Forest\n";
    cout << "> ";

    int choice = getChoice();

    if (choice == 1) {
        currentLocation = LocationType::GhostForest;
    } else {
        cout << "\nInvalid choice. Try again.\n";
    }
}

// GHOST FOREST

void MainGame::ghostForest() {
    cout << "\n================================\n";
    cout << "          GHOST FOREST\n";
    cout << "================================\n";

    showLocationInfo();

    cout << "[Ghost forest story goes here]\n\n";

    cout << "1. Continue to the House\n";
    cout << "> ";

    int choice = getChoice();

    if (choice == 1) {
        currentLocation = LocationType::House;
    } else {
        cout << "\nInvalid choice. Try again.\n";
    }
}

// HOUSE

void MainGame::house() {
    cout << "\n================================\n";
    cout << "              HOUSE\n";
    cout << "================================\n";

    showLocationInfo();

    cout << "[House story goes here]\n\n";

    cout << "1. Continue\n";
    cout << "> ";

    int choice = getChoice();

    if (choice == 1) {
        currentLocation = LocationType::Endings;
    } else {
        cout << "\nInvalid choice. Try again.\n";
    }
}

// ENDINGS BRANCH

void MainGame::endingBranch() {
    cout << "\n================================\n";
    cout << "          FINAL CHOICE\n";
    cout << "================================\n";

    showLocationInfo();

    cout << "Choose your ending:\n\n";
    cout << "1. End1\n";
    cout << "2. End2\n";
    cout << "> ";

    int choice = getChoice();

    if (choice == 1) {
        ending.end1();
        running = false;
    } else if (choice == 2) {
        ending.end2();
        running = false;
    } else {
        cout << "\nInvalid choice. Try again.\n";
    }
}

// START GAME

void MainGame::start() {
    showTitle();

    int choice = getChoice();

    if (choice != 1) {
        cout << "\nGame closed.\n";
        return;
    }

    while (running) {
        switch (currentLocation) {
            case LocationType::Branch1:
                branch1();
                break;

            case LocationType::FirstForest:
                firstForest();
                break;

            case LocationType::Booth:
                booth();
                break;

            case LocationType::GhostForest:
                ghostForest();
                break;

            case LocationType::House:
                house();
                break;

            case LocationType::Endings:
                endingBranch();
                break;
        }
    }
}
