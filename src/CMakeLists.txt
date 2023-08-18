SET(NAME PT100_P1000_Calculator)

# Generic test that uses conan libs
ADD_EXECUTABLE(${NAME} main.cpp)
TARGET_LINK_LIBRARIES(
        ${NAME}
        PRIVATE project_options
        project_warnings
        fmt::fmt)

TARGET_INCLUDE_DIRECTORIES(${NAME} PRIVATE ${CMAKE_BINARY_DIR}/generated ../include)
