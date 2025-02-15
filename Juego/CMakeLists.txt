cmake_minimum_required(VERSION 3.10)

project(JuegoNuevo LANGUAGES CXX)
include_directories(${PROJECT_SOURCE_DIR}/include)

link_directories(${CMAKE_SOURCE_DIR}/lib)

add_executable(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/src/main.cpp ${CMAKE_SOURCE_DIR}/src/Pajaro.cpp)

if (UNIX)
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
elseif(WIN32) 
    target_link_libraries(${PROJECT_NAME} PRIVATE
        AtomEngine
        sfml-graphics
        #sfml-audio
        sfml-network
        sfml-window
        sfml-system
    )
endif()

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)