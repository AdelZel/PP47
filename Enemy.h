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
    bool choice; // random choice variable that determines if the bot goes right or left every time that action timer goes off 
    int reload; // reload timer that determines the number of shots that bot does per second
    float speed; // movement speed of the bot
    int hp; // hp of the bot: 1 - alive; 0 - dead 
    sf::Vector2f location; // location of the bot and its sprite
    sf::Vector2f size; // size of the bot - determines the size of the hitbox based on the size of the sprite passed
public:
    Enemy(); // placeholder constructor reuired for creation of lists
    Enemy(Vector2f location, Vector2f size, Sprite*sprite, float speed); // default constructor
    ~Enemy(); // destructor. mainly relies on the Entity class destructor 
    void shoot(); // creates new laser objects that are assigned to enemy team (type = 1)
    void act(float dT, Window*window); // main acting simulation function that is being called every tick of the game - makes a bot move and shoot
    Sprite*get_enemySprite(); // returns the sprite that the bot uses
    int get_hp(); // returns the current number of hp that a bot has
    // health point of a ship
    void set_hp(int hp);
    // get current speed of a ship
    float get_speed();
    // set current speed of a ship to a value
    void set_speed(float speed);
};

#endif