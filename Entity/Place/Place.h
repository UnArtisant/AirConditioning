#ifndef PLACE_H
#define PLACE_H

#include <vector>
#include <string>
#include <memory>
#include <cmath>
#include "../FCU/Fcu.h"

class Place : public ConsumptionManager {
protected:
    std::string name;
    std::vector<std::unique_ptr<FCU>> fcus;
    std::vector<std::pair<double, double>> busyHours;
    double rti;  // Initial room temperature
    double aar;  // Ambient-Room rate
    double currentTemperature;

public:
    Place(std::string placeName, const std::vector<std::pair<double, double>>& busyHours, double rti, double aar);

    ~Place() override = default;

    [[nodiscard]] bool isBusy(double time) const;

    void addFCU(std::unique_ptr<FCU> fcu);

    [[nodiscard]] const std::string& getName() const { return name; }
    [[nodiscard]] double getRTI() const { return rti; }
    [[nodiscard]] double getAAR() const { return aar; }

    [[nodiscard]] double getConsumption() override;

    // Update room temperature based on ambient conditions
    void updateRoomTemperature(double outdoorTemperature, double deltaTime);
};

class AulasOne : public Place {
public:
    AulasOne();
};

class AulasTwo : public Place {
public:
    AulasTwo();
};

class BiblioTec : public Place {
public:
    BiblioTec();
};

#endif // PLACE_H
