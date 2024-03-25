cmake_minimum_required(VERSION 3.25)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

set(BOOST_ROOT "D:/c/Boost/boost_1_83_0")

find_package(Boost 1.83.0)

if(NOT Boost_FOUND)
    message(FATAL_ERROR "Could not find boost!")
endif()

FIND_PACKAGE(Boost REQUIRED)
IF (Boost_FOUND)
    INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})
    ADD_DEFINITIONS( "-DHAS_BOOST" )
ENDIF()

message("Boost_INCLUDE_DIR: " ${Boost_INCLUDE_DIR})

add_executable(untitled main.cpp Contacts.h Contact.cpp TempF.h Mix.h)
