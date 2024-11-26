cmake_minimum_required(VERSION 3.29)
project(AirConditioning)

set(CMAKE_CXX_STANDARD 20)

add_executable(AirConditioning main.cpp
        Entity/Actuator/Actuator.cpp
        Entity/Actuator/Actuator.h
        Entity/Place/Place.cpp
        Entity/Place/Place.h
        GlobalState.h
        Entity/Pump/Pump.cpp
        Entity/Pump/Pump.h
        Entity/FCU/Fcu.cpp
        Entity/FCU/Fcu.h
        Entity/Chiller/Chiller.cpp
        Entity/Chiller/Chiller.h
        Entity/CoolingTower/CoolingTower.cpp
        Entity/CoolingTower/CoolingTower.h
        Helper/PumpManager.h
        Helper/ConsumptionManager.h
)
