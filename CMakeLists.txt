cmake_minimum_required(VERSION 3.5.0)
project(autonomy VERSION 0.1.0)



add_executable(${PROJECT_NAME} Autonomy.cpp)

file(GLOB NAV_CLASS_IMPLEMENTATIONS "navigatorApp/navImpl/*.cc")
add_library(nav 
    ${NAV_CLASS_IMPLEMENTATIONS}
)
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/navigatorApp/include)
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/navigatorApp/src)
target_link_libraries(${PROJECT_NAME} nav)


file(GLOB AIKO_CLASS_IMPLEMENTATIONS "arucoApp/impl/*.cc")
add_library(aiko
    ${AIKO_CLASS_IMPLEMENTATIONS}
)
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/arucoApp/include)
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/acrucoApp/src)
target_link_libraries(${PROJECT_NAME} aiko)



find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
link_directories(${OpenCV_LIB_DIR})
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})


find_package(realsense2 REQUIRED)
include_directories(${realsense_INCLUDE_DIR})


find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)


ament_target_dependencies(${PROJECT_NAME} rclcpp std_msgs)
install(
    DIRECTORY navigatorApp/include
    DESTINATION installDest 
)
install(
    DIRECTORY arucoApp/include
    DESTINATION installDest
)
install(
    TARGETS ${PROJECT_NAME}
    DESTINATION lib/${PROJECT_NAME}
)

ament_package()