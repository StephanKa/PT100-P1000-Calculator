SET(NAME PT100_P1000_Calculator)

# Generic test that uses conan libs
ADD_EXECUTABLE(${NAME} main.cpp)
TARGET_LINK_LIBRARIES(
        ${NAME}
        PRIVATE project_options
        project_warnings
        fmt::fmt)

TARGET_INCLUDE_DIRECTORIES(${NAME} PRIVATE ${CMAKE_BINARY_DIR}/generated ../include)

ADD_CUSTOM_COMMAND(TARGET ${NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${NAME}> ${CMAKE_BINARY_DIR}/install/bin/$<TARGET_FILE_NAME:${NAME}>)

ADD_CUSTOM_COMMAND(TARGET ${NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/include/PTCalculator.h ${CMAKE_BINARY_DIR}/install/include/PTCalculator.h)
