set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/program1/include)
set(MY_LIB ${CMAKE_SOURCE_DIR}/library)

add_executable(program1 main.cpp ${MY_INCLUDE_DIR}/prog1.h prog1.cpp)

target_link_libraries(program1 library)

target_include_directories(program1 PRIVATE ${MY_LIB}/include)

target_include_directories(program1 PUBLIC ${MY_INCLUDE_DIR})