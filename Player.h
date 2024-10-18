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
Vector2f location;
Vector2f size;
Sprite* sprite;
float speed;

public:
    Player(Vector2f location, Vector2f size, Sprite*sprite, float speed);
    void shoot();
};

#endif