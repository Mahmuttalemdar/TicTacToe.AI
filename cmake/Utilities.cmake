set_property(GLOBAL PROPERTY GLOBAL_QML_DIR)
function(add_qml_dir)
    get_property(tmp GLOBAL PROPERTY GLOBAL_QML_DIR)
    foreach(arg ${ARGV})
        set(tmp "${tmp};${arg}")
    endforeach()
    set_property(GLOBAL PROPERTY GLOBAL_QML_DIR "${tmp}")
endfunction(add_qml_dir)


