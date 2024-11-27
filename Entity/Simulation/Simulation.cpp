#include "Simulation.h"

// Constructor
Simulation::Simulation(double ambientTemp)
    : ambientTemperature(ambientTemp), totalEnergyConsumption(0) {
    // Initialize chiller and cooling tower
    chiller = new Chiller(60.0, 0.5); // Power consumption and TTC
    coolingTower = new CoolingTower(40.0, 0.7);

    // Initialize circuits
    chilledWaterCircuit = new FluidCircuit(10.0, 8.0, 0.1, 0.5, chiller);
    condensedWaterCircuit = new FluidCircuit(25.0, 18.0, 0.1, 0.7, coolingTower);
}

// Destructor
Simulation::~Simulation() {
    delete chilledWaterCircuit;
    delete condensedWaterCircuit;
    delete chiller;
    delete coolingTower;
    for (auto place: places) {
        delete place;
    }
}

// Add a Place to the simulation
void Simulation::addPlace(Place *place) {
    places.push_back(place);
}

// Run the simulation for 24 hours
void Simulation::run() {
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Hourly Simulation Updates:\n";
    std::cout << "Hour\tAmbientTemp\t";
    for (auto place: places) {
        std::cout << place->getName() << "_Temp\t";
    }
    std::cout << "Chiller_ON\tCoolingTower_ON\tEnergyConsumption\n";

    for (int hour = 0; hour < 24; ++hour) {
        // Update ambient temperature (simulate summer conditions)
        ambientTemperature = 21.0 + 6.0 * std::sin((hour - 6) * 3.1416 / 12);

        // Update places
        bool anyFanCoilOn = false;
        for (auto place: places) {
            place->updateTemperature(ambientTemperature, chilledWaterCircuit->getTemperature(), hour);

            // Check if any fan coil is on
            for (auto fanCoil: place->getFanCoils()) {
                if (fanCoil->isOn()) {
                    anyFanCoilOn = true;
                    totalEnergyConsumption += fanCoil->getPowerConsumption();
                }
            }
        }

        // Control chiller and cooling tower based on fan coils
        if (anyFanCoilOn) {
            chiller->turnOn();
            coolingTower->turnOn();
        } else {
            chiller->turnOff();
            coolingTower->turnOff();
        }

        // Update fluid circuits
        chilledWaterCircuit->updateTemperature(ambientTemperature);
        condensedWaterCircuit->updateTemperature(ambientTemperature);

        // Update energy consumption
        if (chiller->isOn()) {
            totalEnergyConsumption += chiller->getPowerConsumption();
        }
        if (coolingTower->isOn()) {
            totalEnergyConsumption += coolingTower->getPowerConsumption();
        }

        // Output hourly update
        std::cout << hour << "\t" << ambientTemperature << "\t\t";
        for (auto place: places) {
            std::cout << place->getTemperature() << "\t\t";
        }
        std::cout << (chiller->isOn() ? "ON" : "OFF") << "\t\t";
        std::cout << (coolingTower->isOn() ? "ON" : "OFF") << "\t\t";
        std::cout << totalEnergyConsumption << "\n";
    }

    report();
}

// Generate a simulation report
void Simulation::report() {
    std::cout << "\nSimulation Report:\n";
    for (auto place: places) {
        std::cout << "Place: " << place->getName()
                << ", Final Temperature: " << place->getTemperature() << "°C\n";
    }
    std::cout << "Total Energy Consumption: " << totalEnergyConsumption << " kWh\n";
    std::cout << "Chiller Operational Cycles: " << chiller->getOperationalCycles() << "\n";
    std::cout << "Cooling Tower Operational Cycles: " << coolingTower->getOperationalCycles() << "\n";
}
