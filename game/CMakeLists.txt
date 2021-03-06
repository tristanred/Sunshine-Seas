#
# SunshineSeas Main CMakeLists
#

cmake_minimum_required(VERSION 3.9)
project(SunshineSeas)

# Get the architecture of the machine
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(ARCH x64)
else()
    set(ARCH x86)
endif()

# Use C++ 11
set(CMAKE_CXX_STANDARD 11)

#
# Setup Dependencies
#

# Include the Libtech CMake project
add_subdirectory("lib/MicroEngine")

# Include LibTech
include_directories("lib/MicroEngine/engine/lib/libtech/include")

# Include MicroEngine
include_directories("lib/MicroEngine/engine/include")

# Setup Windows dependencies
IF(WIN32)
ENDIF(WIN32)

# Setup Linux dependencies
IF(UNIX)
ENDIF(UNIX)

# Setup Mac dependencies
IF(APPLE)
ENDIF(APPLE)

#
# Setup common properties
#
IF(WIN32)
    add_definitions("-D_WINDOWS")
    add_definitions("-D_UNICODE")
    add_definitions("/Zc:strictStrings-")

    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
ENDIF(WIN32)

#
# Create projects
#

## SunshineSeas
file(GLOB_RECURSE GAME_SOURCES "src/*.cpp")
file(GLOB_RECURSE GAME_HEADERS "src/*.h")

# Add the engine files to be included by others
include_directories("include")

add_executable(SunshineSeas ${GAME_HEADERS} ${GAME_SOURCES})
target_link_libraries(SunshineSeas LIBTECH)
target_link_libraries(SunshineSeas MICROENGINE)

# add_subdirectory("../tools" ${CMAKE_CURRENT_BINARY_DIR}/tools)

#
# Adjust project properties
#
IF(WIN32)

set_target_properties(SunshineSeas PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "$(ProjectDir)/$(Configuration)")

ELSEIF(UNIX)

target_compile_options(SunshineSeas PRIVATE -Wall)

ENDIF(WIN32)

#
# Copy the dependencies to the output folder
#
IF(WIN32)
    #SDL2.dll
    add_custom_command(
        TARGET SunshineSeas POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${PROJECT_SOURCE_DIR}/lib/MicroEngine/engine/lib/SDL/windows/lib/$(PlatformTarget)/SDL2.dll"
        $<TARGET_FILE_DIR:SunshineSeas>
    )

    #SDL2_Image.dll
    add_custom_command(
        TARGET SunshineSeas POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${PROJECT_SOURCE_DIR}/lib/MicroEngine/engine/lib/SDL_image/windows/lib/$(PlatformTarget)/SDL2_image.dll"
        $<TARGET_FILE_DIR:SunshineSeas>
    )

    #libjpeg-9.dll
    add_custom_command(
        TARGET SunshineSeas POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${PROJECT_SOURCE_DIR}/lib/MicroEngine/engine/lib/SDL_image/windows/lib/$(PlatformTarget)/libjpeg-9.dll"
        $<TARGET_FILE_DIR:SunshineSeas>
    )

    #libpng16-16.dll
    add_custom_command(
        TARGET SunshineSeas POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${PROJECT_SOURCE_DIR}/lib/MicroEngine/engine/lib/SDL_image/windows/lib/$(PlatformTarget)/libpng16-16.dll"
        $<TARGET_FILE_DIR:SunshineSeas>
    )

    #libtiff-5.dll
    add_custom_command(
        TARGET SunshineSeas POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${PROJECT_SOURCE_DIR}/lib/MicroEngine/engine/lib/SDL_image/windows/lib/$(PlatformTarget)/libtiff-5.dll"
        $<TARGET_FILE_DIR:SunshineSeas>
    )

    #libwebp-4.dll
    add_custom_command(
        TARGET SunshineSeas POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${PROJECT_SOURCE_DIR}/lib/MicroEngine/engine/lib/SDL_image/windows/lib/$(PlatformTarget)/libwebp-4.dll"
        $<TARGET_FILE_DIR:SunshineSeas>
    )

    #SDL2_ttf.dll
    add_custom_command(
        TARGET SunshineSeas POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${PROJECT_SOURCE_DIR}/lib/MicroEngine/engine/lib/SDL_ttf/windows/lib/$(PlatformTarget)/SDL2_ttf.dll"
        $<TARGET_FILE_DIR:SunshineSeas>
    )

    #libfreetype-6.dll
    add_custom_command(
        TARGET SunshineSeas POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${PROJECT_SOURCE_DIR}/lib/MicroEngine/engine/lib/SDL_ttf/windows/lib/$(PlatformTarget)/libfreetype-6.dll"
        $<TARGET_FILE_DIR:SunshineSeas>
    )

    #zlib1.dll
    add_custom_command(
        TARGET SunshineSeas POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${PROJECT_SOURCE_DIR}/lib/MicroEngine/engine/lib/SDL_image/windows/lib/$(PlatformTarget)/zlib1.dll"
        $<TARGET_FILE_DIR:SunshineSeas>
    )

ENDIF(WIN32)

add_custom_command(
    TARGET SunshineSeas POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    "${PROJECT_SOURCE_DIR}/assets"
    $<TARGET_FILE_DIR:SunshineSeas>/assets
)

add_custom_command(
    TARGET SunshineSeas POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    "${PROJECT_SOURCE_DIR}/lib/MicroEngine/engine/assets"
    $<TARGET_FILE_DIR:SunshineSeas>/assets/engine
)