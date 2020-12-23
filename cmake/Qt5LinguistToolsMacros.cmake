include(CMakeParseArguments)
find_package(Qt5LinguistTools)

set(KS_L10N_UPDATE_TRANSLATIONS_TXT "Update source translation l10n/*.ts files")
option(KS_L10N_UPDATE_TRANSLATIONS ${KS_L10N_UPDATE_TRANSLATIONS_TXT} OFF)
add_feature_info(KS_L10N_UPDATE_TRANSLATIONS KS_L10N_UPDATE_TRANSLATIONS ${KS_L10N_UPDATE_TRANSLATIONS_TXT})

set(KS_L10N_INTEGRATE_LOCALIZATION_FILES_TXT "Compile translation files into final application as resource")
option(KS_L10N_INTEGRATE_LOCALIZATION_FILES ${KS_L10N_INTEGRATE_LOCALIZATION_FILES_TXT} ON)
add_feature_info(KS_L10N_INTEGRATE_LOCALIZATION_FILES KS_L10N_INTEGRATE_LOCALIZATION_FILES ${KS_L10N_INTEGRATE_LOCALIZATION_FILES_TXT})


set(KsQt5LinguistToolsMacros_DIR ${CMAKE_CURRENT_SOURCE_DIR})

function(KS_CREATE_TRANSLATION _qm_files)
    set(options)
    set(oneValueArgs)
    set(multiValueArgs OPTIONS)

    cmake_parse_arguments(_LUPDATE "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})
    set(_lupdate_files ${_LUPDATE_UNPARSED_ARGUMENTS})
    set(_lupdate_options ${_LUPDATE_OPTIONS})

    set(_my_sources)
    set(_my_tsfiles)
    foreach(_file ${_lupdate_files})
        get_filename_component(_ext ${_file} EXT)
        get_filename_component(_abs_FILE ${_file} ABSOLUTE)
        if(_ext MATCHES "ts")
            list(APPEND _my_tsfiles ${_abs_FILE})
        else()
            list(APPEND _my_sources ${_abs_FILE})
        endif()
    endforeach()

    foreach(_ts_file ${_my_tsfiles})
        if(_my_sources)
          # make a list file to call lupdate on, so we don't make our commands too
          # long for some systems
          get_filename_component(_ts_name ${_ts_file} NAME_WE)
          set(_ts_lst_file "${CMAKE_CURRENT_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/${_ts_name}_lst_file")
          set(_lst_file_srcs)
          foreach(_lst_file_src ${_my_sources})
              set(_lst_file_srcs "${_lst_file_src}\n${_lst_file_srcs}")
          endforeach()

          get_directory_property(_inc_DIRS INCLUDE_DIRECTORIES)
          foreach(_pro_include ${_inc_DIRS})
              get_filename_component(_abs_include "${_pro_include}" ABSOLUTE)
              set(_lst_file_srcs "-I${_pro_include}\n${_lst_file_srcs}")
          endforeach()

          file(WRITE ${_ts_lst_file} "${_lst_file_srcs}")
        endif()
        add_custom_command(OUTPUT ${_ts_file}
            COMMAND ${Qt5_LUPDATE_EXECUTABLE}
            ARGS ${_lupdate_options} "@${_ts_lst_file}" -ts ${_ts_file}
            DEPENDS ${_my_sources} ${_ts_lst_file} VERBATIM)
    endforeach()
    ks_add_translation(${_qm_files} ${_my_tsfiles})
    set(${_qm_files} ${${_qm_files}} PARENT_SCOPE)
endfunction()


function(KS_ADD_TRANSLATION _qm_files)

    message(STATUS "added ts files: ${ARGN}")

    foreach(_current_FILE ${ARGN})
        get_filename_component(_abs_FILE ${_current_FILE} ABSOLUTE)
        get_filename_component(qm ${_abs_FILE} NAME)
        # everything before the last dot has to be considered the file name (including other dots)
        string(REGEX REPLACE "\\.[^.]*$" "" FILE_NAME ${qm})
        get_source_file_property(output_location ${_abs_FILE} OUTPUT_LOCATION)
        if(output_location)
            file(MAKE_DIRECTORY "${output_location}")
            set(qm "${output_location}/${FILE_NAME}.qm")
        else()
            set(qm "${CMAKE_CURRENT_BINARY_DIR}/${FILE_NAME}.qm")
        endif()

        add_custom_command(OUTPUT ${qm}
            COMMAND ${Qt5_LRELEASE_EXECUTABLE}
            ARGS -idbased ${_abs_FILE} -qm ${qm}
            DEPENDS ${_abs_FILE} VERBATIM
        )
        list(APPEND ${_qm_files} ${qm})
    endforeach()
    set(${_qm_files} ${${_qm_files}} PARENT_SCOPE)
endfunction()


function(ks_update_localization target)
    set(options)
    set(oneValueArgs TARGET_DIRECTORY)
    set(multiValueArgs SOURCES LANGUAGES)
    cmake_parse_arguments(PARAM "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    set(TRANSLATION_FILES "")
    foreach(language ${PARAM_LANGUAGES})
        list(APPEND TRANSLATION_FILES
                "${PARAM_TARGET_DIRECTORY}/${language}.ts"
            )
    endforeach()

    set(QM_FILES "")

    if (KS_L10N_UPDATE_TRANSLATIONS)
        ks_create_translation(QM_FILES
                ${PARAM_SOURCES}
                ${TRANSLATION_FILES}
            )
    else()
        ks_add_translation(QM_FILES
                ${TRANSLATION_FILES}
            )
    endif()

    add_custom_target(${target}_translations DEPENDS ${QM_FILES})
    add_dependencies(${target} ${target}_translations)

    if (KS_L10N_INTEGRATE_LOCALIZATION_FILES)
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
    else()
        set_property(TARGET ${target} APPEND PROPERTY QM_FILES ${QM_FILES})
    endif()
endfunction()

