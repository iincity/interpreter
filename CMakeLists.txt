cmake_minimum_required(VERSION 2.8.9)

include_directories(include include/collections)

file(GLOB SOURCES "src/*.c")

add_executable(tokens_demo.out tokens_demo.c ${SOURCES})
target_link_libraries(tokens_demo.out m )
SET(CMAKE_C_FLAGS "-std=c11")
#
add_executable(tree_demo.out tree_demo.c ${SOURCES})
target_link_libraries(tree_demo.out m)
SET(CMAKE_C_FLAGS "-std=c11")
#
add_executable(mylua.out mylua.c ${SOURCES})

target_link_libraries(mylua.out m)
SET(CMAKE_C_FLAGS "-std=c11")