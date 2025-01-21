set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/program2/include)
set(MY_LIB ${CMAKE_SOURCE_DIR}/library)

add_executable(program2 main.cpp ${MY_INCLUDE_DIR}/prog2.h prog2.cpp)

target_link_libraries(program2 library)

target_include_directories(program2 PRIVATE ${MY_LIB}/include)

target_include_directories(program2 PUBLIC ${MY_INCLUDE_DIR})