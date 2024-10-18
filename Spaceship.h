#ifndef SPACESHIP_H
#define SPACESHIP_H

#include <ctime>
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window.hpp>
#include <vector>

#include <iostream>
#include <string>
using namespace std;
using namespace sf;

#include "Entity.h"

class Spaceship: public Entity {
private:
    int type;    // types: 0 - player, 1 - enemy
    float speed; // СПИД - плохо. multiplier of the distance that a spaceship passes in one second.
    int hp; // 1 if alive, 0 - death

public:
    int spot; // spot at which the spaceship is when destroyed
    // types: 0 - player, 1 - enemy
    Spaceship(); // zero constructor - placeholder for list creation.
    Spaceship(Vector2f location, Vector2f size, Sprite*sprite, int type, float speed); // default constructor
    // creates an instance of laser class and gives it speed and direction
    virtual void shoot();
    // returns the type of an instance (to check if laser hits a player or an enemy)
    int get_type();
    // get current speed of a ship
    float get_speed();
    // set current speed of a ship to a value
    void set_speed(float speed);
};


#endif
