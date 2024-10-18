
#include "Button.h"

#include <ctime>
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window.hpp>
#include <vector>

#include <iostream>
#include <string>

Button::Button(sf::Vector2i location, sf::Vector2i size) {
    this->location = location;
    this->size = size;
}

bool Button::checkClick(sf::Vector2i mousePos) {
    if ((mousePos.x > this->location.x) && (mousePos.x < (this->location.x + this->size.x)))
    {
        if ((mousePos.y > this->location.y) && (mousePos.y < (this->location.y + this->size.y)))
        {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}