cmake_minimum_required(VERSION 3.23)
project(template)

# disable building all of sfml library except sound components
set(SFML_BUILD_GRAPHICS OFF CACHE BOOL "" FORCE)
set(SFML_BUILD_WINDOW OFF CACHE BOOL "" FORCE)
set(SFML_BUILD_NETWORK OFF CACHE BOOL "" FORCE)

add_subdirectory(./external/glad)
add_subdirectory(./external/glm)
add_subdirectory(./external/glfw)
add_subdirectory(./external/stb)
add_subdirectory(./external/sfml)

add_subdirectory(src)