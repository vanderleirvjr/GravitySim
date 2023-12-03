#pragma once

#include "ObjectManager.h"

ObjectManager SolarSystem(ObjectManager& manager);

ObjectManager SaturnRings(ObjectManager& manager);

ObjectManager AddKuiperAsteroids(ObjectManager& manager, int numAsteroids = 500);

ObjectManager Cube(ObjectManager& manager, int cubeSide = 6, double spacing = 1e5);

