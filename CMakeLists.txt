cmake_minimum_required(VERSION 3.17)
project(Proyecto_II_Client_CE2103_)

set(CMAKE_CXX_STANDARD 14)

file(GLOB ALL_REQUIRED_DLL "${CMAKE_CURRENT_LIST_DIR}/libs/SFML-2.5.1/bin/*.dll")
file(COPY ${ALL_REQUIRED_DLL} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

set(SFML_DIR "${CMAKE_CURRENT_LIST_DIR}/libs/SFML-2.5.1/lib/cmake/SFML")

find_package(SFML 2.5 COMPONENTS graphics window system network REQUIRED)
add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-window sfml-system sfml-network)
