#ifndef PLACE_H
#define PLACE_H

#include <string>
#include <vector>
#include "../Actuator/Actuator.h"

class Place {
protected:
    std::string name;
    double currentRoomTemp;
    double ambientRoomRate; // AAR
    std::vector<FanCoil *> fanCoils;
    std::vector<int> occupancySchedule; // 24-hour schedule

    // Comfort temperature setpoints
    double comfortTempSetpoint;
    double lowerComfortLimit;
    double upperComfortLimit;

public:
    Place(const std::string &n, double initTemp, double aar);

    ~Place() = default;

    void addFanCoil(FanCoil *fanCoil);

    void setOccupancySchedule(const std::vector<int> &schedule);

    void updateTemperature(double ambientTemp, double chilledWaterTemp, int hour);

    double getTemperature() const;

    const std::string &getName() const;

    const std::vector<FanCoil *> &getFanCoils() const;
};

#endif // PLACE_H
