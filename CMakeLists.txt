cmake_minimum_required(VERSION 3.5.1 FATAL_ERROR)

project(util VERSION 0.0.1)

include(CMakeUtils)

set_cxx_standard(11)
set_default_build_type(Release)

enable_static_analysis()

if(ENABLE_TESTS)
  enable_testing()
  enable_test_coverage()
  add_subdirectory(test)
endif()

add_subdirectory(src)
