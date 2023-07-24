cmake_minimum_required(VERSION 3.15)

project(05_template)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1 ) 

add_executable(${PROJECT_NAME} src/main.cpp )

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_custom_target(run ./${PROJECT_NAME})
