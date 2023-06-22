cmake_minimum_required (VERSION 3.22)

set(LTS_SOURCES "lts/lts.h" "lts/state.h" "lts/transition.h" 

"lts/parsers/parsers.h" "lts/parsers/state.cpp" "lts/parsers/state.cpp" "lts/parsers/transition.h" "lts/parsers/transition.cpp"

"lts/writers/writers.h" "lts/writers/export.h" "lts/writers/generic.h" "lts/writers/ostream.h" "lts/writers/ofstream.h"
"lts/writers/styling.h"

"lts/internal/directory.h" "lts/internal/directory.cpp" "lts/internal/strings.h" "lts/internal/strings.cpp"
)

add_library(lts STATIC ${LTS_SOURCES})

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET lts PROPERTY CXX_STANDARD 20)
endif()

target_include_directories(lts 
	PUBLIC
		${PROJECT_SOURCE_DIR}/src
)

add_subdirectory("${PROJECT_SOURCE_DIR}/external/nlohmann-json" "external/nlohmann-json")

target_link_libraries(lts 
    PUBLIC 
        nlohmann_json
)