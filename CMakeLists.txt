cmake_minimum_required(VERSION 3.22)
project(ki_rwu_c C)
enable_testing()

set(CMAKE_C_STANDARD 23)

add_library(ki_rwu_c
        include/lib_ki_rwu_c.h
        src/search/node.h
        src/search/node.c
        src/search/uninformed/uninformed_search.h
        src/search/uninformed/uninformed_search.c)


# Testing
## Node testing
add_executable(ki_rwu_c_node_tests
        test/search/node_test.c)
target_link_libraries(ki_rwu_c_node_tests ki_rwu_c)
add_test(NAME ki_rwu_c_node_tests COMMAND ki_rwu_c_node_tests)

## Eight-puzzle node testing
add_executable(ki_rwu_c_eightpuzzle_tests
        test/search/eightpuzzle/eightpuzzle_test.c
        test/search/eightpuzzle/example_eightpuzzle.h
        test/search/eightpuzzle/example_eightpuzzle.c
        test/search/eightpuzzle/dyn_2d_int_array.h
        test/search/eightpuzzle/dyn_2d_int_array.c)
target_link_libraries(ki_rwu_c_eightpuzzle_tests ki_rwu_c)
add_test(NAME ki_rwu_c_eightpuzzle_tests COMMAND ki_rwu_c_eightpuzzle_tests)

## Uninformed search testing
add_executable(ki_rwu_c_usearch_tests
        test/search/uninformed/breadth_first_search_test.c)
target_link_libraries(ki_rwu_c_usearch_tests ki_rwu_c)
add_test(NAME ki_rwu_c_usearch_tests COMMAND ki_rwu_c_usearch_tests)
