include(CMakeParseArguments)

# -------------------------------------------------------------------------------------------------
# Import static libraries function ( @param : Target name )
# -------------------------------------------------------------------------------------------------
function(import_static_libraries)
    set(options)
    set(oneValueArgs TARGET TARGET_NAME)
    set(multiValueArgs)

    cmake_parse_arguments(ARGS "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN} )
    # -------------------------------------------------------------------------------------------------
    # Add Static Library (Core)
    # -------------------------------------------------------------------------------------------------
    add_library(libcore STATIC IMPORTED)
    set_target_properties(libcore PROPERTIES
        IMPORTED_LOCATION ${CMAKE_BINARY_DIR}/source/core/libcore.a)

    # -------------------------------------------------------------------------------------------------
    # Add Static Library (UIComponents)
    # -------------------------------------------------------------------------------------------------
    add_library(libUIComponents STATIC IMPORTED)
    set_target_properties(libUIComponents PROPERTIES
        IMPORTED_LOCATION ${CMAKE_BINARY_DIR}/source/uiComponents/libUIComponents.a)

    # -------------------------------------------------------------------------------------------------
    # Add Static Library (UIScreens)
    # -------------------------------------------------------------------------------------------------
    add_library(libUIScreens STATIC IMPORTED)
    set_target_properties(libUIScreens PROPERTIES
        IMPORTED_LOCATION ${CMAKE_BINARY_DIR}/source/uiScreens/libUIScreens.a)

    # -------------------------------------------------------------------------------------------------
    # Add Static Library (Interfaces)
    # -------------------------------------------------------------------------------------------------
    add_library(libinterfaces STATIC IMPORTED)
    set_target_properties(libinterfaces PROPERTIES
        IMPORTED_LOCATION ${CMAKE_BINARY_DIR}/source/interfaces/libinterfaces.a)

    # -------------------------------------------------------------------------------------------------
    # Add Static Library (Glue)
    # -------------------------------------------------------------------------------------------------
    add_library(libglue STATIC IMPORTED)
    set_target_properties(libglue PROPERTIES
        IMPORTED_LOCATION ${CMAKE_BINARY_DIR}/source/glue/libglue.a)

    # -------------------------------------------------------------------------------------------------
    # Add Static Library (KYCEngine)
    # -------------------------------------------------------------------------------------------------
    #    add_library(libKYCEngine STATIC IMPORTED)
    #    set_target_properties(libKYCEngine PROPERTIES
    #        IMPORTED_LOCATION ${TC_ARTIFACTS_SEARCH_DIR}/lib/libKYCEngine.a)


    # -------------------------------------------------------------------------------------------------
    # Link Qt Libraries to TARGET
    # -------------------------------------------------------------------------------------------------
    target_link_libraries(
        ${ARGN} PUBLIC
            libcore
            libUIComponents
            libUIScreens
            libinterfaces
            libglue
        #            libKYCEngine
        )
endfunction()
