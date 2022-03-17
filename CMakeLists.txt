cmake_minimum_required(VERSION 3.20)
project(pdp_echec)

set(CMAKE_CXX_STANDARD 14)

add_executable(pdp_echec
        src/main.cpp src/game.cpp src/game.h src/ai_player.h src/move.h src/ai_factory.h)
