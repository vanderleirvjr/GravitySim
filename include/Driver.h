#pragma once

#include "ObjectManager.h"

class Driver {
public:
    Driver();
    ~Driver();
    
    void initializeObjects();
    void runSimulation();

private:
    ObjectManager manager = ObjectManager();
};
