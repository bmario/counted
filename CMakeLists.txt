project(counted)

include(ctest)

cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x -stdlib=libc++")

include_directories(include)

add_executable(const_test const_test.cpp)
add_executable(non_const_test non_const_test.cpp)
add_executable(array_test array_test.cpp)

add_test(const_test const_test)
add_test(non_const_test non_const_test)
add_test(array_test array_test)

SET(COUNTED_HEADERS include/counted/counted.hpp include/counted/counted_view.hpp)
install(FILES ${COUNTED_HEADERS} DESTINATION include/counted)