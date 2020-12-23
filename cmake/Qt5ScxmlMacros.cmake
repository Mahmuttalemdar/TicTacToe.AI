include(CMakeParseArguments)

function(ks_add_statecharts)
    set(options)
    set(oneValueArgs TARGET)
    set(multiValueArgs OPTIONS SCXML_FILES)

    if(NOT Qt5Scxml_QSCXMLC_EXECUTABLE)
        message(FATAL_ERROR "qscxmlc executable not found -- Check installation.")
    endif()

    cmake_parse_arguments(ARGS "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})
    include_directories("${CMAKE_CURRENT_BINARY_DIR}")

    set(scxml_files ${ARGS_SCXML_FILES})

    foreach(file ${scxml_files})
        get_filename_component(outfilename ${file} NAME_WE)
        get_filename_component(directory ${file} DIRECTORY)
        get_filename_component(infile ${file} ABSOLUTE BASE_DIR ${CMAKE_CURRENT_LIST_DIR})
        set(include "include/statechart")

        file(MAKE_DIRECTORY "${CMAKE_BINARY_DIR}/${include}")
        set(outfile ${CMAKE_BINARY_DIR}/${include}/${outfilename})
        set(outfile_cpp ${CMAKE_BINARY_DIR}/${include}/${outfilename}.cpp)
        set(outfile_h ${CMAKE_BINARY_DIR}/${include}/${outfilename}.h)

        add_custom_command(OUTPUT ${outfile_cpp} ${outfile_h}
                           COMMAND ${Qt5Scxml_QSCXMLC_EXECUTABLE}
                           ARGS ${ARGS_OPTIONS} --output ${outfile} ${infile}
                           MAIN_DEPENDENCY ${infile}
                           VERBATIM)

        set_property(SOURCE ${outfile_cpp} ${outfile_h} PROPERTY SKIP_AUTOGEN ON)
        set_property(SOURCE ${outfile_cpp} PROPERTY GENERATED ON)
        target_sources(${ARGS_TARGET} PRIVATE ${outfile_cpp} ${outfile_h})
        target_sources(${ARGS_TARGET} PRIVATE ${infile})
    endforeach()
endfunction()
