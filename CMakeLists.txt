cmake_minimum_required(VERSION 3.15)
project(rtsp_test)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(src)
add_executable(rtsp_test main.cpp)
target_link_libraries(rtsp_test PRIVATE rtsp_lib ws2_32)