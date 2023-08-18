# PT100 & PT1000 compile time calculator


## Build Status

[![CMake](https://github.com/StephanKa/PT100-P1000-Calculator/actions/workflows/build_cmake.yml/badge.svg?branch=main)](https://github.com/StephanKa/PT100-P1000-Calculator/actions/workflows/build_cmake.yml)

## Getting Started

## Build Instructions

All defined presets have the following scheme:

| Preset stage  | scheme                    | description                                                              |
|---------------|---------------------------|--------------------------------------------------------------------------|
| build         | **build-**\<PRESET_NAME\> | This stage is used for compiling the project                             |
| configuration | \<PRESET_NAME\>           | This stage is used for configure the project with defined compiler setup |
| test          | **test-**\<PRESET_NAME\>  | This stage is used to run all test registered for ctest                  |

### Configure your build

To configure the project and write makefiles, you could use `cmake` with a bunch of command line options.
The easier option is to run cmake interactively:

#### **Configure via cmake preset**:

Check the preset which can be applied to your build system by typing:

    cmake --list-presets

The output looks like this:

    Available configure presets:

    "unixlike-gcc-10-debug"       - GCC 10 Debug
    "unixlike-gcc-10-release"     - GCC 10 Release
    "unixlike-gcc-11-debug"       - GCC 11 Debug
    "unixlike-gcc-11-release"     - GCC 11 Release
    "unixlike-gcc-12-debug"       - GCC 12 Debug
    "unixlike-gcc-12-release"     - GCC 12 Release
    "unixlike-clang-12-debug"     - Clang 12 Debug
    "unixlike-clang-12-release"   - Clang 12 Release
    "unixlike-clang-13-debug"     - Clang 13 Debug
    "unixlike-clang-13-release"   - Clang 13 Release
    "unixlike-clang-14-debug"     - Clang 14 Debug
    "unixlike-clang-14-release"   - Clang 14 Release
    "unixlike-clang-15-debug"     - Clang 15 Debug
    "unixlike-clang-15-release"   - Clang 15 Release

Choose a configuration which is suitable and use following command for example.

    cmake --preset unixlike-clang-15-debug

### Build
Once you have selected all the options you would like to use, you can build the
project (all targets):

    cmake --preset <PRESET_NAME>

For example:
    
    cmake --preset build-unixlike-clang-15-debug

### Test
Run all test using preset and ctest:

    cmake --preset <PRESET_NAME>

For example:

    cmake --preset test-unixlike-clang-15-debug

## Testing

- See [Catch2 tutorial](https://github.com/catchorg/Catch2/blob/master/docs/tutorial.md)

## Compiler Explorer

[Clang 16.0.0](https://godbolt.org/z/5ToE67of6)
