cmake_minimum_required(VERSION 3.10)

project(StoreManagementSystem)

set(CMAKE_CXX_STANDARD 17)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
find_package(OpenCV REQUIRED)

add_executable(StoreManagementSystem main.cpp)

target_link_libraries(StoreManagementSystem Qt6::Widgets ${OpenCV_LIBS})
