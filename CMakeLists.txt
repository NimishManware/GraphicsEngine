cmake_minimum_required(VERSION 3.20)
project(GameEngine CXX)

set(CMAKE_CXX_STANDARD 20)

# 1. Include platform-specific dependency scripts
include(engine/platform/GLFW/SetupGLFW.cmake)

# 2. engine Static Library Target
add_library(engine STATIC
    engine/core/application/app.cpp
    engine/platform/GLFW/GlfwWindow.cpp
)

target_include_directories(engine 
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(engine PRIVATE glfw)

# 3. Sandbox Executable Target
add_executable(sandbox 
    sandbox/sandbox.cpp
)

target_link_libraries(sandbox PRIVATE engine)

add_executable(event_test
    sandbox/event_test.cpp
)

target_link_libraries(event_test PRIVATE engine)


if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(engine PRIVATE
        -Wall
        -Wextra
        -Wpedantic
    )

    target_compile_options(sandbox PRIVATE
        -Wall
        -Wextra
        -Wpedantic
    )

    target_compile_options(event_test PRIVATE
        -Wall
        -Wextra
        -Wpedantic
    )
endif()
