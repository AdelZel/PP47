
#ifndef BUTTON_H
#define BUTTON_H

#include <ctime>
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window.hpp>
#include <vector>

#include <iostream>
#include <string>

class Button {
public:
    // default constructor of a button.
    // takes in location which is the position of the upper left corner of a rectangular button region
    // takes in size which is the position of the right down corner relative to the left upper one
    Button (sf::Vector2i location, sf::Vector2i size); 
    
    // method that checks where a mouse button has been clicked and returns true if it was clicked inside the button region
    // returns false if it was clicked outside of the button region.
    // takes in 
    bool checkClick (sf::Vector2i);


private:
    sf::Vector2i location;
    sf::Vector2i size;
};

#endif