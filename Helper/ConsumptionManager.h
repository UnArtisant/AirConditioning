//
// Created by Raphael Barriet on 26/11/2024.
//

#ifndef CONSUMPTIONMANAGER_H
#define CONSUMPTIONMANAGER_H

class ConsumptionManager {
public:
    virtual ~ConsumptionManager() = default;
    virtual double getConsumption() = 0;
};

#endif //CONSUMPTIONMANAGER_H
