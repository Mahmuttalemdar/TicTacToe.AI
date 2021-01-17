# -------------------------------------------------------------------------------------------------
# TicTacToe.AI game
# -------------------------------------------------------------------------------------------------
cmake_minimum_required(VERSION 3.10.2)

project(TicTacToe.AI LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# -------------------------------------------------------------------------------------------------
# CMake module Settings (path,list)
# -------------------------------------------------------------------------------------------------
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

# -------------------------------------------------------------------------------------------------
# Utilities
# -------------------------------------------------------------------------------------------------
include(Utilities)

# -------------------------------------------------------------------------------------------------
# Config Settings
# -------------------------------------------------------------------------------------------------
include(Config)

# -------------------------------------------------------------------------------------------------
# General settings
# -------------------------------------------------------------------------------------------------
include(BrandSettings)
include(ImportStaticLibraries)
include(Qt5LibraryManager)
include(Qt5ScxmlMacros)
include(Qt5Localization)

# -------------------------------------------------------------------------------------------------
# Add source
# -------------------------------------------------------------------------------------------------
add_subdirectory(src)

# -------------------------------------------------------------------------------------------------
# Set QML_IMPORT_PATH to QtCreator Environment
# -------------------------------------------------------------------------------------------------
set_property(GLOBAL PROPERTY GLOBAL_QML_DIRS "${GLOBAL_QML_DIRS}")
get_property(QML_DIRS GLOBAL PROPERTY GLOBAL_QML_DIR)
message("QML IMPORT PATH for QT Creator: ${QML_DIRS}")

set_property(GLOBAL PROPERTY QML_IMPORT_PATH "${QML_IMPORT_PATH}")
set(QML_IMPORT_PATH "${QML_IMPORT_PATH} ${QML_DIRS}" CACHE STRING "Qt Creator extra qml import paths" FORCE)
set(QML2_IMPORT_PATH "${QML2_IMPORT_PATH} ${QML_DIRS}" CACHE STRING "Qt Creator extra qml import paths" FORCE)

# -------------------------------------------------------------------------------------------------
# CPack
# -------------------------------------------------------------------------------------------------
include(Package)


