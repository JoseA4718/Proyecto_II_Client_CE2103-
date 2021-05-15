cmake_minimum_required(VERSION 3.19)
project(backend)

set(CMAKE_CXX_STANDARD 14)

add_executable(backend main.cpp "soccar/Data Structures/LinkedList.h" "soccar/Data Structures/Matrix.h" soccar/Field.h soccar/Player.h "soccar/Ball.h" soccar/Box/Box.h soccar/Box/BoundBox.h soccar/Box/ObstacleBox.h soccar/Box/GoalLineBox.h soccar/Box/NormalBox.h soccar/Game.h soccar/GameSettings.h)