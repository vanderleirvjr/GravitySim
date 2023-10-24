#include <chrono>
#include <iostream>
#include <chrono>
#include <ctime> 

#include "Driver.h"
#include "Particle.h"
#include "Object.h"
#include "NetCDFWriter.h"
#include "Physics.h"
#include "CollisionHandler.h"
#include "Arrangement.h"


double randomDouble(double min, double max) {
    return min + static_cast<double>(rand()) / (static_cast<double>(RAND_MAX / (max - min)));
}

Driver::Driver() {}


Driver::~Driver() {}


void Driver::initializeObjects() {

    manager = SolarSystem(manager);
    
    manager = AddKuiperAsteroids(manager, 300);

}


void Driver::runSimulation() {
    
    //CollisionHandler collisionHandler = CollisionHandler();

    Physics phys = Physics(manager);

    NetCDFWriter writer("particles.nc"); // Create a NetCDFWriter instance and specify the file name

    auto last_time = std::chrono::high_resolution_clock::now();  // Start timer

    int time = 0;

    for (int i = 0; i < simulationSteps; ++i) {
        // Check if it's time to write output
        if (i % historyInterval == 0) {

            writer.writeParticles(manager, time); // Assuming 0 is the time step

            // Measure and output time elapsed since last output
            auto current_time = std::chrono::high_resolution_clock::now();
            auto time_elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(current_time - last_time);
            std::cout << "Time elapsed since last output: " << time_elapsed.count() << " ms" << std::endl;

            last_time = current_time;  // Reset timer
            time += 1;
        }


        manager = phys.applyForces();  // Update physics
        //manager = collisionHandler.processObjects(manager);

    }

}