cmake_minimum_required(VERSION 3.10.0)
project(AIKO VERSION 0.1.0)
include(ctest)
enable_testing()

add_executable(${PROJECT_NAME} src/ObjectDetection.cpp)

file(GLOB CLASS_IMPLEMENTATIONS "impl/*.cc")
add_library(detection ${CLASS_IMPLEMENTATIONS})

target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/src)
target_link_libraries(detection)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})
#target_link_libraries(${PROJECT_NAME} PRIVATE realsense2)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)