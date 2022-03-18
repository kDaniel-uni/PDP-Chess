cmake_minimum_required(VERSION 3.13)

project(pdp_echec)

set(CMAKE_CXX_STANDARD 14)

add_executable(pdp_echec src/main.cpp src/game.cpp)

target_include_directories(pdp_echec
        PRIVATE
        ${PROJECT_SOURCE_DIR}/include
        )