# ######################################################################################################################
# Installation instructions

include(GNUInstallDirs)
set(INSTALL_CONFIGDIR ${CMAKE_INSTALL_LIBDIR}/cmake/TicTacToe.AI)

# Install binary
install(TARGETS TicTacToe.AI
        EXPORT TicTacToe.AI-targets
        BUNDLE DESTINATION ${CMAKE_INSTALL_BINDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

# Install desktop files, completion and dbus files
configure_file(${CMAKE_SOURCE_DIR}/res/desktopEntry/package/org.alemdarCorp.TicTacToe.AI.desktop
               ${CMAKE_CURRENT_BINARY_DIR}/share/applications/org.alemdarCorp.TicTacToe.AI.desktop COPYONLY)

# Install Icons
configure_file(${CMAKE_SOURCE_DIR}/res/img/hicolor/48x48/apps/tictactoe.png
               ${CMAKE_CURRENT_BINARY_DIR}/share/icons/hicolor/48x48/apps/tictactoe.png COPYONLY)

configure_file(${CMAKE_SOURCE_DIR}/res/img/hicolor/128x128/apps/tictactoe.png
               ${CMAKE_CURRENT_BINARY_DIR}/share/icons/hicolor/128x128/apps/tictactoe.png COPYONLY)

configure_file(${CMAKE_SOURCE_DIR}/res/img/hicolor/scalable/apps/tictactoe.svg
               ${CMAKE_CURRENT_BINARY_DIR}/share/icons/hicolor/scalable/apps/tictactoe.svg COPYONLY)

# Install assets
install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/share/ DESTINATION ${CMAKE_INSTALL_DATAROOTDIR})

# Install Translations
# install(FILES ${QM_FILES} DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/tictactoe/translations)

# windeployqt
if(WIN32)
  if(EXISTS $ENV{QTDIR}/bin/windeployqt.exe)
    if(CMAKE_BUILD_TYPE MATCHES Release)
      set(BINARIES_TYPE --release)
    else()
      set(BINARIES_TYPE --debug)
    endif()

    add_custom_command(
      TARGET TicTacToe.AI
      POST_BUILD
      COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_BINARY_DIR}/windeployqt_stuff
      COMMAND
        $ENV{QTDIR}/bin/windeployqt.exe ${BINARIES_TYPE} --no-translations --compiler-runtime --no-system-d3d-compiler
        --no-angle --no-webkit2 --no-quick-import --dir ${CMAKE_BINARY_DIR}/windeployqt_stuff $<TARGET_FILE:TicTacToe.AI>
      # copy translations manually QM_FILES
      # COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}/windeployqt_stuff/translations
      # COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_BINARY_DIR}/src/translations
      #         ${CMAKE_BINARY_DIR}/windeployqt_stuff/translations
      )

    install(DIRECTORY ${CMAKE_BINARY_DIR}/windeployqt_stuff/ DESTINATION bin)
  else()
    message("Unable to find executable QTDIR/bin/windeployqt.")
  endif()
endif()

# macdeployqt
if (APPLE)
    set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")
    execute_process(COMMAND brew --prefix qt5 OUTPUT_VARIABLE QTDIR)
    string(REGEX REPLACE "\n$" "" QTDIR "${QTDIR}")
    set(MAC_DEPLOY_QT ${QTDIR}/bin/macdeployqt)
    if (EXISTS ${MAC_DEPLOY_QT})
        set_source_files_properties(resources/icon.icns PROPERTIES
                MACOSX_PACKAGE_LOCATION Resources)

        set_target_properties(${target} PROPERTIES
                MACOSX_BUNDLE TRUE
                )
    else ()
        message("Unable to find executable ${MAC_DEPLOY_QT}.")
    endif ()
endif ()
