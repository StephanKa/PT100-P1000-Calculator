INCLUDE(CTest)
INCLUDE(Catch)

ADD_LIBRARY(catch_main STATIC catch_main.cpp)
TARGET_LINK_LIBRARIES(catch_main PUBLIC CONAN_PKG::catch2)
TARGET_LINK_LIBRARIES(catch_main PRIVATE project_options)

# Add a file containing a set of constexpr tests
ADD_EXECUTABLE(catch_constexpr_tests constexpr_tests.cpp)
TARGET_INCLUDE_DIRECTORIES(catch_constexpr_tests PUBLIC ${CMAKE_SOURCE_DIR}/include)
TARGET_LINK_LIBRARIES(catch_constexpr_tests PRIVATE project_options project_warnings catch_main)

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
