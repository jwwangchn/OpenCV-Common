cmake_minimum_required(VERSION 2.8)
project(DisplayImage)
find_package(OpenCV 2 REQUIRED)
add_executable(DisplayImage DisplayImage.cpp)
target_link_libraries(DisplayImage ${OpenCV_LIBS})
