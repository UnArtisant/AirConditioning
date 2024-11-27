#include "FluidCircuit.h"

// Constructor
FluidCircuit::FluidCircuit(double initialTemp, double setpointTemp, double ambientInfluence, double ttc, Actuator *act)
    : currentTemperature(initialTemp), setpointTemperature(setpointTemp),
      ambientTemperatureInfluence(ambientInfluence), transferCoefficient(ttc), actuator(act) {
}

// Update the temperature based on the current state of the actuator
void FluidCircuit::updateTemperature(double ambientTemp) {
    if (actuator->isOn()) {
        double deltaT = currentTemperature - setpointTemperature;
        currentTemperature -= transferCoefficient * deltaT;

        // Ensure temperature does not go below setpoint
        if (currentTemperature < setpointTemperature) {
            currentTemperature = setpointTemperature;
        }
    } else {
        // Adjust towards ambient temperature
        double deltaT = ambientTemp - currentTemperature;
        currentTemperature += ambientTemperatureInfluence * deltaT;
    }
}

// Getter for the current temperature
double FluidCircuit::getTemperature() const {
    return currentTemperature;
}
