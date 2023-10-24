#pragma once 

#include "Particle.h"

class Object {

private:
    Particle particle;
    double energy;

public:

    Object(Particle newParticle);

    ~Object();

    void setParticle(const Particle& newParticle);

    Particle getParticle() const;

    void setName(const std::string& newName);

    std::string getName() const;

    void setPosition(const Position& newPosition);

    Position getPosition() const;

    void setVelocity(const Velocity& newVelocity);

    Velocity getVelocity() const;

    void setRadius(const double newRadius);

    double getRadius() const;

    void setMass(const double newMass);

    double getMass() const;

    void calculateEnergy();

    double getEnergy() const;

    bool operator==(const Object& other) const;

};
