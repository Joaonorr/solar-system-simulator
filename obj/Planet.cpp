#include "Planet.h"
#include "gui.h"

Planet::Planet(float initx, float inity, float initz, float size, float mass)
    : Object{initx, inity, initz} {
    this->size = size;
    this->mass = mass;
}

void Planet::draw() {
    GUI::drawSphere(this->initx, this->inity, this->initz, this->size);
}
