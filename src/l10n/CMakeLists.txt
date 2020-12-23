# -------------------------------------------------------------------------------------------------
# Set Library (I10n)
# -------------------------------------------------------------------------------------------------
project(l10n)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(AUTOMOC_MOC_OPTIONS -Muri=l10n)

# Static library definitions for QT
add_definitions(-DQT_PLUGIN)
add_definitions(-DQT_STATICPLUGIN=1)


# -------------------------------------------------------------------------------------------------
# HEADERS & SOURCES
# -------------------------------------------------------------------------------------------------
# Source files *.cpp
set(SOURCES
    "${CMAKE_CURRENT_LIST_DIR}/src/l10n_plugin.cpp"
    )

# Header files *.h
set(HEADERS
    "${CMAKE_CURRENT_LIST_DIR}/src/l10n_plugin.h"
    )

# Add a library with the above sources
add_library(
    ${PROJECT_NAME} STATIC
    ${SOURCES}
    ${HEADERS}
    )

set_directory_properties(PROPERTIES CLEAN_NO_CUSTOM 1)

# -------------------------------------------------------------------------------------------------
# Link all libraries to target
# -------------------------------------------------------------------------------------------------
link_libraries(${PROJECT_NAME})


# -------------------------------------------------------------------------------------------------
# Include Path
# -------------------------------------------------------------------------------------------------
target_include_directories(
    ${PROJECT_NAME} PUBLIC
        ${CMAKE_SOURCE_DIR}/src
    )

# -------------------------------------------------------------------------------------------------
# Set Alias of Library to reach from parent executeable
# -------------------------------------------------------------------------------------------------
add_library(sub::l10n ALIAS ${PROJECT_NAME})
