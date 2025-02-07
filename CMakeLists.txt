cmake_minimum_required (VERSION 3.10)

project (AtomEngine VERSION 0.0.1)

link_directories(${PROJECT_SOURCE_DIR}/lib)



add_library (${PROJECT_NAME} 
            STATIC ${PROJECT_SOURCE_DIR}/src/core/Atom.cpp
            ${PROJECT_SOURCE_DIR}/src/core/Game.cpp
            ${PROJECT_SOURCE_DIR}/src/OpenGL/window.cpp
            ${PROJECT_SOURCE_DIR}/src/core/SceneManager.cpp
)


target_link_libraries (
    ${PROJECT_NAME} PUBLIC 

)

target_link_directories(${PROJECT_NAME} PUBLIC
    ${PROJECT_SOURCE_DIR}/lib
)

