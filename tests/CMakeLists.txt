cmake_minimum_required (VERSION 3.22)

# Dependencies
add_subdirectory("${PROJECT_SOURCE_DIR}/external/googletest" "external/googletest")

# Macro
macro(package_add_test TESTNAME)
    add_executable(${TESTNAME} ${ARGN})

    target_compile_features(${TESTNAME}  PRIVATE cxx_std_20)
    target_link_libraries(${TESTNAME} 
    PRIVATE 
        lts
        gtest
        gmock
        gtest_main)

    gtest_discover_tests(${TESTNAME}
        WORKING_DIRECTORY ${PROJECT_DIR}
        PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${PROJECT_DIR}"
    )
    set_target_properties(${TESTNAME} PROPERTIES 
        FOLDER tests
        RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin/tests")
endmacro()

# Test Suite
package_add_test("lts-base" "lts/lts.cpp")
package_add_test("lts-parsers" "lts/parsers.cpp")
package_add_test("lts-export" "lts/export.cpp")