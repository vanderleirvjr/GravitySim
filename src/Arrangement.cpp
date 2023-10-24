#include <cstdlib>  // for std::rand()
#include <ctime>  // for std::time()
#include <cmath>

#include "Arrangement.h"
#include "Particle.h"
#include "Constants.h"


ObjectManager SolarSystem(ObjectManager& manager) {

    Particle sun;
    sun.setComponents("Sun",0,0,0,0,0,0,6.96e8 / 10,1.989e30);
    Object sunObj(sun);
    manager.addObject(sunObj);

    // Create Mercury
    Particle mercury;
    mercury.setComponents("Mercury", 5.79e10, 0, 0, 0, 4.74e4, 0, 2.439e6, 3.3011e23);
    Object mercuryObj(mercury);
    manager.addObject(mercuryObj);

    // Create Venus
    Particle venus;
    venus.setComponents("Venus", 1.082e11, 0, 0, 0, 3.5e4, 0, 6.051e6, 4.867e24);
    Object venusObj(venus);
    manager.addObject(venusObj);

    // Create Earth
    Particle earth;
    earth.setComponents("Earth", 1.496e11, 0, 0, 0, 2.98e4, 0, 6.371e6, 5.972e24);
    Object earthObj(earth);
    manager.addObject(earthObj);

    // Create Mars
    Particle mars;
    mars.setComponents("Mars", 2.279e11, 0, 0, 0, 2.41e4, 0, 3.3895e6, 6.4171e23);
    Object marsObj(mars);
    manager.addObject(marsObj);

    // Create Jupiter
    Particle jupiter;
    jupiter.setComponents("Jupiter", 7.785e11, 0, 0, 0, 1.31e4, 0, 6.9911e7, 1.898e27);
    Object jupiterObj(jupiter);
    manager.addObject(jupiterObj);

    // Create Saturn
    Particle saturn;
    saturn.setComponents("Saturn", 1.429e12, 0, 0, 0, 9.68e3, 0, 5.8232e7, 5.683e26);
    Object saturnObj(saturn);
    manager.addObject(saturnObj);

    // Create Uranus
    Particle uranus;
    uranus.setComponents("Uranus", 2.871e12, 0, 0, 0, 6.8e3, 0, 2.5362e7, 8.681e25);
    Object uranusObj(uranus);
    manager.addObject(uranusObj);

    // Create Neptune
    Particle neptune;
    neptune.setComponents("Neptune", 4.5e12, 0, 0, 0, 5.43e3, 0, 2.4622e7, 1.024e26);
    Object neptuneObj(neptune);
    manager.addObject(neptuneObj);

    return manager;

}

ObjectManager AddKuiperAsteroids(ObjectManager& manager, int numAsteroids) {
    std::srand(std::time(nullptr));  // Initialize random seed

    for (int i = 0; i < numAsteroids; ++i) {
        double distance = 4e+11 + static_cast<double>(std::rand()) / (static_cast<double>(RAND_MAX / (2e+11)));  // 30 to 55 AU in meters
        double angle = static_cast<double>(std::rand()) / RAND_MAX * 2 * 3.14159;  // 0 to 2*pi radians
        
        // Calculate the radial velocity
        double radial_velocity = std::sqrt(G * sunMass / distance);

        // Calculate the velocity components
        double vx = -radial_velocity * std::sin(angle);
        double vy = radial_velocity * std::cos(angle);

        Particle asteroid;
        asteroid.setComponents(
            "KuiperAsteroid" + std::to_string(i),
            distance * std::cos(angle),  // x
            distance * std::sin(angle),  // y
            0,  // z
            vx,  // vx
            vy,  // vy
            0,  // vz
            2e6,  // radius
            1e18  // mass
        );

        Object asteroidObj(asteroid);
        manager.addObject(asteroidObj);
    }

    return manager;

}



ObjectManager Cube(ObjectManager& manager) {

    int cubeSide = 6;  // 10 particles along each side of the cube
    double spacing = 1e5;  // 1e7 units between each particle
    
    for (int x = 0; x < cubeSide; ++x) {
        for (int y = 0; y < cubeSide; ++y) {
            for (int z = 0; z < cubeSide; ++z) {
                Particle asteroid;
    
                asteroid.setComponents("", x * spacing, y * spacing, z * spacing, 0, 0, 0, 8e3, 1e22);
                Object obj(asteroid);
                manager.addObject(obj);
            }
        }

    }

    return manager;

}