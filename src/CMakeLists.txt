cmake_minimum_required (VERSION 3.22)

set(LTS_SOURCES "lts/lts.h" "lts/state.h" "lts/transition.h" 

"lts/parsers/parsers.h" "lts/parsers/state.cpp" "lts/parsers/state.cpp" "lts/parsers/transition.h" "lts/parsers/transition.cpp"

"lts/writers/writers.h" "lts/writers/export.h" "lts/writers/ostream.h" "lts/writers/ofstream.h"
"lts/writers/styling.h"

"lts/internal/directory.h" "lts/internal/directory.cpp" "lts/internal/strings.h" "lts/internal/strings.cpp"
)

add_library(lts STATIC ${LTS_SOURCES})

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET lts PROPERTY CXX_STANDARD 20)
endif()

if (LTS_UNITY)
    set_target_properties(lts PROPERTIES UNITY_BUILD ON)
endif()

target_include_directories(lts 
	PUBLIC
		${PROJECT_SOURCE_DIR}/src
)

# Ankerl Unordered Dense
add_subdirectory("${PROJECT_SOURCE_DIR}/external/unordered_dense" "external/unordered_dense")
# Container Hash
add_subdirectory("${PROJECT_SOURCE_DIR}/external/boost/container_hash" "external/boost/container_hash")
# dependencies of container hash
add_subdirectory("${PROJECT_SOURCE_DIR}/external/boost/config" "external/boost/config")
add_subdirectory("${PROJECT_SOURCE_DIR}/external/boost/describe" "external/boost/describe")
add_subdirectory("${PROJECT_SOURCE_DIR}/external/boost/mp11" "external/boost/mp11")
add_subdirectory("${PROJECT_SOURCE_DIR}/external/boost/type_traits" "external/boost/type_traits")
add_subdirectory("${PROJECT_SOURCE_DIR}/external/boost/static_assert" "external/boost/static_assert")

target_link_libraries(lts 
    INTERFACE
        unordered_dense
		Boost::container_hash
)