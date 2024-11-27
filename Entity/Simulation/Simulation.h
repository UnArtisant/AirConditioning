#ifndef SIMULATION_H
#define SIMULATION_H

#include <vector>
#include <iostream>
#include <iomanip>
#include <cmath>

#include "../FluidCircuit/FluidCircuit.h"
#include "../Place/Place.h"

class Simulation {
private:
    std::vector<Place *> places;
    FluidCircuit *chilledWaterCircuit;
    FluidCircuit *condensedWaterCircuit;
    Chiller *chiller;
    CoolingTower *coolingTower;
    double ambientTemperature;
    double totalEnergyConsumption;

public:
    explicit Simulation(double ambientTemp);

    ~Simulation();

    void addPlace(Place *place);

    void run();

    void report();
};

#endif // SIMULATION_H
