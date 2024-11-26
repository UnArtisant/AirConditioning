#include <iostream>

#include "GlobalState.h"
#include "Entity/Place/Place.h"

int main() {
    GlobalState &globalState = GlobalState::getInstance();

    AulasOne aulasOne;
    AulasTwo aulasTwo;
    BiblioTec biblioTec;

    double deltaTime = 1.0; // Simulate 1 hour

    // Simulate each hour for 24 hours
    for (int i = 0; i < 24; ++i) {
        int outdoorTemperature = globalState.getWeather(static_cast<int>(globalState.getClock()));
        std::cout << "Current time: " << globalState.getFormattedTime() << std::endl;

        aulasOne.updateRoomTemperature(outdoorTemperature, deltaTime);
        aulasTwo.updateRoomTemperature(outdoorTemperature, deltaTime);
        biblioTec.updateRoomTemperature(outdoorTemperature, deltaTime);

        // Display results
        std::cout << "Aulas One Consumption: " << aulasOne.getConsumption() << " kW\n";
        std::cout << "Aulas Two Consumption: " << aulasTwo.getConsumption() << " kW\n";
        std::cout << "BiblioTec Consumption: " << biblioTec.getConsumption() << " kW\n";

        // Increment the clock by 1 hour
        globalState.incrementClock(1.0);
    }
}
