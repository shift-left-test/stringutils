build_test_program(
  NAME unittest
  SUFFIX .bin
  SRCS StringTest.cpp
  PRIVATE_HEADERS ${CMAKE_SOURCE_DIR}/include
)
