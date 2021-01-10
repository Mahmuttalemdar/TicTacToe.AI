# -------------------------------------------------------------------------------------------------
# Set Library
# -------------------------------------------------------------------------------------------------
project(interfaces)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(AUTOMOC_MOC_OPTIONS -Muri=Interfaces)

# Static library definitions for QT
add_definitions(-DQT_PLUGIN)
add_definitions(-DQT_STATICPLUGIN=1)


# -------------------------------------------------------------------------------------------------
# HEADERS & SOURCES
# -------------------------------------------------------------------------------------------------
# Source files *.cpp
set(SOURCES
    "${CMAKE_CURRENT_LIST_DIR}/src/interfaces_plugin.cpp"
    # "${CMAKE_CURRENT_LIST_DIR}/src/controllers/application_controller.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/src/controllers/game_controller.cpp"
    )

# Header files *.h
set(HEADERS
    "${CMAKE_CURRENT_LIST_DIR}/src/interfaces_plugin.h"
    # "${CMAKE_CURRENT_LIST_DIR}/src/controllers/application_controller.h"
    "${CMAKE_CURRENT_LIST_DIR}/src/controllers/game_controller.h"
    )

# Adding library with the above source.
add_library(
    ${PROJECT_NAME} STATIC
        ${SOURCES}
        ${HEADERS}
)


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
        PUBLIC sub::core
)


# -------------------------------------------------------------------------------------------------
# Include Path
# -------------------------------------------------------------------------------------------------
target_include_directories(
    ${PROJECT_NAME} PUBLIC
        ${CMAKE_SOURCE_DIR}/src
        ${CMAKE_BINARY_DIR}/include
)

# -------------------------------------------------------------------------------------------------
# Dependencies of library
# -------------------------------------------------------------------------------------------------
add_dependencies(${PROJECT_NAME}
    sub::l10n
    sub::core
    sub::UIComponents
    sub::UIScreens
)


# -------------------------------------------------------------------------------------------------
# Set Alias of Library to reach from parent executeable
# -------------------------------------------------------------------------------------------------
add_library(sub::interfaces ALIAS ${PROJECT_NAME})


