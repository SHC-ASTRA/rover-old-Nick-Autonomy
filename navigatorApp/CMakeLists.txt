cmake_minimum_required(VERSION 3.1.0)
project(navigator VERSION 0.1.0)



add_executable(${PROJECT_NAME} src/navigator.cpp)

file(GLOB CLASS_IMPLEMENTATIONS "source/*.cc")
add_library(nav 
    ${CLASS_IMPLEMENTATIONS}
)
message(${CLASS_IMPLEMENTATIONS})


target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/src)
target_link_libraries(nav)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})




set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)