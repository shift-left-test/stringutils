build_test_program(
  NAME unittest
  SUFFIX .bin
  SRCS SampleTest.cpp
  PRIVATE_HEADERS ${CMAKE_SOURCE_DIR}/include
)
