#include "Fcu.h"

FCU::FCU(int pumpCount, int pumpSetting)
    : PumpManager(6, pumpSetting, pumpCount) {
}

void FCU::activate() {
    is_active = true;
    if (countActivatePump() == 0) {
        // Ensure at least one pump is active
        activateFirstPump();
    }
}

void FCU::deactivate() {
    is_active = false;
    deactivateAllPumps();
}

double FCU::getCoolingCapacity(double RToff, double Tch) {
    int active_pumps = countActivatePump();
    double TTCf = calculateTTCf(active_pumps);
    return (RToff - Tch) * TTCf;
}

// Calculate total power consumption of FCU
double FCU::getConsumption() {
    if (!is_active) {
        return 0.0; // If the FCU is OFF, power consumption is 0
    }

    // FCU power consumption (6 kW) + sum of active pump consumptions
    double totalConsumption = power_consumption; // Base FCU consumption
    for (const auto &pump: pumps) {
        if (pump.isActive()) {
            totalConsumption += pump.getConsumption(); // Dynamically retrieve pump consumption
        }
    }
    return totalConsumption;
}

// AulasTwoFCU Implementation
AulasTwoFCU::AulasTwoFCU() : FCU(2) {
}

double AulasTwoFCU::calculateTTCf(int active_pumps) {
    switch (active_pumps) {
        case 1: return 0.25;
        case 2: return 0.40;
        default: return 0.0;
    }
}

// AulasOneFCU Implementation
AulasOneFCU::AulasOneFCU() : FCU(2) {
}

double AulasOneFCU::calculateTTCf(int active_pumps) {
    switch (active_pumps) {
        case 1: return 0.30;
        case 2: return 0.40;
        default: return 0.0;
    }
}

// BiblioTecFCU Implementation
BiblioTecFCU::BiblioTecFCU() : FCU(3) {
}

double BiblioTecFCU::calculateTTCf(int active_pumps) {
    switch (active_pumps) {
        case 1: return 0.20;
        case 2: return 0.30;
        case 3: return 0.40;
        default: return 0.0;
    }
}
