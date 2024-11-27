#include "Place.h"

// Constructor
Place::Place(const std::string &n, double initTemp, double aar)
    : name(n), currentRoomTemp(initTemp),
      ambientRoomRate(aar),
      comfortTempSetpoint(22.0),
      lowerComfortLimit(20.0),
      upperComfortLimit(24.0) {}

// Add a FanCoil to the place
void Place::addFanCoil(FanCoil *fanCoil) {
    fanCoils.push_back(fanCoil);
}

// Set the occupancy schedule
void Place::setOccupancySchedule(const std::vector<int> &schedule) {
    occupancySchedule = schedule;
}

// Update the room temperature based on various parameters
void Place::updateTemperature(double ambientTemp, double chilledWaterTemp, int hour) {
    double deltaT = ambientTemp - currentRoomTemp;
    double RToff = currentRoomTemp + ambientRoomRate * deltaT;

    if (occupancySchedule[hour] == 1) {
        // Occupied
        if (currentRoomTemp > comfortTempSetpoint + 0.5) {
            // Need cooling
            for (auto fanCoil : fanCoils) {
                fanCoil->turnOn();
                double deltaT_fc = RToff - chilledWaterTemp;
                currentRoomTemp = RToff - fanCoil->getTTC() * deltaT_fc;
                // Prevent overcooling
                if (currentRoomTemp < comfortTempSetpoint) {
                    currentRoomTemp = comfortTempSetpoint;
                }
            }
        } else if (currentRoomTemp < comfortTempSetpoint - 0.5) {
            // Too cold, fan coils should be OFF
            for (auto fanCoil : fanCoils) {
                fanCoil->turnOff();
            }
            currentRoomTemp = RToff;
            // Prevent temperature from dropping below lower comfort limit
            if (currentRoomTemp < lowerComfortLimit) {
                currentRoomTemp = lowerComfortLimit;
            }
        } else {
            // Within comfort range, fan coils OFF
            for (auto fanCoil : fanCoils) {
                fanCoil->turnOff();
            }
            currentRoomTemp = RToff;
        }
    } else {
        // Unoccupied, fan coils OFF
        for (auto fanCoil : fanCoils) {
            fanCoil->turnOff();
        }
        currentRoomTemp = RToff;
    }
}

// Getter for the current temperature
double Place::getTemperature() const {
    return currentRoomTemp;
}

// Getter for the name of the place
const std::string &Place::getName() const {
    return name;
}

// Getter for the list of FanCoils
const std::vector<FanCoil *> &Place::getFanCoils() const {
    return fanCoils;
}
