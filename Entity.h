#ifndef ENTITY_H
#define ENTITY_H

#include <ctime>
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window.hpp>
#include <vector>

#include <iostream>
#include <string>


class Entity {
private:
    sf::Vector2f location;
    sf::Vector2f size;
    sf::Sprite* sprite;


public:
    Entity(sf::Vector2f location, sf::Vector2f size, sf::Sprite* sprite);
    Entity();
    ~Entity();
    //checks if the entity is colliding with a given entity passed to the function and returns true if it is and false if not
    bool checkCollision(Entity Collider);
    //checks if the entity is colliding with any entity within the vector passed to the function and if it is, adds it to an output vector
    //after a collision check is made for each entity in the passed vector the output vector is returned
    std::vector<Entity*> checkCollision(std::vector<Entity*> Colliders);
    //moves the entity to the new location passed to the function and returns nothing
    void move(sf::Vector2f newLocation);
    //returns the location of the entity
    sf::Vector2f get_location();
    //returns the size of the entity
    sf::Vector2f get_size();
    //returns a pointer to the sprite used for the entity, used to draw entities to screen within Game::run()
    sf::Sprite* get_sprite();
};


#endif