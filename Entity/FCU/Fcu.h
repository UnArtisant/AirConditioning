#ifndef FCU_H
#define FCU_H

#include "../../Helper/ConsumptionManager.h"
#include "../../Helper/PumpManager.h"

class FCU : public PumpManager, public ConsumptionManager {
protected:
    explicit FCU(int pumpCount, int pumpSetting = 11);

    virtual double calculateTTCf(int active_pumps) = 0;

public:
    void activate() override;

    void deactivate() override;

    [[nodiscard]] double getCoolingCapacity(double RToff, double Tch);

    [[nodiscard]] double getConsumption() override;
};

class AulasTwoFCU : public FCU {
public:
    explicit AulasTwoFCU();

protected:
    double calculateTTCf(int active_pumps) override;
};

class AulasOneFCU : public FCU {
public:
    explicit AulasOneFCU();

protected:
    double calculateTTCf(int active_pumps) override;
};

class BiblioTecFCU : public FCU {
public:
    explicit BiblioTecFCU();

protected:
    double calculateTTCf(int active_pumps) override;
};

#endif // FCU_H
