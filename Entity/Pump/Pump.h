//
// Created by Raphael Barriet on 25/11/2024.
//

#ifndef PUMP_H
#define PUMP_H
#include "../Actuator/Actuator.h"


class Pump final : public Actuator {
public:
    explicit Pump(int c_power_consumption);
};

#endif //PUMP_H
