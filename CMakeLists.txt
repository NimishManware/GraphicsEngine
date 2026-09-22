cmake_minimum_required(VERSION 3.20)
project(GameEngine CXX)

set(CMAKE_CXX_STANDARD 20)

# 1. Include platform-specific dependency scripts
include(Engine/Platform/GLFW/SetupGLFW.cmake)

# 2. Engine Static Library Target
add_library(Engine STATIC
    Engine/Core/Application/app.cpp
    Engine/Core/Window/window.hpp
    Engine/Platform/GLFW/GlfwWindow.cpp
    Engine/Platform/GLFW/GlfwWindow.hpp
)

target_include_directories(Engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(Engine PRIVATE glfw)

# 3. Sandbox Executable Target
add_executable(Sandbox Sandbox/sandbox.cpp)
target_link_libraries(Sandbox PRIVATE Engine)