# -------------------------------------------------------------------------------------------------
# Deploy project if DEVELOYMENT_MODE = ON
# -------------------------------------------------------------------------------------------------
if(DEPLOYMENT_MODE)
    get_property(QMLDIRS GLOBAL PROPERTY GLOBAL_QML_DIR)
    deploy_project(TARGET ${PROJECT_NAME} QMLDIRS ${QMLDIRS} EXCLUDED_FOLDERS ${EXCLUDED_FOLDERS})
endif()



