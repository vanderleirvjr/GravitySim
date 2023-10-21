#pragma once 

struct Force {
    double x;
    double y;
    double z;

    Force() : x(0), y(0), z(0) {}
    Force(int val) : x(val), y(val), z(val) {}

    Force& operator+=(const Force& other) {
        x += other.x;
        y += other.y;
        z += other.z;
        return *this;
    }

    Force operator*(double scalar) const {
        Force result;
        result.x = x * scalar;
        result.y = y * scalar;
        result.z = z * scalar;
        return result;
    }

    Force operator/(double scalar) const {
        Force result;
        if (scalar != 0.0) {
            result.x = x / scalar;
            result.y = y / scalar;
            result.z = z / scalar;
        }
        return result;
    }

};