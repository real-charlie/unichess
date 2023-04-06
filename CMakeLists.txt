cmake_minimum_required(VERSION 3.19)
project(UniChess C)

set(CMAKE_C_STANDARD 11)

add_executable(UniChess src/main.c headers/handle_arg.h src/handle_arg.c headers/error.h src/error.c headers/sime_game.h src/sime_game.c headers/move_actions.h src/move_actions.c)
add_compile_options(-fno-stack-protector)