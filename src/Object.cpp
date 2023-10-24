#include "Object.h"

Object::Object(Particle newParticle): particle(newParticle) {
    // constructor body, if needed
}

Object::~Object() {
    // destructor body, if needed
}

void Object::setName(const std::string& newName) {
    particle.name = newName;
}

std::string Object::getName() const {
    return particle.name;
} 


void Object::setParticle(const Particle& newParticle) {
    particle = newParticle;
    calculateEnergy();
}

Particle Object::getParticle() const {
    return particle;
}

void Object::setVelocity(const Velocity& newVelocity) {
    particle.velocity = newVelocity;
    
}

Velocity Object::getVelocity() const {
    return particle.velocity;
}

void Object::setPosition(const Position& newPosition) {
    particle.position = newPosition;
    calculateEnergy();
}

Position Object::getPosition() const {
    return particle.position;
}

void Object::setRadius(const double newRadius) {
    particle.radius = newRadius;
}

double Object::getRadius() const {
    return particle.radius;
}

void Object::setMass(const double newMass) {
    particle.mass = newMass;
}

double Object::getMass() const {
    return particle.mass;
}

void Object::calculateEnergy() {
    energy = 0.5 * particle.mass * (particle.velocity.x * particle.velocity.x + 
                                    particle.velocity.y * particle.velocity.y + 
                                    particle.velocity.z * particle.velocity.z);
}

double Object::getEnergy() const {
    return energy;
}



bool Object::operator==(const Object& other) const {
    // Implement your comparison logic here.
    // For example, if you want to compare based on position:
    return this->getPosition().x == other.getPosition().x &&
           this->getPosition().y == other.getPosition().y;
}
