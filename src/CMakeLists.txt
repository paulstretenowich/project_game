cmake_minimum_required(VERSION 2.6)
project(la_legende_de_Dora)

set(
    CMAKE_MODULE_PATH
    ${CMAKE_MODULE_PATH}
    "${PROJECT_SOURCE_DIR}/cmake"
    )

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(SDL2_mixer REQUIRED)

set(
    SOURCES_FILES
    ${PROJECT_SOURCE_DIR}/main.cpp
    ${PROJECT_SOURCE_DIR}/game.cpp
    ${PROJECT_SOURCE_DIR}/menustate.cpp
    ${PROJECT_SOURCE_DIR}/optionstate.cpp
    ${PROJECT_SOURCE_DIR}/instructionstate.cpp
    ${PROJECT_SOURCE_DIR}/introstate.cpp
    ${PROJECT_SOURCE_DIR}/deadstate.cpp
    ${PROJECT_SOURCE_DIR}/stage1state.cpp
    ${PROJECT_SOURCE_DIR}/foreststate.cpp
    ${PROJECT_SOURCE_DIR}/mountainstate.cpp
    ${PROJECT_SOURCE_DIR}/seatownstate.cpp
    ${PROJECT_SOURCE_DIR}/seastate.cpp
    ${PROJECT_SOURCE_DIR}/castlestate.cpp
    ${PROJECT_SOURCE_DIR}/endstate.cpp
    ${PROJECT_SOURCE_DIR}/texturemanager.cpp
    )

include_directories(
    ${SDL2_INCLUDE_DIRS}
    ${SDL2_IMAGE_INCLUDE_DIRS}
    ${SDL2TTF_INCLUDE_DIRS}
    ${SDL2MIXER_INCLUDE_DIRS}
    )

add_executable(
    ${PROJECT_NAME}
    ${SOURCES_FILES}
    )

target_link_libraries(
    ${PROJECT_NAME}
    ${SDL2_LIBRARY}
    ${SDL2_IMAGE_LIBRARY}
    ${SDL2_TTF_LIBRARY}
    ${SDL2_MIXER_LIBRARY}
    )
