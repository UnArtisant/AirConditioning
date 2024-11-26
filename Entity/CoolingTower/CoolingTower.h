//
// Created by Raphael Barriet on 25/11/2024.
//

#ifndef COOLINGTOWER_H
#define COOLINGTOWER_H

#include "../../Helper/PumpManager.h"

class CoolingTower : public PumpManager {
public:
    explicit CoolingTower(int pumpSetting = 14, int pumpCount = 2) : PumpManager(
        40, pumpSetting, pumpCount) {
    }
};


#endif //COOLINGTOWER_H
