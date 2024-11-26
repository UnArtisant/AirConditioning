//
// Created by Raphael Barriet on 22/11/2024.
//

#ifndef ACTUATOR_H
#define ACTUATOR_H


class Actuator {
protected:
    bool is_active;
    double power_consumption;

public:
    explicit Actuator(double c_power_consumption);

    virtual ~Actuator() = default;

    virtual void deactivate();

    virtual void activate();

    [[nodiscard]] bool isActive() const;

    [[nodiscard]] double getConsumption() const { return power_consumption; }
};


#endif //ACTUATOR_H
