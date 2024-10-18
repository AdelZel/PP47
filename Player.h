#ifndef PLAYER_H
#define PLAYER_H

#include <ctime>
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window.hpp>
#include <vector>

#include <iostream>
#include <string>
using namespace std;
using namespace sf;

#include "Spaceship.h"

class Player: public Spaceship {
private:
Vector2f location; // location of the player's spaceship - top left corner 
Vector2f size; // size. based on the size of the sprite
Sprite* sprite; // player's sprite
float speed; // speed - aka multiplier of the number of pixels that a player passes in one delta time

public:
    Player(Vector2f location, Vector2f size, Sprite*sprite, float speed); // default constructor
    void shoot(); // creates a laser owned by the player
};

#endif