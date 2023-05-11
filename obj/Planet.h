#ifndef PLANET_H
#define PLANET_H

#include "Object.h"

class Planet : public Object {
public:
    float size;

    float mass;

    Planet(float initx = 0.0, float inity = 0.0, float initz = 0.0, float size = 1.0, float mass = 1.0);

    void draw();

};

#endif // PLANET_H
