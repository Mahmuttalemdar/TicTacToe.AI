# -------------------------------------------------------------------------------------------------
# Set Library
# -------------------------------------------------------------------------------------------------
project(UIComponents)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC OFF)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(AUTOMOC_MOC_OPTIONS -Muri=UIComponents)

# Static library definitions for QT
add_definitions(-DQT_PLUGIN)
add_definitions(-DQT_STATICPLUGIN=1)


# -------------------------------------------------------------------------------------------------
# HEADERS & SOURCES & RESOURCES
# -------------------------------------------------------------------------------------------------
# Source files *.cpp
set(SOURCES
    "${CMAKE_CURRENT_LIST_DIR}/source/ui_components_plugin.cpp"
    )

# Header files *.h
set(HEADERS
    "${CMAKE_CURRENT_LIST_DIR}/source/ui_components_plugin.h"
    )

# Resource files *.qrc
set(RESOURCES
   "${CMAKE_CURRENT_LIST_DIR}/imports/UIComponents/UIComponents.qrc"
   "${CMAKE_CURRENT_LIST_DIR}/imports/Theme/Theme.qrc"
    )


# Save qml dir in Global Property
add_qml_dir("${CMAKE_CURRENT_LIST_DIR}/imports")

# Add a library with the above sources
add_library(
    ${PROJECT_NAME} STATIC
        ${SOURCES}
        ${HEADERS}
        ${RESOURCES}
)


# -------------------------------------------------------------------------------------------------
# Link all libraries to target
# -------------------------------------------------------------------------------------------------
link_libraries(${PROJECT_NAME})


# -------------------------------------------------------------------------------------------------
# Include Directories
# -------------------------------------------------------------------------------------------------
target_include_directories(
    ${PROJECT_NAME} PUBLIC
        ${CMAKE_SOURCE_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/source
        )


# -------------------------------------------------------------------------------------------------
# Set Alias of Library to reach from parent executeable
# -------------------------------------------------------------------------------------------------
add_library(sub::UIComponents ALIAS ${PROJECT_NAME})
