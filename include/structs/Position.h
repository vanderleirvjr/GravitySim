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

    Position operator+(const Position& pos) const {
        Position result;
        result.x = x + pos.x;
        result.y = y + pos.y;
        result.z = z + pos.z;
        return result;
    }


    Position operator*(const Position& other) const {
        Position result;
        result.x = x * other.x;
        result.y = y * other.y;
        result.z = z * other.z;
        return result;
    }

    Position operator/(double scalar) const {
        if(scalar == 0) {
            // Handle division by zero if needed
            // For example, throw an exception or return a default value
        }
        
        Position result;
        result.x = x / scalar;
        result.y = y / scalar;
        result.z = z / scalar;
        return result;
    }


    double sumComponents() const {
        return x + y + z;
    }

    void setComponents(double newX, double newY, double newZ) {
        x = newX;
        y = newY;
        z = newZ;
    }

};
