#include <iostream>
#include <chrono>
#include <cstdlib>  // For random numbers
#include <ctime>    // To seed random numbers

#include "ObjectManager.h"
#include "NetCDFWriter.h"
#include "Physics.h"
#include "Position.h"

int main() {

    ObjectManager manager;
    NetCDFWriter writer("particles.nc"); // Create a NetCDFWriter instance and specify the file name
    std::srand(std::time(nullptr)); // seed random number generator

    // for (int i = 0; i < 10; ++i) {
    //     Particle asteroid;
        
    //     // Randomize initial position within a certain range
    //     asteroid.position.x = std::rand() % 10000 - 5000; // Between -5000 and 5000
    //     asteroid.position.y = std::rand() % 10000 - 5000; // Between -5000 and 5000
    //     asteroid.position.z = std::rand() % 10000 - 5000; // Between -5000 and 5000

    //     // Randomize initial velocity within a certain range
    //     asteroid.velocity.x = (std::rand() % 100 - 50) / 10.0; // Between -5 and 5
    //     asteroid.velocity.y = (std::rand() % 100 - 50) / 10.0; // Between -5 and 5
    //     asteroid.velocity.z = (std::rand() % 100 - 50) / 10.0; // Between -5 and 5

    //     // Randomize mass and radius within a certain range
    //     asteroid.mass = std::rand() % 1000000000 + 1e9;  // Between 1e9 and 2e9
    //     asteroid.radius = std::rand() % 100 + 50;        // Between 50 and 150

    //     // Create an Object using the Particle and add it to the manager
    //     Object obj(asteroid);
    //     manager.addObject(obj);
    // }

    // Initialize a Particle struct
    Particle sun;
    sun.name = "Sun";
    sun.position.x = 0;
    sun.position.y = 0;
    sun.position.z = 0;
    sun.velocity.x = 0;
    sun.velocity.y = 0;
    sun.velocity.z = 0;
    sun.radius = 1e8;
    sun.mass = 1.9891e30;
    Object obj_sun(sun);
    
    // Initialize Mercury
    Particle mercury;
    mercury.name = "Mercury";
    mercury.position.x = 5.79e10;
    mercury.position.y = 0;
    mercury.position.z = 0;
    mercury.velocity.x = 0;
    mercury.velocity.y = 4.74e4;
    mercury.velocity.z = 0;
    mercury.radius = 2.4397e6;
    mercury.mass = 3.3011e23;
    Object obj_mercury(mercury);
    
    // Initialize Venus
    Particle venus;
    venus.name = "Venus";
    venus.position.x = 1.082e11;
    venus.position.y = 0;
    venus.position.z = 0;
    venus.velocity.x = 0;
    venus.velocity.y = 3.5e4;
    venus.velocity.z = 0;
    venus.radius = 6.0518e6;
    venus.mass = 4.8675e24;
    Object obj_venus(venus);
    
    // Initialize Earth (already provided)
    Particle earth;
    earth.name = "Earth";
    earth.position.x = 1.49597e11;
    earth.position.y = 0;
    earth.position.z = 0;
    earth.velocity.x = 0;
    earth.velocity.y = 3e4;
    earth.velocity.z = 0;
    earth.radius = 6.371e6;
    earth.mass = 5.9722e24;
    Object obj_earth(earth);
    
    // Initialize Mars
    Particle mars;
    mars.name = "Mars";
    mars.position.x = 2.279e11;
    mars.position.y = 0;
    mars.position.z = 0;
    mars.velocity.x = 0;
    mars.velocity.y = 2.41e4;
    mars.velocity.z = 0;
    mars.radius = 3.3895e6;
    mars.mass = 6.4171e23;
    Object obj_mars(mars);
    
    // Initialize Jupiter
    Particle jupiter;
    jupiter.name = "Jupiter";
    jupiter.position.x = 7.786e11;
    jupiter.position.y = 0;
    jupiter.position.z = 0;
    jupiter.velocity.x = 0;
    jupiter.velocity.y = 1.31e4;
    jupiter.velocity.z = 0;
    jupiter.radius = 6.9911e7;
    jupiter.mass = 1.8982e27;
    Object obj_jupiter(jupiter);
    
    // Initialize Saturn
    Particle saturn;
    saturn.name = "Saturn";
    saturn.position.x = 1.433e12;
    saturn.position.y = 0;
    saturn.position.z = 0;
    saturn.velocity.x = 0;
    saturn.velocity.y = 9.68e3;
    saturn.velocity.z = 0;
    saturn.radius = 5.8232e7;
    saturn.mass = 5.6834e26;
    Object obj_saturn(saturn);
    
    // Initialize Uranus
    Particle uranus;
    uranus.name = "Uranus";
    uranus.position.x = 2.877e12;
    uranus.position.y = 0;
    uranus.position.z = 0;
    uranus.velocity.x = 0;
    uranus.velocity.y = 6.8e3;
    uranus.velocity.z = 0;
    uranus.radius = 2.5362e7;
    uranus.mass = 8.6810e25;
    Object obj_uranus(uranus);
    
    // Initialize Neptune
    Particle neptune;
    neptune.name = "Neptune";
    neptune.position.x = 4.504e12;
    neptune.position.y = 0;
    neptune.position.z = 0;
    neptune.velocity.x = 0;
    neptune.velocity.y = 5.43e3;
    neptune.velocity.z = 0;
    neptune.radius = 2.4622e7;
    neptune.mass = 1.02413e26;
    Object obj_neptune(neptune);

    // Io
    Particle io;
    io.position.x = 4.22e8;  // Example position in meters from Jupiter
    io.position.y = 0;
    io.position.z = 0;
    io.velocity.x = 0;
    io.velocity.y = 1.74e4;  // Example velocity in m/s
    io.velocity.z = 0;
    io.radius = 1.821e6;  // Radius in meters
    io.mass = 8.9e22;  // Mass in kg
    
    // Europa
    Particle europa;
    europa.position.x = 6.71e8;
    europa.position.y = 0;
    europa.position.z = 0;
    europa.velocity.x = 0;
    europa.velocity.y = 1.38e4;
    europa.velocity.z = 0;
    europa.radius = 1.5608e6;
    europa.mass = 4.8e22;
    
    // Ganymede
    Particle ganymede;
    ganymede.position.x = 1.07e9;
    ganymede.position.y = 0;
    ganymede.position.z = 0;
    ganymede.velocity.x = 0;
    ganymede.velocity.y = 1.09e4;
    ganymede.velocity.z = 0;
    ganymede.radius = 2.6341e6;
    ganymede.mass = 1.48e23;
    
    // Callisto
    Particle callisto;
    callisto.position.x = 1.88e9;
    callisto.position.y = 0;
    callisto.position.z = 0;
    callisto.velocity.x = 0;
    callisto.velocity.y = 8.2e3;
    callisto.velocity.z = 0;
    callisto.radius = 2.4106e6;
    callisto.mass = 1.08e23;

    Object io_obj(io);
    Object europa_obj(europa);
    Object ganymede_obj(ganymede);
    Object callisto_obj(callisto);
    
    manager.addObject(io_obj);
    manager.addObject(europa_obj);
    manager.addObject(ganymede_obj);
    manager.addObject(callisto_obj);


    
    // Add these objects to your ObjectManager
    manager.addObject(obj_sun);
    manager.addObject(obj_mercury);
    manager.addObject(obj_venus);
    manager.addObject(obj_earth);
    manager.addObject(obj_mars);
    manager.addObject(obj_jupiter);
    manager.addObject(obj_saturn);
    manager.addObject(obj_uranus);
    manager.addObject(obj_neptune);

    Physics phys = Physics(manager);

    int output_interval = 240;  // Write output every 10 time steps

    auto last_time = std::chrono::high_resolution_clock::now();  // Start timer


    int time = 0;
    for (int i = 0; i < 86700; ++i) {
        // Check if it's time to write output
        if (i % output_interval == 0) {
            writer.writeParticles(manager, time); // Assuming 0 is the time step

            // Measure and output time elapsed since last output
            auto current_time = std::chrono::high_resolution_clock::now();
            auto time_elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(current_time - last_time);
            std::cout << "Time elapsed since last output: " << time_elapsed.count() << " ms" << std::endl;

            last_time = current_time;  // Reset timer
            time += 1;
        }


        manager = phys.applyForces();  // Update physics
    }

    return 0;
}
