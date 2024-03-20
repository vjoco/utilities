cmake_minimum_required(VERSION 3.10)
project(cc1)

# Add the executable target
add_executable(cc1 Hal.cpp cc1101_lucky.cpp Module.cpp CC1101/CC1101.cpp  PhysicalLayer.cpp)
