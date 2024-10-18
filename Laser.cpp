#include "Laser.h"
#include "Game.h"

Laser::Laser(sf::Vector2f location, int startingOwnerType) : Projectile(location, size, new Sprite(Game::tLaser), startingOwnerType, 1) {
    this->location = location;
    ownerType = startingOwnerType;
}

Laser::~Laser(){}