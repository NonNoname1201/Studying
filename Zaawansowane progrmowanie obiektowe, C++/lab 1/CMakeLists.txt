cmake_minimum_required(VERSION 3.25)
project(lab_1)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab_1 main.cpp src/person.h src/person.cpp src/student.h src/student.cpp src/Animal.h src/Animal.cpp src/Dog.h src/Dog.cpp src/Cat.h src/Cat.cpp)
