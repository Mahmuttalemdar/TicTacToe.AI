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
# Project Icon
# -------------------------------------------------------------------------------------------------
if(APPLE)
    set(${PROJECT_NAME}_ICON tictactoe.icns)
elseif(WINDOWS)
    set(${PROJECT_NAME}_ICON tictactoe.ico)
elseif(UNIX AND NOT APPLE)
    set(${PROJECT_NAME}_ICON tictactoe.png)
endif()

set(ICON_FILE  ${CMAKE_SOURCE_DIR}/res/img/app/${${PROJECT_NAME}_ICON})
target_sources(${PROJECT_NAME} PRIVATE ${ICON_FILE})


# -------------------------------------------------------------------------------------------------
# Application Bundle
# -------------------------------------------------------------------------------------------------
if(APPLE)
    set_source_files_properties(
        ${ICON_FILE}
        PROPERTIES MACOSX_PACKAGE_LOCATION "Resources"
        )

    set_target_properties(${PROJECT_NAME} PROPERTIES
        MACOSX_BUNDLE true
        MACOSX_BUNDLE_INFO_PLIST ${CMAKE_SOURCE_DIR}/packaging/platform/macOS/Info.plist.in
        MACOSX_BUNDLE_ICON_FILE ${${PROJECT_NAME}_ICON}
        INSTALL_RPATH "@loader_path/../Frameworks"
        INSTALL_RPATH_USE_LINK_PATH TRUE
        )

elseif(WIN32)
    set_target_properties(${PROJECT_NAME} PROPERTIES
        WIN32_EXECUTABLE true
        )

    set(RESOURCE_FILE "${CMAKE_BINARY_DIR}/mPower.rc")
    configure_file("${CMAKE_SOURCE_DIR}/packaging/platform/Windows/resource_template.rc.in" "${RESOURCE_FILE}")

    ENABLE_LANGUAGE(RC)
    target_sources(${PROJECT_NAME} PRIVATE ${RESOURCE_FILE})

elseif(UNIX AND NOT APPLE)
    set(RESOURCE_FILE "${CMAKE_BINARY_DIR}/${PROJECT_NAME}.desktop")
    configure_file("${CMAKE_SOURCE_DIR}/packaging/platform/Linux/gnome_dekstop_entry.in" "${RESOURCE_FILE}")
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
