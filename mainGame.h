
#ifndef MAINGAME_H
#define MAINGAME_H

#include "Player.h"
#include "Ending.h"
#include "Location.h"

class MainGame {
private:
    enum class LocationType {
        Branch1,
        FirstForest,
        Booth,
        GhostForest,
        House,
        Endings
    };

    Player player;
    Ending ending;

    bool running = true;
    bool forestAvailable = true;
    int forestStage = 0;

    LocationType currentLocation = LocationType::Branch1;
    Forest forest;
    Booth boothLocation;

    Location* activeLocation = nullptr;

    int getChoice();

    void showLocationInfo() const;
    void showTitle() const;

    void branch1();
    void firstForest();
    void booth();
    void ghostForest();
    void house();

    void endingBranch();

public:
    void start();
};

#endif
