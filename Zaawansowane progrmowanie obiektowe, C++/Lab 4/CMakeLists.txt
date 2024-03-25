cmake_minimum_required(VERSION 3.25)
project(Lab_4)

set(CMAKE_CXX_STANDARD 17)

add_executable(Lab_4 main.cpp Citizen.cpp Citizen.h City.h PostalIndex.h PostalIndex.cpp City.cpp Functor.cpp Functor.h)
