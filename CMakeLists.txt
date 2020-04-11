cmake_minimum_required(VERSION 3.0.0)
project(rPiDeviceIO LANGUAGES C CXX)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
    set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
endif(NOT CMAKE_BUILD_TYPE)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++17 -lstdc++ -lm -Wall -Wextra -Wpedantic")

if(NOT WIN32)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")
endif(NOT WIN32)

include_directories(hw_interface)
include_directories(device)
include_directories(measure)
include_directories(types)

# Interfaces
set(SourceGroup_IO
    "hw_interface/i2c_prot/i2c.cpp"
    "hw_interface/i2c_prot/i2c.h"
    "hw_interface/modbus_prot/modbus.cpp"
    "hw_interface/modbus_prot/modbus.h"
    "hw_interface/hardware.hpp"
)
source_group("rPiDeviceIO\\IO" FILES ${SourceGroup_IO})

# Devices
set(SourceGroup_Devices
    "device/device.cpp"
    "device/device.h"
    "device/device_list.h"
    "device/abstract/bps.cpp"
    "device/abstract/bps.h"
    "device/abstract/imu.cpp"
    "device/abstract/imu.h"
    "device/abstract/unit/accelerometer.h"
    "device/abstract/unit/barometer.h"
    "device/abstract/unit/gyroscope.h"
    "device/abstract/unit/magnetometer.h"
    "device/abstract/unit/thermometer.h"
    "device/abstract/unit/timer.h"
)
source_group("rPiDeviceIO\\Devices" FILES ${SourceGroup_Devices})

set(SourceGroup_BMP180
    "device/bmp180/bmp180.cpp"
    "device/bmp180/bmp180.h"
    "device/bmp180/calc/bmp180_calc.cpp"
    "device/bmp180/calc/bmp180_calc.h"
    "device/bmp180/io/bmp180_io.cpp"
    "device/bmp180/io/bmp180_io.h"
    "device/bmp180/io/bmp180_raw.h"
    "device/bmp180/io/bmp180_reg.h"
    "device/bmp180/io/barometer/bmp180_bar.cpp"
    "device/bmp180/io/barometer/bmp180_bar.h"
    "device/bmp180/io/barometer/bmp180_bar_reg.h"
    "device/bmp180/io/thermometer/bmp180_therm.cpp"
    "device/bmp180/io/thermometer/bmp180_therm.h"
    "device/bmp180/io/thermometer/bmp180_therm_reg.h"
)
source_group("rPiDeviceIO\\BMP180" FILES ${SourceGroup_BMP180})

set(SourceGroup_MPU9255
    "device/mpu9255/mpu9255.cpp"
    "device/mpu9255/mpu9255.h"
    "device/mpu9255/calc/mpu9255_calc.cpp"
    "device/mpu9255/calc/mpu9255_calc.h"
    "device/mpu9255/io/mpu9255_io.cpp"
    "device/mpu9255/io/mpu9255_io.h"
    "device/mpu9255/io/mpu9255_raw.h"
    "device/mpu9255/io/mpu9255_reg.h"
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
)
source_group("rPiDeviceIO\\MPU9255" FILES ${SourceGroup_MPU9255})

set(SourceGroup_OWEN_SV01
    device/owen_sv01/owen_sv01.cpp
    device/owen_sv01/owen_sv01.h
    device/owen_sv01/io/owen_sv01_io.cpp
    device/owen_sv01/io/owen_sv01_io.h
    device/owen_sv01/io/owen_sv01_reg.h
)
source_group("rPiDeviceIO\\OWEN_SV01" FILES ${SourceGroup_OWEN_SV01})

set(SourceGroup_OWEN_TRM202
    device/owen_trm202/owen_trm202.cpp
    device/owen_trm202/owen_trm202.h
    device/owen_trm202/io/owen_trm202_io.cpp
    device/owen_trm202/io/owen_trm202_io.h
    device/owen_trm202/io/owen_trm202_reg.h
)
source_group("rPiDeviceIO\\OWEN_TRM202" FILES ${SourceGroup_OWEN_TRM202})

# Types
set(SourceGroup_Types
    "types/bps_types.h"
    "types/imu_types.h"
    "types/unit/timer_types.h"
    "types/int24/int24.h"
    "types/int24/int24_t/int24_t.cpp"
    "types/int24/int24_t/int24_t.h"
    "types/int24/int24_t/uint24_t.cpp"
    "types/int24/int24_t/uint24_t.h"
    "types/int24/utility/conversion.hpp"
    "types/int24/utility/operators.hpp"
    "types/int24/utility/integer.hpp"
)
source_group("rPiDeviceIO\\Types" FILES ${SourceGroup_Types})

# Tests
set(SourceGroup_Measure
    "measure/meanfilter.cpp"
    "measure/meanfilter.h"
    "measure/measure.cpp"
    "measure/measure.h"
)
source_group("rPiDeviceIO\\Measure" FILES ${SourceGroup_Measure})

# Utility
set(SourceGroup_Test
    "main.cpp"
)
source_group("rPiDeviceIO\\Test" FILES ${SourceGroup_Test})

set(SOURCE
    ${SourceGroup_IO}
    ${SourceGroup_Devices}
    ${SourceGroup_BMP180}
    ${SourceGroup_MPU9255}
    ${SourceGroup_OWEN_SV01}
    ${SourceGroup_OWEN_TRM202}
    ${SourceGroup_Types}
    ${SourceGroup_Measure}
    ${SourceGroup_Test}
)

add_executable(${PROJECT_NAME} ${SOURCE})
target_link_libraries(${PROJECT_NAME} modbus)
