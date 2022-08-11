cmake_minimum_required(VERSION 3.3 FATAL_ERROR)

project(util VERSION 0.0.1)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/scripts)

include(CMakeUtils)

set_cxx_standard(11)
set_default_build_type(Release)

if(ENABLE_TESTS)
  enable_testing()
  enable_test_coverage()
  add_subdirectory(test)
endif()

add_subdirectory(src)
