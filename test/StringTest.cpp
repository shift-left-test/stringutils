/*
  MIT License

  Copyright (c) 2019 Sung Gon Kim

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.
*/

#include <gtest/gtest.h>
#include <string>
#include "snap/string.hpp"

class StringTest : public ::testing::Test {
 protected:
  constexpr static const char *SOURCE = "hello world";
  constexpr static const char *PREFIX = "hello";
  constexpr static const char *SUFFIX = "world";
  constexpr static const char *EMPTY = "";
  constexpr static const char *UPPERCASE = "HELLO WORLD";
  constexpr static const char *LOWERCASE = "hello world";
};

TEST_F(StringTest, testStartsWithReturnTrueWhenValidInputGiven) {
  EXPECT_TRUE(snap::string::startsWith(SOURCE, SOURCE));
  EXPECT_TRUE(snap::string::startsWith(SOURCE, PREFIX));
  EXPECT_TRUE(snap::string::startsWith(SOURCE, EMPTY));
  EXPECT_TRUE(snap::string::startsWith(EMPTY, EMPTY));
}

TEST_F(StringTest, testStartsWithReturnFalseWhenInvalidInputGiven) {
  EXPECT_FALSE(snap::string::startsWith(SUFFIX, SOURCE));
  EXPECT_FALSE(snap::string::startsWith(SOURCE, SUFFIX));
  EXPECT_FALSE(snap::string::startsWith(EMPTY, SOURCE));
}

TEST_F(StringTest, testEndsWithReturnTrueWhenValidInputGiven) {
  EXPECT_TRUE(snap::string::endsWith(SOURCE, SOURCE));
  EXPECT_TRUE(snap::string::endsWith(SOURCE, SUFFIX));
  EXPECT_TRUE(snap::string::endsWith(SOURCE, EMPTY));
  EXPECT_TRUE(snap::string::endsWith(EMPTY, EMPTY));
}

TEST_F(StringTest, testEndsWithReturnFalseWhenInvalidInputGiven) {
  EXPECT_FALSE(snap::string::endsWith(PREFIX, SOURCE));
  EXPECT_FALSE(snap::string::endsWith(SOURCE, PREFIX));
  EXPECT_FALSE(snap::string::endsWith(EMPTY, SOURCE));
}

TEST_F(StringTest, testUppercaseReturnUppercasedInput) {
  EXPECT_EQ(std::string(UPPERCASE), snap::string::uppercase(LOWERCASE));
  EXPECT_EQ(std::string(UPPERCASE), snap::string::uppercase(UPPERCASE));
}

TEST_F(StringTest, testLowercaseReturnLowercasedInput) {
  EXPECT_EQ(std::string(LOWERCASE), snap::string::lowercase(UPPERCASE));
  EXPECT_EQ(std::string(LOWERCASE), snap::string::lowercase(LOWERCASE));
}