#include "Object.h"

Object::Object(Particle newParticle): particle(newParticle) {
    // constructor body, if needed
}

Object::~Object() {
    // destructor body, if needed
}

void Object::setParticle(const Particle& newParticle) {
    particle = newParticle;
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

bool Object::operator==(const Object& other) const {
    // Implement your comparison logic here.
    // For example, if you want to compare based on position:
    return this->getPosition().x == other.getPosition().x &&
           this->getPosition().y == other.getPosition().y;
}
