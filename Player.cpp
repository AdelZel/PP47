
#include <ctime>
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include "Game.h"
#include <iostream>
#include <string>
using namespace std;
using namespace sf;

#include "Spaceship.h"
#include "Player.h"
#include "Laser.h"

Player::Player(Vector2f location, Vector2f size, Sprite*sprite, float speed): Spaceship(location, size, sprite, 0, speed)
{
    this->location = location;
}

void Player::shoot()
{
    // cout << "pew" << endl;
    // cout << get_location().x << " " << get_location().y << endl;
    Game::AddNewProjectile(new Laser(get_location(), 0));
    return ;
}