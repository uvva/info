add_library(library SHARED src/function.cpp)

target_include_directories(library PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

set_target_properties(library PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/library)