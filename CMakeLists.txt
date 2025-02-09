cmake_minimum_required(VERSION 3.10)
project(AtomEngine VERSION 0.0.1)

set(SFML_LIB_DIR ${PROJECT_SOURCE_DIR}/lib/SFML)

include_directories(${PROJECT_SOURCE_DIR}/include)

link_directories(${SFML_LIB_DIR})

set(SOURCE_FILES
    ${PROJECT_SOURCE_DIR}/src/core/Atom.cpp
    ${PROJECT_SOURCE_DIR}/src/core/Atom2D.cpp
    ${PROJECT_SOURCE_DIR}/src/core/Spr2D.cpp
    ${PROJECT_SOURCE_DIR}/src/core/Game.cpp
    ${PROJECT_SOURCE_DIR}/src/core/SceneManager.cpp
    ${PROJECT_SOURCE_DIR}/src/SFML/window.cpp
)

add_library(AtomEngine STATIC ${SOURCE_FILES})
target_include_directories(AtomEngine PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME} PUBLIC
    sfml-graphics-s
    sfml-audio-s
    sfml-network-s
    sfml-window-s
    sfml-system-s
)



set_target_properties(AtomEngine PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
)
