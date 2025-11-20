cmake_minimum_required(VERSION 3.15 FATAL_ERROR)
project(qdstest LANGUAGES C CXX VERSION 0.0.0)

set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

cmake_policy(SET CMP0100 NEW)
set(CMAKE_AUTOMOC ON CACHE BOOL "" FORCE)
set(CMAKE_AUTORCC ON CACHE BOOL "" FORCE)
set(CMAKE_AUTOUIC ON CACHE BOOL "" FORCE)

file(TO_CMAKE_PATH "$ENV{QTDIR}" QT_INSTALL_ROOT)
list(APPEND CMAKE_PREFIX_PATH "${QT_INSTALL_ROOT}/lib/cmake")
find_package(Qt6 REQUIRED COMPONENTS Core)
qt_standard_project_setup(REQUIRES 6.5)

if(MSVC)
    add_compile_options(/MP)
    add_compile_options(/W3)
endif()

add_subdirectory(qdstest)
