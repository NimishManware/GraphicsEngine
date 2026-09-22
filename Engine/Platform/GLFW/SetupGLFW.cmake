# Engine/Platform/GLFW/SetupGLFW.cmake

# 1. Try to find local GLFW on the system (minimum version 3.3) without throwing an error if missing
find_package(glfw3 3.3 QUIET)

if(glfw3_FOUND)
    message(STATUS "Engine: Found system GLFW (Version ${glfw3_VERSION})")
else()
    message(STATUS "Engine: Local GLFW not found or version < 3.3. Fetching GLFW from GitHub...")
    
    include(FetchContent)
    FetchContent_Declare(
        glfw
        GIT_REPOSITORY https://github.com/glfw/glfw.git
        GIT_TAG        3.4
    )
    
    # Disable unneeded GLFW targets to speed up compilation
    set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
    set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
    set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
    set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)

    FetchContent_MakeAvailable(glfw)
endif()