
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
#include "Entity.h"

Spaceship::Spaceship(){}

Spaceship::Spaceship(Vector2f location, Vector2f size, Sprite*sprite, int type, float speed): Entity(location, size, sprite)
{
    this->type = type;
    this->speed = speed;
    this->hp = 1;
}

void Spaceship::shoot()
{
    cout << "piw" << endl;
    return ;
}

int Spaceship::get_type()
{
    return this->type;
}

float Spaceship::get_speed()
{
    return this->speed;
}
    
void Spaceship::set_speed(float speed)
{
    this->speed = speed;
}
