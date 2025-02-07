cmake_minimum_required(VERSION 3.10)

project(JuegoNuevo LANGUAGES CXX)

include_directories(${PROJECT_SOURCE_DIR}../../include ${PROJECT_SOURCE_DIR}../../include/glad)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/src/main.cpp)


set(LIBRARY_PATH ${PROJECT_SOURCE_DIR}../../build/Debug)
set(LIBRARY_NAME "AtomEngine")

set(LIBRARY_PATH ${PROJECT_SOURCE_DIR}../../build/Debug)
set(LIBRARY_NAME "glfw3")

target_link_libraries(${PROJECT_NAME} PRIVATE ${LIBRARY_PATH}/${CMAKE_STATIC_LIBRARY_PREFIX}${LIBRARY_NAME}${CMAKE_STATIC_LIBRARY_SUFFIX})
