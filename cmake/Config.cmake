# -------------------------------------------------------------------------------------------------
# Application Settings
# -------------------------------------------------------------------------------------------------
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(BUILD_ID 001 CACHE STRING "Build ID which is comming from pipelines.")

set(VER_MAJ 1)      # App major version number
set(VER_MIN 0)      # App minor version number
set(VER_PAT 0)      # App patch version number
set(VER_BID 0)      # Pipeline build number

if(DEFINED ENV{BUILD_ID})
    set(VER_BID $ENV{BUILD_ID})
endif()

set(PROJECT_VERSION_MAJOR ${VER_MAJ})
set(PROJECT_VERSION_MINOR ${VER_MIN})
set(PROJECT_VERSION_PATCH ${VER_BID})
set(PROJECT_VERSION "${VER_MAJ}.${VER_MIN}.${VER_BID}")

message(STATUS "Application build version: ${VER_MAJ}.${VER_MIN}.${VER_BID}")

# -------------------------------------------------------------------------------------------------
# Write App Version to File for Setups
# -------------------------------------------------------------------------------------------------
function(write_app_version VER_MAJ VER_MIN VER_PAT)
    file ( WRITE
        "${CMAKE_CURRENT_BINARY_DIR}/BuildInfo.cmake"
        "{
        \"version\" : \"${VER_MAJ}.${VER_MIN}.${VER_BID}\"
        }"
        )
endfunction()
write_app_version(${VER_MAJ} ${VER_MIN} ${VER_PAT})

# Newer versions of the Android Toolchain only search find_package in SYSROOT directories
# by overwriting the CMAKE_FIND_ROOT_PATH_MODE_... values. Since we need our builds to recognize
# packages in artifacts folder we must override these settings
if (ANDROID)
    set( CMAKE_FIND_ROOT_PATH_MODE_PROGRAM BOTH )
    set( CMAKE_FIND_ROOT_PATH_MODE_LIBRARY BOTH )
    set( CMAKE_FIND_ROOT_PATH_MODE_INCLUDE BOTH )
    set( CMAKE_FIND_ROOT_PATH_MODE_PACKAGE BOTH )
endif()















