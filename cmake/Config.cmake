# -------------------------------------------------------------------------------------------------
# Application Settings
# -------------------------------------------------------------------------------------------------
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(BUILD_ID 001 CACHE STRING "Build ID which is comming from pipelines.")

set(VER_MAJ 1)      # App major version number
set(VER_MIN 0)      # App minor version number
set(VER_PAT 1)      # App patch version number
set(VER_BID 1)      # Pipeline build number

if(DEFINED ENV{BUILD_ID})
    set(VER_BID $ENV{BUILD_ID})
endif()

set(PROJECT_VERSION_MAJOR ${VER_MAJ})
set(PROJECT_VERSION_MINOR ${VER_MIN})
set(PROJECT_VERSION_PATCH ${VER_BID})
set(PROJECT_VERSION "${VER_MAJ}.${VER_MIN}.${VER_BID}")

message(STATUS "CFG :: Application build version: ${VER_MAJ}.${VER_MIN}.${VER_BID}")

# -------------------------------------------------------------------------------------------------
# Deployment Mode
# -------------------------------------------------------------------------------------------------
set(DEPLOYMENT_MODE OFF CACHE BOOL "Deployment Mode, controlling deploy artifacts after build or not.")
message(STATUS "CFG :: Deployment Mode: ${DEPLOYMENT_MODE}")
