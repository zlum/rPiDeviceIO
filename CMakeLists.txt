cmake_minimum_required(VERSION 3.0.0)
project(rPiDeviceIO LANGUAGES C CXX)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
    set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
endif(NOT CMAKE_BUILD_TYPE)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++14 -lstdc++ -lm -Wall -Wextra -Wpedantic")

if(NOT WIN32)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")
endif(NOT WIN32)

include_directories(hw_interface)
include_directories(device)
include_directories(measure)
include_directories(types)

#Interfaces
set(SourceGroup_IO
    "hw_interface/i2c/i2c.cpp"
    "hw_interface/i2c/i2c.h"
    "hw_interface/hardware.hpp"
)
source_group("rPiDeviceIO\\IO" FILES ${SourceGroup_IO})

#Devices
set(SourceGroup_BMP180
    "device/bmp180/bmp180.cpp"
    "device/bmp180/bmp180.h"
    "device/bmp180/bmp180_types.h"
    "device/bmp180/calc/bmp180_calc.cpp"
    "device/bmp180/calc/bmp180_calc.h"
    "device/bmp180/io/bmp180_io.cpp"
    "device/bmp180/io/bmp180_io.h"
)
source_group("rPiDeviceIO\\BMP180" FILES ${SourceGroup_BMP180})

#Types
set(SourceGroup_Types
    "types/int24.h"
    "types/int24_t/int24_t.cpp"
    "types/int24_t/int24_t.h"
    "types/int24_t/uint24_t.cpp"
    "types/int24_t/uint24_t.h"
    "types/utility/conversion.hpp"
    "types/utility/operators.hpp"
    "types/utility/integer.hpp"
)
source_group("rPiDeviceIO\\Types" FILES ${SourceGroup_Types})

#Tests
set(SourceGroup_Measure
    "measure/measure.cpp"
    "measure/measure.h"
)
source_group("rPiDeviceIO\\Measure" FILES ${SourceGroup_Measure})

#Tests
set(SourceGroup_Test
    "main.cpp"
)
source_group("rPiDeviceIO\\Test" FILES ${SourceGroup_Test})

set(SOURCE
    ${SourceGroup_IO}
    ${SourceGroup_BMP180}
    ${SourceGroup_Types}
    ${SourceGroup_Test}
    ${SourceGroup_Measure}
)

add_executable(${PROJECT_NAME} ${SOURCE})
