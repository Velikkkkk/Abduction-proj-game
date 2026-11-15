## HappiestDay
## Project Description

"Happiest Day" is a text-based adventure game developed in C++.
Players progress through a narrative by collecting items and making choices.
The primary goal of the project is to create an interactive
story where the player's decisions influence the course of the game.

## Current Features

The project currently includes:

- A main menu to start or exit the game.
- A "Player" class with a health system.
- An inventory system based on the `std::vector` container.
- Functionality to add, remove, and check for the presence of items.
- Multiple locations interconnected by player choices.
- A system for tracking the player's current location.
- A "Forest" game stage featuring interactive decision-making.
- An access control system for specific locations.
- Two possible endings.

## Program Structure

The project consists of several classes:

### MainGame
Manages the core game loop, player choices,
and transitions between locations.

### Player
Stores data regarding the player's health and inventory.

### Item
Represents an item, defined by its name.

### Location
Stores information about a location,
including its name and description.

### Ending
Contains the various ways the game can conclude.

## Abstract Data Types

The `std::vector` container is used to manage the player's inventory.
`std::vector` was chosen because it allows for
easy addition, removal, and access to items.

## Current Development Stage

Work is currently underway on the narrative and the interactions between different regions.
Players can collect items and utilize them when making decisions. ## Development Plans

Future plans include the following:

- Complete the storyline for each location.
- Add more choices for the player.
- Implement a system where player decisions influence subsequent events.
- Fully flesh out both endings.
- Improve the interconnections between existing classes.
- Test the game and fix any potential bugs.

## Feedback Questions

1. In your opinion, is it possible to optimize the game even further?

2. Should anything be changed regarding the visual aspect of the selection menu?
