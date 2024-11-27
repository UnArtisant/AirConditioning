#ifndef ACTUATOR_H
#define ACTUATOR_H

class Actuator {
protected:
    bool state; // ON = true, OFF = false
    double powerConsumptionPerHour;
    int operationalCycles;
    double temperatureTransferCoefficient;

public:
    Actuator(double power, double ttc);
    virtual ~Actuator() = default;

    virtual void turnOn();
    virtual void turnOff();

    bool isOn() const;
    double getPowerConsumption() const;
    int getOperationalCycles() const;
    double getTTC() const;
};

class FanCoil : public Actuator {
public:
    FanCoil(double power, double ttc);
};

class Chiller : public Actuator {
public:
    Chiller(double power, double ttc);
};

class CoolingTower : public Actuator {
public:
    CoolingTower(double power, double ttc);
};

#endif // ACTUATOR_H
