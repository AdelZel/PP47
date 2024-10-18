#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "Entity.h"
#include "Enemy.h"
#include "Player.h"
#include "vector"

class Projectile: public Entity{
    private:
        sf::Vector2f location;
        sf::Vector2f size;
        sf::Sprite* sprite;
        int ownerType;
        int speed;
        
    public:
        //constructor for Projectile class, it takes a location, a size, a sprite, an ownerType, and speed, 
        //then sets the instance's relevant members to the passed values and also adds the new object to the projectiles vector via calling the AddNewProjectile() function
        Projectile(sf::Vector2f location, sf::Vector2f size, sf::Sprite* sprite, int ownerType, int speed);
        Projectile();
        //calls the DeleteProjectile() function before destroying the instance;
        ~Projectile();
        // //checks if the projectile is colliding with a given entity passed to the function and returns true if it is and false if not, inherited from Entity
        // bool checkCollision(Entity*Collider);
        bool checkCollision(Entity Collider);
        // //checks if the entity is colliding with any entity within the vector passed to the function and if it is, adds it to an output vector
        // //after a collision check is made for each entity in the passed vector the output vector is returned
        // std::vector<Entity*> checkCollision(std::vector<Entity*> Colliders);
        //moves the projectile to the new location passed to the function and returns nothing, inherited from Entity
        void move(sf::Vector2i newLocation);
        //returns the location of the projectile, inherited from Entity
        sf::Vector2f get_location();
        //returns the size of the projectile, inherited from Entity
        sf::Vector2f get_size();
        //returns a pointer to the sprite used for the projectile, used to draw entities to screen within Game::run(), inherited from Entity
        sf::Sprite* get_sprite();
        // 0 - player; 1 - enemy
        int get_ownerType();
        //moves the projectile a set distance according to its speed, returns nothing, is called each frame in Game::run()
        void Fire(Player*player);
};

#endif
