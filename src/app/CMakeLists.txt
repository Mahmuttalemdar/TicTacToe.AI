# -------------------------------------------------------------------------------------------------
# Application
# -------------------------------------------------------------------------------------------------
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)


# -------------------------------------------------------------------------------------------------
# HEADERS & SOURCES
# -------------------------------------------------------------------------------------------------
# Source files *.cpp
set(SOURCES
    "${CMAKE_CURRENT_LIST_DIR}/src/main.cpp"
    )

# Resource files *.qrc
set(RESOURCES
   "${CMAKE_CURRENT_LIST_DIR}/ui/main.qrc"
    )


# -------------------------------------------------------------------------------------------------
# Project Definition
# -------------------------------------------------------------------------------------------------
if(ANDROID)
    add_library(${PROJECT_NAME} SHARED
        ${SOURCES}
        ${RESOURCES}
        )
else()
    add_executable(${PROJECT_NAME}
        ${SOURCES}
        ${RESOURCES}
        )
endif()


# -------------------------------------------------------------------------------------------------
# Link Libraries
# -------------------------------------------------------------------------------------------------
link_libraries(${PROJECT_NAME})
# import_static_libraries(${PROJECT_NAME})

target_link_libraries(
    ${PROJECT_NAME}
        PUBLIC sub::core
        PUBLIC sub::glue
        PUBLIC sub::interfaces
    )


# -------------------------------------------------------------------------------------------------
# Include Directories
# -------------------------------------------------------------------------------------------------
target_include_directories(
    ${PROJECT_NAME} PUBLIC
        ${CMAKE_SOURCE_DIR}/src
    )


# -------------------------------------------------------------------------------------------------
# Dependencies of application
# -------------------------------------------------------------------------------------------------
add_dependencies(
    ${PROJECT_NAME}
        sub::l10n
        sub::core
        sub::glue
        sub::interfaces
        sub::UIComponents
        sub::UIScreens
    )
