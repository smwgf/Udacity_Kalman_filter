cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

add_definitions(-std=c++11)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

project(kalman_filter)

find_package (Eigen3 3.3 REQUIRED NO_MODULE)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
#include_directories(${Eigen_INCLUDE_DIRS})
#link_directories(${Eigen_LIBRARY_DIRS})
#add_definitions(${Eigen_DEFINITIONS})

# Executable for create matrix exercise
add_executable (kalman src/KF/kalman.cpp)
target_link_libraries (kalman Eigen3::Eigen)

add_executable (EKF src/EKF/kalman_filter.cpp src/EKF/main.cpp src/EKF/tracking.cpp)
target_link_libraries (EKF Eigen3::Eigen)

add_executable (UKF src/UKF/ukf_main.cpp src/UKF/UKF_sigma_point.cpp)
target_link_libraries (UKF Eigen3::Eigen)