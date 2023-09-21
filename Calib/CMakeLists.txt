cmake_minimum_required(VERSION 3.1.0)
project(Calib VERSION 0.1.0)

include(ctest)
enable_testing()

add_executable(${PROJECT_NAME} src/calibrator.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/src)

find_package(OpenCV REQUIRED)
include_directories(${OPENCV_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})



set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)