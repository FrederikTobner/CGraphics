cmake_minimum_required(VERSION 3.6)

set(THIS GLFWGLAD)

project( ${THIS} )

# Set used C standard to C11
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

# Set C++ standard to 14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package( OpenGL REQUIRED )

include_directories( ${OPENGL_INCLUDE_DIRS} )

set( GLFW_BUILD_DOCS OFF CACHE BOOL  "GLFW lib only" )
set( GLFW_INSTALL OFF CACHE BOOL  "GLFW lib only" )

# Builds glad - https://gen.glad.sh/
add_subdirectory(external/glad)

# Builds glfw - https://www.glfw.org/
add_subdirectory(external/glfw)

if( MSVC )
    SET( CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /ENTRY:mainCRTStartup" )
endif()

set(HEADERS
src/utilities.h
)

set(SOURCES
src/utilities.c    
src/display.c
)

add_executable( ${THIS} WIN32 ${SOURCES} )

# for linmath.h
target_include_directories( ${THIS} PUBLIC external/glfw/deps)

target_link_libraries( ${THIS} 
${OPENGL_LIBRARIES} 
glfw
glad
)

if( MSVC )
    if(${CMAKE_VERSION} VERSION_LESS "3.6.0") 
        message( "\n\t[ WARNING ]\n\n\tCMake version lower than 3.6.\n\n\t - Please update CMake and rerun; OR\n\t - Manually set 'GLFW-CMake-starter' as StartUp Project in Visual Studio.\n" )
    else()
        set_property( DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${THIS} )
    endif()
endif()