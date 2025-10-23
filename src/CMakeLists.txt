set(LIBRARY_NAME json)

# set(JSON_SOURCES
# )

set(JSON_HEADERS
json.h
nlohmann.h
factory.h
)

add_subdirectory(third-party/json)

add_library(${LIBRARY_NAME} INTERFACE)

# Link nlohmann-json to your wrapper
target_link_libraries(${LIBRARY_NAME}
    INTERFACE nlohmann_json::nlohmann_json
)

# Export header include path so other projects can do #include "json.h"
target_include_directories(${LIBRARY_NAME}
    INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}
)

# Optional: Register header files so they appear in IDEs/Eclipse/Clion
list(TRANSFORM JSON_HEADERS PREPEND "${CMAKE_CURRENT_SOURCE_DIR}/")
target_sources(${LIBRARY_NAME} INTERFACE ${JSON_HEADERS})

# Create nice namespace target
add_library(${LIB_ALIAS} ALIAS ${LIBRARY_NAME})