FUNCTION(ENABLE_DOXYGEN)
    IF(ENABLE_DOXYGEN)
        SET(DOXYGEN_CALLER_GRAPH YES)
        SET(DOXYGEN_CALL_GRAPH YES)
        SET(DOXYGEN_EXTRACT_ALL YES)
        FIND_PACKAGE(Doxygen REQUIRED dot)
        DOXYGEN_ADD_DOCS(doxygen-docs ${PROJECT_SOURCE_DIR})

    ENDIF()
ENDFUNCTION()
