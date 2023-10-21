#pragma once 

#include "Object.h"
#include "ObjectManager.h"
#include "Force.h"

class Physics {

private:
    ObjectManager manager;

public:

    Physics(ObjectManager& inputManager);
    ~Physics();

    Force gravityForce(Object& obj1);

    ObjectManager applyForces();

};