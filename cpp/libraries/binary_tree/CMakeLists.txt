cmake_minimum_required (VERSION 2.6)
project (BinaryTreeLibrary)
################################################################################
# GTest - http://code.google.com/p/googletest/
################################################################################
if (MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /bigobj")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
endif()
add_subdirectory("../../../gtest-1.7.0" "${CMAK_CURRENT_BINARY_DIR}/LIBS/gtest-1.7.0")
enable_testing(true)

################################################################################
# FastArray (header file only library)
################################################################################
include_directories(src ${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
add_executable(unit-tests unit_tests.cpp binary_tree.cpp binary_tree_node.cpp)
target_link_libraries(unit-tests ws2_32 gtest gtest_main)
add_test(unit-tests unit-tests)

