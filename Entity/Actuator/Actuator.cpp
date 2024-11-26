//
// Created by Raphael Barriet on 22/11/2024.
//

#include "Actuator.h"

Actuator::Actuator(double c_power_consumption): is_active(false), power_consumption(c_power_consumption) {
}


void Actuator::activate() {
    is_active = true;
}

void Actuator::deactivate() {
    is_active = false;
}

bool Actuator::isActive() const {
    return is_active;
}
