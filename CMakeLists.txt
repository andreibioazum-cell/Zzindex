cmake_minimum_required(VERSION 3.10)
project(CubicBattle)
add_executable(CubicBattle main.c world.c)
target_link_libraries(CubicBattle raylib lua m log android)
