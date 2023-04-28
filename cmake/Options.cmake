IF(NOT MSVC)
    OPTION(ENABLE_BUILD_WITH_TIME_TRACE "Enable -ftime-trace to generate time tracing .json files on clang" OFF)
ENDIF()

OPTION(BUILD_SHARED_LIBS "Enable compilation of shared libraries" OFF)
OPTION(ENABLE_TESTING "Enable Test Builds" ON)

# Very basic PCH example
OPTION(ENABLE_PCH "Enable Precompiled Headers" OFF)

option(ENABLE_CPPCHECK "Enable static analysis with cppcheck" OFF)
option(ENABLE_CLANG_TIDY "Enable static analysis with clang-tidy" OFF)
option(ENABLE_INCLUDE_WHAT_YOU_USE "Enable static analysis with include-what-you-use" OFF)

OPTION(ENABLE_CACHE "Enable cache if available" ON)
option(ENABLE_DOXYGEN "Enable doxygen doc builds of source" OFF)

# Sanitizers
OPTION(ENABLE_SANITIZER_UNDEFINED_BEHAVIOR "Enable undefined behavior sanitizer" FALSE)
OPTION(ENABLE_SANITIZER_THREAD "Enable thread sanitizer" FALSE)
OPTION(ENABLE_SANITIZER_MEMORY "Enable memory sanitizer" FALSE)
OPTION(ENABLE_SANITIZER_ADDRESS "Enable address sanitizer" FALSE)
OPTION(ENABLE_SANITIZER_LEAK "Enable leak sanitizer" FALSE)

OPTION(ENABLE_COVERAGE "Enable coverage reporting for gcc/clang" FALSE)

OPTION(ENABLE_IPO "Enable Interprocedural Optimization, aka Link Time Optimization (LTO)" OFF)
