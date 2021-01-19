# -------------------------------------------------------------------------------------------------
# Developer Mode
# -------------------------------------------------------------------------------------------------
function(deploy_project)
    set(options)
    set(oneValueArgs TARGET)
    set(multiValueArgs QMLDIRS EXCLUDED_FOLDERS IGNORE_ITEMS CONFIGURATION)

    cmake_parse_arguments(ARGS "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    set(Qt5_PREFIX_PATH "${Qt5_DIR}/../../../")

    if(APPLE AND UNIX)
        find_program (QT5_MACDEPLOYQT_EXECUTABLE macdeployqt HINTS "${Qt5_PREFIX_PATH}/bin")
        set(BUNDLE_PATH "${CMAKE_BINARY_DIR}/src/app/${PROJECT_NAME}.app")
        message(STATUS "Deployment Mode: ${DEPLOYMENT_MODE}, checking platform for macdeployqt: ${QT5_MACDEPLOYQT_EXECUTABLE}")

        if(QT5_MACDEPLOYQT_EXECUTABLE AND DEPLOYMENT_MODE)
            message(STATUS "Deployment Mode: ${DEPLOYMENT_MODE}, deployment tool will run after building...")

            set(QT5_DEPLOY_FLAGS "")

            # list(APPEND QT5_DEPLOY_FLAGS -dmg)
            foreach (ARGS_QMLDIR ${ARGS_QMLDIRS})
                list(APPEND QT5_DEPLOY_FLAGS "-qmldir=${ARGS_QMLDIR}")
            endforeach()

            list(APPEND QT5_DEPLOY_FLAGS -libpath=${Qt5_PREFIX_PATH}/lib)
            list(APPEND QT5_DEPLOY_FLAGS -libpath=${BUNDLE_PATH})

            add_custom_command(
                OUTPUT
                deployment_output
                COMMAND "${QT5_MACDEPLOYQT_EXECUTABLE}"
                # "${CMAKE_BINARY_DIR}/src/app/${PROJECT_NAME}.app"
                "$<TARGET_FILE_DIR:${ARGS_TARGET}>/../../"
                ${QT5_DEPLOY_FLAGS}
                -always-overwrite
                COMMENT "Deploying Qt on Mac OSX platform..."
                )

            add_custom_target(
                deployment_target_${${CMAKE_BUILD_TYPE}}_${ARGS_TARGET} ALL DEPENDS deployment_output
                COMMENT "Macdeployqt finished"
                )

        endif(QT5_MACDEPLOYQT_EXECUTABLE AND DEPLOYMENT_MODE)

    elseif(WIN32)
        find_program (QT5_WINDEPLOYQT_EXECUTABLE windeployqt HINTS "${Qt5_PREFIX_PATH}/bin")
        set(EXECUTABLE_PATH "${CMAKE_BINARY_DIR}/src/app/${PROJECT_NAME}.exe")

        if(QT5_WINDEPLOYQT_EXECUTABLE AND DEPLOYMENT_MODE)
            message(STATUS "Deployment Mode: ${DEPLOYMENT_MODE}, deployment tool will run after building...")

            set (BUILD_TYPE_FLAGS "")

            foreach (ARGS_QMLDIR ${ARGS_QMLDIRS})
                list(APPEND BUILD_TYPE_FLAGS "-qmldir=${ARGS_QMLDIR}")
            endforeach()

            list(APPEND BUILD_TYPE_FLAGS --compiler-runtime)

            if(${CMAKE_BUILD_TYPE} MATCHES Debug)
                list(APPEND BUILD_TYPE_FLAGS --debug)
                list(APPEND BUILD_TYPE_FLAGS --pdb)
            else()
                list(APPEND BUILD_TYPE_FLAGS --release)
            endif()

            add_custom_command(
                OUTPUT
                deploy_win_output
                COMMAND "${QT5_WINDEPLOYQT_EXECUTABLE}"
                "$<TARGET_FILE_DIR:${ARGS_TARGET}>"
                ${BUILD_TYPE_FLAGS}
                COMMENT "Deploying Qt on Windows platform..."
                )

            add_custom_target(
                deploy_win_target ALL
                DEPENDS
                deploy_win_output
                COMMENT "Windeployqt finished"
                )
        endif(QT5_WINDEPLOYQT_EXECUTABLE AND DEPLOYMENT_MODE)

    endif(APPLE AND UNIX)
endfunction()
