#ifndef ENTITY_H
#define ENTITY_H

#include <ctime>
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window.hpp>
#include <vector>

#include <iostream>
#include <string>


class Meteor
{
private:
    sf::Sprite sprite;        // sprite of meteor
    sf::Texture texture;      // texture of meteor
    sf::Vector2f velocity;    // movement vector for direction and speed
    float speed;              // speed factor

    void initTexture();       // function to load texture
    void initSprite();        // function to set up sprite

public:
    Meteor(float posX, float posY);  // constructor with position

    void update(float deltaTime);    // update the meteor's position
    void render(sf::RenderTarget& target); // render the meteor

    sf::Vector2f get_position() const;    // get meteor position
    sf::FloatRect get_bounds() const;     // get bounds for collision detection
};

#endif // METEOR_H
