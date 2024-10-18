#include "Meteor.h"

#include <ctime>
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window.hpp>
#include <vector>

#include <iostream>
#include <string>




void Meteor::initTexture()
{
    if (!this->texture.loadFromFile("images/meteor.png"))
    {
        std::cerr << "ERROR::METEOR::Could not load texture file." << std::endl;
    }
}

// Initialize sprite and assign texture
void Meteor::initSprite()
{
    this->sprite.setTexture(this->texture);
    this->sprite.setScale(0.5f, 0.5f);  // adjust size
    this->sprite.setPosition(rand() % 640, rand() % 360);  // random start position
}

// constructor: sets initial position, direction, and speed
Meteor::Meteor(float posX, float posY)
{
    this->speed = static_cast<float>((rand() % 100) + 50) / 10.f;  // random speed between 5 and 15
    float dirX = static_cast<float>((rand() % 200) - 100) / 100.f;  // random direction X (-1.0 to 1.0)
    float dirY = static_cast<float>((rand() % 200) - 100) / 100.f;  // random direction Y (-1.0 to 1.0)
    
    this->velocity = sf::Vector2f(dirX, dirY);  // set direction
    this->initTexture();
    this->initSprite();
    this->sprite.setPosition(posX, posY);
}

// update the position based on velocity and speed
void Meteor::update(float deltaTime)
{
    this->sprite.move(this->velocity * this->speed * deltaTime);
}

// render the meteor to the window
void Meteor::render(sf::RenderTarget& target)
{
    target.draw(this->sprite);
}

// get meteor position for other logic
sf::Vector2f Meteor::get_position() const
{
    return this->sprite.getPosition();
}

// get bounds for collision detection or boundaries
sf::FloatRect Meteor::get_bounds() const
{
    return this->sprite.getGlobalBounds();
}
