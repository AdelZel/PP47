#ifndef LASER_H 
#define LASER_H

#include "Projectile.h"
#include "vector"

class Laser: public Projectile{
private:
    sf::Vector2f location; // spawn location of the laser
    sf::Vector2f size; // size of the hitbox of the laser basesd on the size of the sprite
    sf::Sprite* sprite; // laser sprite
    int ownerType; // 0 - player; 1 - enemy
    int spot; // spot at which the laser is destructed
    int speed; // speed at which the laser moves

public:
    //constructor for Laser class, it takes a location,  an ownerType, 
    //then sets the instance's relevant members to the passed values and also adds the new object to the Projectile::projectiles vector via calling the Projectile::AddNewProjectile() function
    //unlike the Projectile constructor, the Laser constructor does not take a sprite, size, or speed as those are predetermined by the fact it is a laser projectile
    Laser(sf::Vector2f location, int ownerType);
    ~Laser();
    //checks if the projectile is colliding with a given entity passed to the function and returns true if it is and false if not, inherited from Projectile
    bool checkCollision(Entity*Collider);
    //moves the projectile to the new location passed to the function and returns nothing, inherited from Projectile
    void move(sf::Vector2i newLocation);
    //returns the location of the projectile, inherited from Projectile
    sf::Vector2i get_location();
    //returns the size of the projectile, inherited from Projectile
    sf::Vector2f get_size();
    //returns a pointer to the sprite used for the laser, used to draw entities to screen within Game::run(), inherited from Projectile
    sf::Sprite* get_sprite();
    //moves the projectile a set distance according to its speed, returns nothing, is called each frame in Game::run(), inherited from Projectile
    void Fire();

};

#endif