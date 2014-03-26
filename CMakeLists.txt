project(counted)

include(CTest)

cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

include_directories(include)

add_executable(const_test const_test.cpp)
add_executable(non_const_test non_const_test.cpp)
add_executable(array_test array_test.cpp)
add_executable(temporary_test temporary_test.cpp)
add_executable(temporary_test2 temporary_test2.cpp)


# set additional flags for debug build
SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -Wall -pedantic")

add_test(const_test const_test)
add_test(non_const_test non_const_test)
add_test(array_test array_test)
add_test(temporary_test temporary_test)
add_test(temporary_test2 temporary_test2)

SET(COUNTED_HEADERS include/counted/counted.hpp include/counted/counted_view.hpp)
install(FILES ${COUNTED_HEADERS} DESTINATION include/counted)