cmake_minimum_required(VERSION 3.0.0)
project(rPiDeviceIO LANGUAGES C CXX)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
    set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
endif(NOT CMAKE_BUILD_TYPE)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++14 -lstdc++ -Wall -Wextra -Wpedantic")

if(NOT WIN32)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")
endif(NOT WIN32)

include_directories(hw_interface)

#Interfaces
set(SourceGroup_IO
    "hw_interface/i2c/i2c.cpp"
    "hw_interface/i2c/i2c.h"
    "hw_interface/deviceio.h"
)
source_group("rPiDeviceIO\\IO" FILES ${SourceGroup_IO})

#Tests
set(SourceGroup_Test
    "main.cpp"
)
source_group("rPiDeviceIO\\Test" FILES ${SourceGroup_Test})

set(SOURCE
    ${SourceGroup_IO}
    ${SourceGroup_Test}
)

add_executable(${PROJECT_NAME} ${SOURCE})
