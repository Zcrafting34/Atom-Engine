cmake_minimum_required(VERSION 3.10)

project(JuegoNuevo LANGUAGES CXX)
include_directories(${PROJECT_SOURCE_DIR}/include)

link_directories(${CMAKE_SOURCE_DIR}/lib)

add_executable(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/src/main.cpp)

target_link_libraries(${PROJECT_NAME} PUBLIC
    AtomEngine
    sfml-graphics-s
    sfml-audio-s
    sfml-network-s
    sfml-window-s
    sfml-system-s
    X11
    Xrandr
    Xi
    Xcursor
    udev
)
