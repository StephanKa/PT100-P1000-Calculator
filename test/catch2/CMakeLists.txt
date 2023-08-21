INCLUDE(CTest)
INCLUDE(Catch)

# Add a file containing a set of constexpr tests
ADD_EXECUTABLE(catch_constexpr_tests constexpr_tests.cpp)
TARGET_INCLUDE_DIRECTORIES(catch_constexpr_tests PUBLIC ${CMAKE_SOURCE_DIR}/include)
TARGET_LINK_LIBRARIES(catch_constexpr_tests PRIVATE project_options project_warnings Catch2::Catch2WithMain)

CATCH_DISCOVER_TESTS(
        catch_constexpr_tests
        TEST_PREFIX
        "catch_constexpr."
        REPORTER
        JUnit
        OUTPUT_DIR
        .
        OUTPUT_PREFIX
        "catch_constexpr."
        OUTPUT_SUFFIX
        .xml)

ADD_CUSTOM_COMMAND(TARGET catch_constexpr_tests POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:catch_constexpr_tests> ${CMAKE_BINARY_DIR}/install/bin/$<TARGET_FILE_NAME:catch_constexpr_tests>)
