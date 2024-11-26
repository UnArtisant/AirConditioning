#include "Place.h"
#include <algorithm>

Place::Place(std::string placeName, const std::vector<std::pair<double, double>>& busyHours, double rti, double aar)
    : name(std::move(placeName)), busyHours(busyHours), rti(rti), aar(aar), currentTemperature(rti) {
}

bool Place::isBusy(double time) const {
    return std::any_of(busyHours.begin(), busyHours.end(), [time](const auto& range) {
        return time >= range.first && time <= range.second;
    });
}

double Place::getConsumption() {
    double totalConsumption = 0;

    for (const auto& fcu : fcus) {
        totalConsumption += fcu->getConsumption();
    }

    return totalConsumption;
}

void Place::addFCU(std::unique_ptr<FCU> fcu) {
    fcus.push_back(std::move(fcu));
}

void Place::updateRoomTemperature(double outdoorTemperature, double deltaTime) {
    double temperatureDelta = currentTemperature - outdoorTemperature;
    currentTemperature = rti + aar * temperatureDelta * deltaTime;
}

// AulasOne Implementation
AulasOne::AulasOne()
    : Place("Aulas One", {{10.00, 19.00}}, 16.00, 0.7) {
    addFCU(std::make_unique<AulasOneFCU>());
    addFCU(std::make_unique<AulasOneFCU>());
}

// AulasTwo Implementation
AulasTwo::AulasTwo()
    : Place("Aulas Two", {{7.00, 22.00}}, 16.00, 0.7) {
    addFCU(std::make_unique<AulasTwoFCU>());
}

// BiblioTec Implementation
BiblioTec::BiblioTec()
    : Place("Bibliotec", {{7.00, 13.00}, {15.00, 21.00}}, 16.00, 0.9) {
    addFCU(std::make_unique<BiblioTecFCU>());
}
