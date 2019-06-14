cmake_minimum_required(VERSION 3.14)
project(TestBarriles C)

set(CMAKE_C_STANDARD 11)

add_executable(TestBarriles gameController.c gameController.h gameWindow.c gameWindow.h)

find_package(SDL2 REQUIRED)
include_directories("usr/include/SDL2")
target_link_libraries(TestBarriles ${SDL2_LIBRARY} -lSDL2)
target_link_libraries(TestBarriles ${SDL2_LIBRARY}-lSDL2_mixer)
target_link_libraries(TestBarriles ${SDL2_image_LIBRARY} -lSDL2_image)
target_link_libraries(TestBarriles ${SDL2}-lSDL2_ttf)