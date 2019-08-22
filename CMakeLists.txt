cmake_minimum_required(VERSION 3.12)
project(ex2AC)

set(CMAKE_CXX_STANDARD 14)

add_executable(ex2AC main.cpp interface.h MyEmployee.cpp MyEmployee.h Date.cpp MyPlane.cpp MyPlane.h MyFlight.cpp MyFlight.h MyCustomer.cpp MyCustomer.h MyReservation.cpp MyReservation.h MyImplementation.h MyImplementation.cpp)