# -------------------------------------------------------------------------------------------------
# Set Library
# -------------------------------------------------------------------------------------------------
project(core)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(AUTOMOC_MOC_OPTIONS -Muri=Core)

# Static library definitions for QT
add_definitions(-DQT_PLUGIN)
add_definitions(-DQT_STATICPLUGIN=1)


# -------------------------------------------------------------------------------------------------
# HEADERS & SOURCES
# -------------------------------------------------------------------------------------------------
# Source files *.cpp
set(SOURCES
    "${CMAKE_CURRENT_LIST_DIR}/src/ai/ai_player.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/src/core_plugin.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/src/settings/game_settings.cpp"

    "${CMAKE_CURRENT_LIST_DIR}/src/data/game_difficulty.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/src/data/tile_shape.cpp"

    "${CMAKE_CURRENT_LIST_DIR}/src/game/board.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/src/game/game_object.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/src/game/player.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/src/game/tile.cpp"

    "${CMAKE_CURRENT_LIST_DIR}/src/model/tile_shape_model.cpp"
    )

# Header files *.h
set(HEADERS
    "${CMAKE_CURRENT_LIST_DIR}/src/ai/ai_player.h"

    "${CMAKE_CURRENT_LIST_DIR}/src/core_plugin.h"
    "${CMAKE_CURRENT_LIST_DIR}/src/settings/game_settings.h"

    "${CMAKE_CURRENT_LIST_DIR}/src/data/game_difficulty.h"
    "${CMAKE_CURRENT_LIST_DIR}/src/data/tile_shape.h"

    "${CMAKE_CURRENT_LIST_DIR}/src/game/board.h"
    "${CMAKE_CURRENT_LIST_DIR}/src/game/game_object.h"
    "${CMAKE_CURRENT_LIST_DIR}/src/game/player.h"
    "${CMAKE_CURRENT_LIST_DIR}/src/game/tile.h"

    "${CMAKE_CURRENT_LIST_DIR}/src/model/tile_shape_model.h"
    )

# Resource files *.qrc
set(RESOURCES
   "${CMAKE_CURRENT_LIST_DIR}/res/Core.qrc"
    )

# Adding library with the above source.
add_library(
    ${PROJECT_NAME} STATIC
        ${SOURCES}
        ${HEADERS}
        ${RESOURCES}
)

# -------------------------------------------------------------------------------------------------
# Generate configure file and set properties
# -------------------------------------------------------------------------------------------------
configure_file(
    "${CMAKE_CURRENT_LIST_DIR}/../template/config.h.in"
    "${CMAKE_CURRENT_BINARY_DIR}/config/config.h"
   )
target_sources(${PROJECT_NAME} PRIVATE "${CMAKE_CURRENT_BINARY_DIR}/config/config.h")


# -------------------------------------------------------------------------------------------------
# Link all libraries to target
# -------------------------------------------------------------------------------------------------
link_libraries(${PROJECT_NAME})


# -------------------------------------------------------------------------------------------------
# Link Subsystems
# -------------------------------------------------------------------------------------------------
target_link_libraries(
    ${PROJECT_NAME}
        PUBLIC sub::l10n
)


# -------------------------------------------------------------------------------------------------
# Include Path
# -------------------------------------------------------------------------------------------------
target_include_directories(
    ${PROJECT_NAME} PUBLIC
        ${CMAKE_SOURCE_DIR}/src
        ${CMAKE_CURRENT_BINARY_DIR}/
)


# -------------------------------------------------------------------------------------------------
# Statecharts
# -------------------------------------------------------------------------------------------------
ks_add_statecharts(
    TARGET ${PROJECT_NAME}
    SCXML_FILES
        ${CMAKE_CURRENT_LIST_DIR}/src/statechart/Main.scxml
    OPTIONS "--namespace" "statechart"
            "--statemethods"
)


# -------------------------------------------------------------------------------------------------
# Set Alias of Library to reach from parent executeable
# -------------------------------------------------------------------------------------------------
add_library(sub::core ALIAS ${PROJECT_NAME})
