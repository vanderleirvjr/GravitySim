#pragma once 

#include "Force.h"

struct Velocity {
    double x;
    double y;
    double z;

    bool operator==(const Velocity& other) const {
        return x == other.x &&
               y == other.y &&
               z == other.z;
    }

    Velocity operator+(const Force& force) const {
        Velocity result;
        result.x = x + force.x;
        result.y = y + force.y;
        result.z = z + force.z;
        return result;
    }


    Velocity operator*(double scalar) const {
        Velocity result;
        result.x = x * scalar;
        result.y = y * scalar;
        result.z = z * scalar;
        return result;
    }

};
