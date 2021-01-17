include(CMakeParseArguments)

# -------------------------------------------------------------------------------------------------
# Qt based dependencies
# -------------------------------------------------------------------------------------------------
find_package(
    Qt5 REQUIRED COMPONENTS
    Core Gui Qml Scxml Svg Xml
    )

# -------------------------------------------------------------------------------------------------
# Qt based dependencies (Android Platforms)
# -------------------------------------------------------------------------------------------------
if(ANDROID)
    find_package(
        Qt5 REQUIRED COMPONENTS
        AndroidExtras
        )
endif(ANDROID)

# -------------------------------------------------------------------------------------------------
# Link libraries function ( @param : Target name )
# -------------------------------------------------------------------------------------------------
function(link_libraries)
    set(options)
    set(oneValueArgs TARGET TARGET_NAME)
    set(multiValueArgs)

    cmake_parse_arguments(ARGS "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN} )
    
    if (NOT ARGN)
        message(CRITICAL "LIBRARY MANAGER :: TARGET required a library name.")
    endif()

    # -------------------------------------------------------------------------------------------------
    # Link Qt Libraries to TARGET
    # -------------------------------------------------------------------------------------------------
    target_link_libraries(
        ${ARGN} LINK_PRIVATE
            Qt5::Core Qt5::Gui Qt5::Qml Qt5::Scxml Qt5::Svg Qt5::Xml
    )

    # -------------------------------------------------------------------------------------------------
    # Link Qt Libraries to TARGET (Android Platforms)
    # -------------------------------------------------------------------------------------------------
    if(ANDROID)
        target_link_libraries(
            ${ARGN} LINK_PRIVATE
            Qt5::AndroidExtras
        )
    endif(ANDROID)

endfunction()
