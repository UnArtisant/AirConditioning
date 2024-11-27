#ifndef FLUIDCIRCUIT_H
#define FLUIDCIRCUIT_H
#include "../Actuator/Actuator.h"


class FluidCircuit {
protected:
    double currentTemperature;
    double ambientTemperatureInfluence;
    double setpointTemperature; // Desired temperature
    double transferCoefficient; // TTCch or TTCcd
    Actuator *actuator; // Chiller or Cooling Tower

public:
    FluidCircuit(double initialTemp, double setpointTemp, double ambientInfluence, double ttc, Actuator *act);

    ~FluidCircuit() = default; // Default destructor

    void updateTemperature(double ambientTemp);

    double getTemperature() const;
};

#endif // FLUIDCIRCUIT_H
