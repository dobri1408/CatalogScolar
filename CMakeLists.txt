cmake_minimum_required(VERSION 3.24)
project(oop)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(WARNINGS_AS_ERRORS "Treat warnings as errors" OFF)
option(USE_ASAN "Use Address Sanitizer" OFF)
option(USE_MSAN "Use Memory Sanitizer" OFF)

if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    set(CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/install" CACHE PATH "default install path" FORCE)
endif()

# FetchContent for nlohmann_json
include(FetchContent)
FetchContent_Declare(
        json
        GIT_REPOSITORY https://github.com/nlohmann/json.git
        GIT_TAG v3.10.5
)
FetchContent_MakeAvailable(json)

# Define the executable
add_executable(${PROJECT_NAME}
        main.cpp
        Barchart.cpp
        Parinte.cpp
        Materie.cpp
        Nota.cpp
        Student.cpp
        Catalog.cpp
        Clasa.cpp
        Scoala.cpp
        Person.cpp
        Profesor.cpp
        SchoolAPI.cpp
)

# Link libraries
target_link_libraries(${PROJECT_NAME} PRIVATE nlohmann_json::nlohmann_json)

# Include directories (update these if you have additional directories)
target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/include)

# Compiler options and definitions
if(WARNINGS_AS_ERRORS)
    if(MSVC)
        target_compile_options(${PROJECT_NAME} PRIVATE /WX)
    else()
        target_compile_options(${PROJECT_NAME} PRIVATE -Werror)
    endif()
endif()

if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4 /permissive- /wd4244 /wd4267 /wd4996)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic)
endif()

# Sanitizers Setup Directly (Simplified Version)
if(USE_ASAN OR USE_MSAN)
    if(MSVC)
        target_compile_options(${PROJECT_NAME} PRIVATE "/fsanitize=address")
        target_link_options(${PROJECT_NAME} PRIVATE "/fsanitize=address")
    else()
        target_compile_options(${PROJECT_NAME} PRIVATE "-fsanitize=address")
        target_link_options(${PROJECT_NAME} PRIVATE "-fsanitize=address")
    endif()
endif()

# Installation settings
install(TARGETS ${PROJECT_NAME} DESTINATION bin)
