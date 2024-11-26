//
// Created by Raphael Barriet on 25/11/2024.
//

#ifndef CHILLER_H
#define CHILLER_H

#include "../../Helper/PumpManager.h"

class Chiller : public PumpManager {
public:
    Chiller(int pumpSetting = 15, int pumpCount = 2) : PumpManager(
        60, pumpSetting, pumpCount) {
    }
};


#endif //CHILLER_H
