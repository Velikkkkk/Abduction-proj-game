cmake_minimum_required(VERSION 4.3)
project(newonemoregame)

set(CMAKE_CXX_STANDARD 20)

add_executable(newonemoregame main.cpp
        player.cpp
        player.h
        item.cpp
        item.h
        location.cpp
        location.h
        ending.cpp
        ending.h
        mainGame.cpp
        mainGame.h)
