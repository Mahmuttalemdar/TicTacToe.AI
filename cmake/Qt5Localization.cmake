#include("${CMAKE_SOURCE_DIR}/CMake/Toolchain/KsQt5LinguistToolsMacros.cmake")

find_package(Qt5LinguistTools)
if(NOT ${Qt5LinguistTools_FOUND})
    message(WARNING "?-- Cannot find Qt5 linguist tools: translation will not be available.")
    return()
endif()

find_program(Qt5_LCONVERT_EXECUTABLE lconvert
    PATHS ${Qt5LinguistTools_DIR}/../../../bin
    NO_DEFAULT_PATH
    )

function(KS_GENERATE_TSFILES target)
    set(options)
    set(oneValueArgs TARGET_DIRECTORY JSON_SOURCE)
    set(multiValueArgs LANGUAGES)

    cmake_parse_arguments(PARAM "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    set(TRANSLATION_FILES "")
    foreach(language ${PARAM_LANGUAGES})
        list(APPEND TRANSLATION_FILES
            "${PARAM_TARGET_DIRECTORY}/${language}.ts"
            )
    endforeach()

    if(KS_L10N_UPDATE_TRANSLATIONS AND APPLE)

        find_package (Python3 COMPONENTS Interpreter)
        find_package(PythonInterp REQUIRED)

        set(
            PYTHON_ARGUMENTS
            ${CMAKE_SOURCE_DIR}/src/ksecointerface/scripts/translationgenerator.py
            --trfilesdir ${PARAM_JSON_SOURCE}
            --tsfilesdir ${PARAM_TARGET_DIRECTORY}
            )

        message(STATUS "PYTHON_ARGUMENTS: ${PYTHON_ARGUMENTS}")

        add_custom_command(
            OUTPUT
            ${TRANSLATION_FILES}
            COMMAND
            ${Python3_EXECUTABLE} ${PYTHON_ARGUMENTS}
            DEPENDS
            ${CMAKE_SOURCE_DIR}/src/ksecointerface/scripts/translationgenerator.py
            WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
            COMMENT
            "PRE BUILD: Generatin translation files..."
            )

    endif()

    set(QM_FILES "")

    ks_add_translation(QM_FILES
        ${TRANSLATION_FILES}
        )

    add_custom_target(${target}_translations DEPENDS ${QM_FILES})
    add_dependencies(${target} ${target}_translations)

    set(L10N_RESOURCE_CONTENT
        "<!DOCTYPE RCC>\n <RCC version=\"1.0\">\n     <qresource prefix=\"/l10n/\">\n"
        )
    foreach(qm_file ${QM_FILES})
        get_filename_component(base_filename ${qm_file} NAME)
        string(APPEND L10N_RESOURCE_CONTENT
            "        <file alias=\"${base_filename}\">${qm_file}</file>\n"
            )
    endforeach()

    string(APPEND L10N_RESOURCE_CONTENT
        "    </qresource>\n"
        "</RCC>\n"
        )

    file(WRITE "${CMAKE_CURRENT_BINARY_DIR}/l10n.qrc" ${L10N_RESOURCE_CONTENT})
    set(RESOURCES_FILES
        "${CMAKE_CURRENT_BINARY_DIR}/l10n.qrc"
        )
    qt5_add_resources (RCC_SOURCES ${RESOURCES_FILES})
    target_sources(
        ${target} PRIVATE ${RCC_SOURCES}
        )

endfunction(KS_GENERATE_TSFILES target)
