cmake_minimum_required(VERSION 3.1.0)
project(AUTONOMY)

add_subdirectory(arucoApp)
add_subdirectory(calib)
add_subdirectory(depthApp)
add_subdirectory(navigatorApp)


find_package(OpenCV REQUIRED)
include_directories(${OPENCV_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})
