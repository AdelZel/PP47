#ifndef GAME_H
#define GAME_H

#include <ctime>
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include "Entity.h"
#include "Projectile.h"
#include "Spaceship.h"
#include "Laser.h"

#include <iostream>
#include <string>

#include "Button.h"
#include "Score.h"
#include "Entity.h"
#include "Spaceship.h"
#include "Player.h"
#include "Projectile.h"
#include "Enemy.h"

using namespace std;
using namespace sf;

class Game
{
private:

    bool hasSavedScore = false;

    Score score;

/*  gameState can be one of the following:
    0 - menu
    1 - gameplay
    2 - lost
    3 - record table
    4 - closing                        */
    int gameState;

    Clock sclock;
    float dT;
    vector<int> size;

    Texture tBackMenuButtons; 
    Sprite sBackMenuButtons;
    Texture tBackRecords;
    Sprite sBackRecords;
    Texture tBackGameplay;
    Sprite sBackGameplay;
    Texture tBackGameplayD;
    Sprite sBackGameplayD;
    Texture tPlayer;
    Sprite sPlayer;
    Texture tEnemy;
    Sprite sEnemy;
    inline static Projectile* projectiles[30];
    inline static int sizeOfProj;
    inline static Enemy* enemies[3];
    
    Texture tBackDeathScreen;
    Sprite sBackDeathScreen;

public:
    inline static Sprite sLaser;
    inline static Texture tLaser;
    Game();

    float deltaTime();
    void run();

    int get_gameState();
    void set_gameState(int gs);
    //adds the projectile passed to the function to the vector projectiles which keeps track of all projectiles currently instantiated, called when a projectile is constructed
    static void AddNewProjectile(Projectile*);
    //removes the projectile passed to the function to the vector projectiles which keeps track of all projectiles currently instantiated, called when a projectile is destroyed
    void DeleteProjectile(int, Projectile*);

    //adds the projectile passed to the function to the vector projectiles which keeps track of all projectiles currently instantiated, called when a projectile is constructed
    void AddNewEnemy(Enemy);
    //removes the projectile passed to the function to the vector projectiles which keeps track of all projectiles currently instantiated, called when a projectile is destroyed
    void DeleteEnemy(int, Enemy*);
};

#endif