cmake_minimum_required (VERSION 3.22)

project ("lts")

option(LTS_RUN_TESTS "Run tests" ON)
option(LTS_UNITY "Use unity/jumbo build mode" ON)

set(CMAKE_VS_JUST_MY_CODE_DEBUGGING YES)

# Library
add_subdirectory(src)

# Tests
if ((CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME) AND LTS_RUN_TESTS)
    include(CTest)
    enable_testing()
    include(GoogleTest)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    add_subdirectory(tests)
endif()