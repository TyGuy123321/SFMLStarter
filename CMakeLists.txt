cmake_minimum_required(VERSION 3.31)
project(<PROJECT_NAME>) # TODO: Name Here

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_PREFIX_PATH "/usr/local/opt/sfml")
find_package(SFML 3 COMPONENTS Graphics Window System REQUIRED)

set(ASSETS_SOURCE_DIR "${CMAKE_SOURCE_DIR}/assets")
set(ASSETS_OUTPUT_DIR "${CMAKE_BINARY_DIR}/assets")

add_executable(${PROJECT_NAME}
        main.cpp
        scenes/MainScene.cpp
        SceneManager.cpp
        Systems.cpp
)

include(FetchContent)

FetchContent_Declare(
        box2d
        GIT_REPOSITORY https://github.com/erincatto/box2d.git
        GIT_TAG v3.1.1
)

FetchContent_MakeAvailable(box2d)

FetchContent_Declare(
        entt
        GIT_REPOSITORY https://github.com/skypjack/entt.git
        GIT_TAG v3.15.0
)

FetchContent_MakeAvailable(entt)

target_link_libraries(${PROJECT_NAME}
        PRIVATE
        SFML::Graphics
        SFML::Window
        SFML::System
        box2d
)

target_include_directories(${PROJECT_NAME}
        PRIVATE
        ${entt_SOURCE_DIR}/src
)

add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${ASSETS_SOURCE_DIR}" "${ASSETS_OUTPUT_DIR}"
)

# Define a custom target used to build and run the game
add_custom_target(run
        COMMAND $<TARGET_FILE:${PROJECT_NAME}>
        DEPENDS ${PROJECT_NAME}
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)
