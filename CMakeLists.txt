cmake_minimum_required(VERSION 3.5.1 FATAL_ERROR)

project(snap VERSION 0.0.1)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/scripts")
include(CMakeUtils)

set_cxx_standard(11)

enable_testing()
enable_test_coverage()
add_all_subdirectories()
enable_static_analysis(ALL)
