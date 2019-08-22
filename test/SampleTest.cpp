#include <gtest/gtest.h>
#include "snap/SampleHeader.hpp"

TEST(SampleTest, testEcho) {
  EXPECT_EQ("test", snap::echo("test"));
}
