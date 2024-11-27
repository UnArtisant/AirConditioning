#include "Actuator.h"

// Actuator class implementation
Actuator::Actuator(double power, double ttc)
    : state(false), powerConsumptionPerHour(power),
      operationalCycles(0), temperatureTransferCoefficient(ttc) {}

void Actuator::turnOn() {
    if (!state) {
        state = true;
        operationalCycles++;
    }
}

void Actuator::turnOff() {
    if (state) {
        state = false;
        operationalCycles++;
    }
}

bool Actuator::isOn() const {
    return state;
}

double Actuator::getPowerConsumption() const {
    return powerConsumptionPerHour;
}

int Actuator::getOperationalCycles() const {
    return operationalCycles;
}

double Actuator::getTTC() const {
    return temperatureTransferCoefficient;
}

// FanCoil class implementation
FanCoil::FanCoil(double power, double ttc) : Actuator(power, ttc) {}

// Chiller class implementation
Chiller::Chiller(double power, double ttc) : Actuator(power, ttc) {}

// CoolingTower class implementation
CoolingTower::CoolingTower(double power, double ttc) : Actuator(power, ttc) {}

