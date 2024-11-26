//
// Created by Raphael Barriet on 26/11/2024.
//

#ifndef PUMPMANAGER_H
#define PUMPMANAGER_H
#include <vector>

#include "../Entity/Pump/Pump.h"


class PumpManager : public Actuator {
protected:
    std::vector<Pump> pumps;

    explicit PumpManager(int actuatorSetting, int pumpSetting, int pumpCount)
        : Actuator(actuatorSetting) {
        pumps.reserve(pumpCount);
        for (int i = 0; i < pumpCount; ++i) {
            pumps.emplace_back(pumpSetting);
        }
    }

    int countActivatePump() {
        int active_pumps = 0;
        for (const auto &pump: pumps) {
            if (pump.isActive()) {
                active_pumps++;
            }
        }
        return active_pumps;
    }

    void activateFirstPump() {
        if (!pumps.empty() && !pumps.front().isActive()) {
            pumps.front().activate();
        }
    }

    void deactivateAllPumps() {
        for (Pump &pump: pumps) {
            pump.deactivate();
        }
    }
};


#endif //PUMPMANAGER_H
