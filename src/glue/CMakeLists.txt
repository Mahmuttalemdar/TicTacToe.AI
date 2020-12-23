# -------------------------------------------------------------------------------------------------
# Set Library
# -------------------------------------------------------------------------------------------------
project(glue)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(AUTOMOC_MOC_OPTIONS -Muri=Glue)

# Static library definitions for QT
add_definitions(-DQT_PLUGIN)
add_definitions(-DQT_STATICPLUGIN=1)


# -------------------------------------------------------------------------------------------------
# HEADERS & SOURCES
# -------------------------------------------------------------------------------------------------
# Source files *.cpp
set(SOURCES
    "${CMAKE_CURRENT_LIST_DIR}/src/entrance.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/src/glue_plugin.cpp"
    )

# Header files *.h
set(HEADERS
    "${CMAKE_CURRENT_LIST_DIR}/src/entrance.h"
    "${CMAKE_CURRENT_LIST_DIR}/src/entrance_p.h"
    "${CMAKE_CURRENT_LIST_DIR}/src/glue_plugin.h"
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
# Include Path
# -------------------------------------------------------------------------------------------------
target_include_directories(
    ${PROJECT_NAME} PUBLIC 
        ${CMAKE_SOURCE_DIR}/src
        ${CMAKE_BINARY_DIR}/include
)


# -------------------------------------------------------------------------------------------------
# Link Subsystems
# -------------------------------------------------------------------------------------------------  
target_link_libraries(
    ${PROJECT_NAME} PUBLIC
        sub::l10n
        sub::core
        sub::interfaces
        sub::UIComponents
        sub::UIScreens
)


# -------------------------------------------------------------------------------------------------
# Dependencies of library
# -------------------------------------------------------------------------------------------------
add_dependencies(${PROJECT_NAME}
    sub::l10n
    sub::core
    sub::interfaces
    sub::UIComponents
    sub::UIScreens
)


# -------------------------------------------------------------------------------------------------
# Set Alias of Library to reach from parent executeable
# -------------------------------------------------------------------------------------------------
add_library(sub::glue ALIAS ${PROJECT_NAME})
