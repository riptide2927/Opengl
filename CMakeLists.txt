cmake_minimum_required(VERSION 3.21.0)

set(NAME Opengl)

project(${NAME} VERSION 0.23.1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g -std=c++20")

find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")

    option(GIT_SUBMODULE "Check submodules during build" ON)
    if(GIT_SUBMODULE)
        message(STATUS "Submodule download")
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} RESULT_VARIABLE GIT_SUBMOD_RESULT)

        if(NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "git submodule update --init failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
        endif()
    endif()
endif()

set(source_dir "${PROJECT_SOURCE_DIR}/src")

file(GLOB_RECURSE SOURCES "${source_dir}/*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES} vendor/glad/src/glad.c)

add_subdirectory(external/glfw)
add_subdirectory(external/assimp)

target_include_directories(${PROJECT_NAME}
    PUBLIC external/glfw/include
    PUBLIC external/assimp/include
    PUBLIC external/glm/glm
    PUBLIC vendor/glad/include
)

target_link_directories(${PROJECT_NAME}
    PRIVATE external/glfw/src
    PRIVATE extrenal/assimp/lib
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE glfw
    PRIVATE SOIL
    PRIVATE assimp
    PRIVATE GL
)