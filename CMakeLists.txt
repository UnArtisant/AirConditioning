cmake_minimum_required(VERSION 3.29)
project(AirConditioning)

set(CMAKE_CXX_STANDARD 20)

add_executable(AirConditioning main.cpp
        Entity/Actuator/Actuator.cpp
        Entity/Actuator/Actuator.h
        Entity/FluidCircuit/FluidCircuit.cpp
        Entity/FluidCircuit/FluidCircuit.h
        Entity/Place/Place.cpp
        Entity/Place/Place.h)
