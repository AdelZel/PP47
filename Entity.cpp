#include "Entity.h"

#include <ctime>
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window.hpp>
#include <vector>

#include <iostream>
#include <string>

Entity::Entity(){}

Entity::Entity(sf::Vector2f location, sf::Vector2f size, sf::Sprite*sprite)
{
    this->location = location;
    this->size = size;
    this->sprite = sprite;
    this->sprite->setPosition(location.x, location.y);
}

bool Entity::checkCollision(Entity Collider)
{
    //our projectile entity
    sf::Vector2f p_tl = this->get_location(); // top left corner
    sf::Vector2f p_tr = this->get_location() + sf::Vector2f(this->get_size().x, 0); // top right
    sf::Vector2f p_bl = this->get_location() + sf::Vector2f(0, this->get_size().y); // bottom left
    sf::Vector2f p_br = this->get_location() + this->get_size(); // bottom right
    
    // potential collider entity
    sf::Vector2f c_tl = Collider.get_location(); // top left corner
    sf::Vector2f c_tr = Collider.get_location() + sf::Vector2f(Collider.get_size().x, 0); // top right
    sf::Vector2f c_bl = Collider.get_location() + sf::Vector2f(0, Collider.get_size().y); // bottom left
    sf::Vector2f c_br = Collider.get_location() + Collider.get_size(); // bottom right
    

    // checking top left corner
         if ( ( c_tl.x < p_tl.x && p_tl.x < c_tr.x) && (c_tl.y < p_tl.y && p_tl.y < c_bl.y) ) { return true; }
    
    // checking top right corner
    else if ( ( c_tl.x < p_tr.x && p_tr.x < c_tr.x) && (c_tl.y < p_tr.y && p_tr.y < c_bl.y) ) { return true; }

    // checking bot left corner
    else if ( ( c_tl.x < p_bl.x && p_bl.x < c_tr.x) && (c_tl.y < p_bl.y && p_bl.y < c_bl.y) ) { return true; }

    // checking bot right corner
    else if ( ( c_tl.x < p_br.x && p_br.x < c_tr.x) && (c_tl.y < p_br.y && p_br.y < c_bl.y) ) { return true; }
    
    else { return false; }
}

// std::vector<Entity*> Entity::checkCollision(std::vector<Entity*> Colliders)
// {
//     std::vector<Entity*> output;
//     for (size_t i = 0; i < Colliders.size(); i++)
//     {
//         if (checkCollision(Colliders.at(i)))
//         {
//             output.push_back(Colliders.at(i));
//         }
//     }
//     return output;
// }

void Entity::move(sf::Vector2f newLocation)
{
    this->location = newLocation;
    this->sprite->setPosition((float)location.x, (float)location.y);
}

sf::Vector2f Entity::get_location()
{
    return this->location;
}

sf::Vector2f Entity::get_size()
{
    return this->size;
}

sf::Sprite* Entity::get_sprite()
{
    return sprite;
}

Entity::~Entity()
{
    //delete sprite;
}
