cmake_minimum_required(VERSION 3.8.0)
set(CMAKE_CXX_STANDARD 11)
project(bsdiff)
add_definitions(-DBSDIFF_EXECUTABLE -DBSPATCH_EXECUTABLE)
add_executable(bsdiff bsdiff.cpp)
add_executable(bspatch bspatch.cpp)
find_library(bzip2 bz2)
target_link_libraries(bsdiff ${bzip2})
target_link_libraries(bspatch ${bzip2})
