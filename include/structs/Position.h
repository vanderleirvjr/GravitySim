#pragma once

#include "Velocity.h"

struct Position {
    double x;
    double y;
    double z;

    bool operator==(const Position& other) const {
        return x == other.x &&
               y == other.y &&
               z == other.z;
    }


    Position operator-(const Position& other) const {
        Position diff;
        diff.x = x - other.x;
        diff.y = y - other.y;
        diff.z = z - other.z;
        return diff;
    }


    Position operator+(const Velocity& vel) const {
        Position result;
        result.x = x + vel.x;
        result.y = y + vel.y;
        result.z = z + vel.z;
        return result;
    }

};
