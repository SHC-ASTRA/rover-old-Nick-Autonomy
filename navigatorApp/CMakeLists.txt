cmake_minimum_required(VERSION 3.5.0)
project(navigator VERSION 0.1.0)



add_executable(${PROJECT_NAME} src/navigator.cpp)

file(GLOB CLASS_IMPLEMENTATIONS "navImpl/*.cc")
add_library(nav 
    ${CLASS_IMPLEMENTATIONS}
)
#message(${CLASS_IMPLEMENTATIONS})


target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/src)
target_link_libraries(nav)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)



ament_target_dependencies(${PROJECT_NAME} rclcpp std_msgs)
install(
    DIRECTORY include/
    DESTINATION include 
)

install(
    TARGETS nav
    DESTINATION lib/${PROJECT_NAME}
)

ament_package()