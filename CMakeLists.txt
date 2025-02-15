cmake_minimum_required(VERSION 3.10)
project(AtomEngine VERSION 0.0.2)

set(CMAKE_PREFIX_PATH "C:/Users/Admin/Documents/Atom-Engine/vcpkg_installed/x64-windows/share")
include_directories(${PROJECT_SOURCE_DIR}/include)

set( SOURCE_FILES
    ${PROJECT_SOURCE_DIR}/src/core/Atom.cpp
    ${PROJECT_SOURCE_DIR}/src/core/Atom2D.cpp
    ${PROJECT_SOURCE_DIR}/src/core/Game.cpp
    ${PROJECT_SOURCE_DIR}/src/core/SceneManager.cpp
    ${PROJECT_SOURCE_DIR}/src/core/Spr2D.cpp
    ${PROJECT_SOURCE_DIR}/src/SFML/window.cpp
)

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC 
    ${PROJECT_SOURCE_DIR}/include
    ${SFML_INCLUDE_DIRS} 
)

find_package(SFML COMPONENTS system window graphics audio CONFIG REQUIRED)

target_link_libraries(${PROJECT_NAME} PUBLIC  
    ${SFML_LIBRARIES} 
)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20) # o cxx_std_20 si quieres usar C++20
