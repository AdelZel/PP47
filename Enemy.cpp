
#include <ctime>
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <random>
#include "Game.h"
#include "Laser.h"
#include <iostream>
#include <string>
using namespace std;
using namespace sf;

#include "Spaceship.h"
#include "Enemy.h"

Enemy::Enemy(){hp = -1; location.x = -50; location.y = -50;}

Enemy::Enemy(Vector2f location, Vector2f size, Sprite*sprite, float speed): Spaceship(location, size, sprite, 1, speed)
{
    this->actionTimer = 999.f;
    this->choice = rand()%2;
    reload = 0;
}

void Enemy::shoot()
{
    Game::AddNewProjectile(new Laser(Vector2f(this->get_location()+this->get_size()/2.f), 1));
    cout << "paw" << endl;
    return ;
}

Enemy::~Enemy(){}

void Enemy::act(float dT, Window*window)
{
    float path = this->get_speed()*dT*100;
    
    if (actionTimer < 0.2f) { actionTimer+=dT; } else
    {
        actionTimer = 0.f;
        this->choice = rand()%2;
        cout << "choice: '"<< choice << "' '" << path << endl;
        this->reload += 1;
        if (reload == 5) {
            this->shoot();
            reload = 0; }
    }

    if (choice)
    {
        
        this->move(this->get_location()+Vector2f((float)(((float)window->getSize().x)*this->get_speed()/1600.f), 0.f));
        cout << "moving right for: " << path << endl;
    }
    else
    {
        this->move(this->get_location()-Vector2f((float)(((float)window->getSize().x)*this->get_speed()/1600.f), 0.f));
        cout << "moving left for: " << path << endl;
    }

    // enemy boundaries set
    if (this->get_location().x < 0)
    {
       this->move(Vector2f(0, this->get_location().y));
    }
    else if (((this->get_location().x + this->get_size().x) > window->getSize().x))
    {
        this->move(Vector2f(window->getSize().x-this->get_size().x, this->get_location().y));
    }
    // //

    return ;
}

Sprite* Enemy::get_enemySprite()
{
    return this->get_sprite();
}

int Enemy::get_hp()
{
    return this->hp;
}

void Enemy::set_hp(int newhp)
{
    this->hp = newhp;
    return ;
}

float Enemy::get_speed()
{
    return this->speed;
}
    
void Enemy::set_speed(float speed)
{
    this->speed = speed;
}