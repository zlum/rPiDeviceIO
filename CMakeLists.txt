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
    "device/bmp180/calc/bmp180_calc.cpp"
    "device/bmp180/calc/bmp180_calc.h"
    "device/bmp180/io/bmp180_io.cpp"
    "device/bmp180/io/bmp180_io.h"
    "device/bmp180/io/barometer/bmp180_bar.cpp"
    "device/bmp180/io/barometer/bmp180_bar.h"
    "device/bmp180/io/barometer/bmp180_bar_reg.h"
    "device/bmp180/io/thermometer/bmp180_therm.cpp"
    "device/bmp180/io/thermometer/bmp180_therm.h"
    "device/bmp180/io/thermometer/bmp180_therm_reg.h"
    "device/bmp180/io/bmp180_raw.h"
    "device/bmp180/io/bmp180_reg.h"
)
source_group("rPiDeviceIO\\BMP180" FILES ${SourceGroup_BMP180})

set(SourceGroup_MPU9255
    "device/mpu9255/mpu9255.cpp"
    "device/mpu9255/mpu9255.h"
    "device/mpu9255/mpu9255_types.h"
    "device/mpu9255/calc/mpu9255_calc.cpp"
    "device/mpu9255/calc/mpu9255_calc.h"
    "device/mpu9255/io/accelerometer/mpu9255_accel.cpp"
    "device/mpu9255/io/accelerometer/mpu9255_accel.h"
    "device/mpu9255/io/accelerometer/mpu9255_accel_reg.h"
    "device/mpu9255/io/gyroscope/mpu9255_gyro.cpp"
    "device/mpu9255/io/gyroscope/mpu9255_gyro.h"
    "device/mpu9255/io/gyroscope/mpu9255_gyro_reg.h"
    "device/mpu9255/io/magnetometer/mpu9255_mag.cpp"
    "device/mpu9255/io/magnetometer/mpu9255_mag.h"
    "device/mpu9255/io/magnetometer/mpu9255_mag_raw.h"
    "device/mpu9255/io/magnetometer/mpu9255_mag_reg.h"
    "device/mpu9255/io/mpu9255_io.cpp"
    "device/mpu9255/io/mpu9255_io.h"
    "device/mpu9255/io/mpu9255_raw.h"
    "device/mpu9255/io/mpu9255_reg.h"
)
source_group("rPiDeviceIO\\MPU9255" FILES ${SourceGroup_MPU9255})

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
    ${SourceGroup_MPU9255}
    ${SourceGroup_Types}
    ${SourceGroup_Measure}
    ${SourceGroup_Test}
)

add_executable(${PROJECT_NAME} ${SOURCE})
