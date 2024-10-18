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
    3 - record table           */
    int gameState;

    Clock sclock; // default ingame timer to base most of the time-based events (movement and shooting)
    float dT; // delta time variable that describes time between frames. (how much dpid the last tick in the game last)
    vector<int> size; // size of the game window

//textures and sprites for different backgrounds and entities 
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
    Texture tBackDeathScreen;
    Sprite sBackDeathScreen;
    // //

    inline static Projectile* projectiles[30]; // list of all projectiles
    inline static int sizeOfProj; // number of currently existing projectiles
    inline static Enemy* enemies[3]; // list of all enemies
    

public:
    inline static Sprite sLaser; // laser sprite - made public so it can be referenced by other classes
    inline static Texture tLaser; // laser texture - made public so it can be referenced by other classes
    Game(); // game process object constructor. takes no inputs but generates a lot of data and loads from the data-storing file

    float deltaTime(); // calculates delta time variable
    void run(); // main method of the class - makes game active as long as the game window exists

/*  gameState can be one of the following:
    0 - menu
    1 - gameplay
    2 - lost
    3 - record table           */
    int get_gameState();
    void set_gameState(int gs); // changes current gamestate to a passed type
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