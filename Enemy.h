#ifndef ENEMY_H
#define ENEMY_H

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

class Enemy: public Spaceship {
private:
    float actionTimer; // determines how often will a bot act.
    bool choice;
    int reload;
    float speed;
    int hp;
    sf::Vector2f location;
    sf::Vector2f size;
public:
    Enemy();
    Enemy(Vector2f location, Vector2f size, Sprite*sprite, float speed);
    ~Enemy();
    void shoot();
    void act(float dT, Window*window);
    Sprite*get_enemySprite();
    int get_hp();
    // health point of a ship
    void set_hp(int hp);
    // get current speed of a ship
    float get_speed();
    // set current speed of a ship to a value
    void set_speed(float speed);
};

#endif