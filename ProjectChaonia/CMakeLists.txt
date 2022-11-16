cmake_minimum_required(VERSION 3.20)
project(ProjectChaonia)

set(CMAKE_CXX_STANDARD 14)



add_executable(ProjectChaonia main.cpp Character.cpp Character.h Interpreter.cpp Interpreter.h Object.cpp Object.h Room.cpp Room.h Item.cpp Item.h Weapon.cpp Weapon.h Command.cpp Command.h Player.cpp Player.h Game.cpp Game.h Connection.cpp Connection.h)
