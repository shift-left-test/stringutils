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
  static constexpr const char *EMPTY = "";
  static constexpr const char *hello_world = "hello world";
  static constexpr const char *HELLO_WORLD = "HELLO WORLD";
  static constexpr const char *HELLO = "HELLO";
  static constexpr const char *WORLD = "WORLD";
  static constexpr const char NULL_CHAR = '\0';
  static constexpr const char SPACE_CHAR = ' ';
};

constexpr const char *StringTest::EMPTY;
constexpr const char *StringTest::hello_world;
constexpr const char *StringTest::HELLO_WORLD;
constexpr const char *StringTest::HELLO;
constexpr const char *StringTest::WORLD;
constexpr const char StringTest::NULL_CHAR;
constexpr const char StringTest::SPACE_CHAR;


TEST_F(StringTest, testStartsWithReturnTrueWhenValidInputGiven) {
  EXPECT_TRUE(snap::string::startsWith(HELLO_WORLD, HELLO_WORLD));
  EXPECT_TRUE(snap::string::startsWith(HELLO_WORLD, HELLO));
  EXPECT_TRUE(snap::string::startsWith(HELLO_WORLD, EMPTY));
  EXPECT_TRUE(snap::string::startsWith(EMPTY, EMPTY));
}

TEST_F(StringTest, testStartsWithReturnFalseWhenInvalidInputGiven) {
  EXPECT_FALSE(snap::string::startsWith(WORLD, HELLO_WORLD));
  EXPECT_FALSE(snap::string::startsWith(HELLO_WORLD, WORLD));
  EXPECT_FALSE(snap::string::startsWith(EMPTY, HELLO_WORLD));
}

TEST_F(StringTest, testEndsWithReturnTrueWhenValidInputGiven) {
  EXPECT_TRUE(snap::string::endsWith(HELLO_WORLD, HELLO_WORLD));
  EXPECT_TRUE(snap::string::endsWith(HELLO_WORLD, WORLD));
  EXPECT_TRUE(snap::string::endsWith(HELLO_WORLD, EMPTY));
  EXPECT_TRUE(snap::string::endsWith(EMPTY, EMPTY));
}

TEST_F(StringTest, testEndsWithReturnFalseWhenInvalidInputGiven) {
  EXPECT_FALSE(snap::string::endsWith(HELLO, HELLO_WORLD));
  EXPECT_FALSE(snap::string::endsWith(HELLO_WORLD, HELLO));
  EXPECT_FALSE(snap::string::endsWith(EMPTY, HELLO_WORLD));
}

TEST_F(StringTest, testUppercaseReturnUppercasedInput) {
  EXPECT_EQ(HELLO_WORLD, snap::string::uppercase(hello_world));
  EXPECT_EQ(HELLO_WORLD, snap::string::uppercase(HELLO_WORLD));
}

TEST_F(StringTest, testLowercaseReturnLowercasedInput) {
  EXPECT_EQ(hello_world, snap::string::lowercase(HELLO_WORLD));
  EXPECT_EQ(hello_world, snap::string::lowercase(hello_world));
}

TEST_F(StringTest, testLstripRemovesLeadingWhitespaces) {
  EXPECT_EQ(HELLO, snap::string::lstrip(HELLO));
  EXPECT_EQ(HELLO, snap::string::lstrip("  \t\r HELLO"));
  EXPECT_EQ(EMPTY, snap::string::lstrip(EMPTY));
}

TEST_F(StringTest, testLstripWithCharRemovesTheLeadingChars) {
  EXPECT_EQ(HELLO, snap::string::lstrip(" HELLO", SPACE_CHAR));
  EXPECT_EQ(HELLO, snap::string::lstrip("   HELLO", SPACE_CHAR));
  EXPECT_EQ(HELLO, snap::string::lstrip(HELLO, SPACE_CHAR));
  EXPECT_EQ(" HELLO", snap::string::lstrip(" HELLO", NULL_CHAR));
}

TEST_F(StringTest, testRstripRemovesTrailingWhitespaces) {
  EXPECT_EQ(HELLO, snap::string::rstrip(HELLO));
  EXPECT_EQ(HELLO, snap::string::rstrip("HELLO  \r\t  "));
  EXPECT_EQ(EMPTY, snap::string::rstrip(EMPTY));
}

TEST_F(StringTest, testRstripWithCharRemovesTheTrailingChars) {
  EXPECT_EQ(HELLO, snap::string::rstrip("HELLO ", SPACE_CHAR));
  EXPECT_EQ(HELLO, snap::string::rstrip("HELLO   ", SPACE_CHAR));
  EXPECT_EQ(HELLO, snap::string::rstrip(HELLO, SPACE_CHAR));
  EXPECT_EQ("HELLO ", snap::string::rstrip("HELLO ", NULL_CHAR));
}

TEST_F(StringTest, testStripRemovesLeadingAndTrailingSpaces) {
  EXPECT_EQ(HELLO, snap::string::strip(HELLO));
  EXPECT_EQ(HELLO, snap::string::strip("  HELLO  "));
  EXPECT_EQ(EMPTY, snap::string::strip(EMPTY));
}

TEST_F(StringTest, testStripWithCharsRemovesLeadingAndTrailingChars) {
  EXPECT_EQ(HELLO, snap::string::strip(HELLO, SPACE_CHAR));
  EXPECT_EQ(HELLO, snap::string::strip("  HELLO  ", SPACE_CHAR));
  EXPECT_EQ(" HELLO ", snap::string::strip(" HELLO ", NULL_CHAR));
  EXPECT_EQ(EMPTY, snap::string::strip(EMPTY, SPACE_CHAR));
  EXPECT_EQ(EMPTY, snap::string::strip(EMPTY, NULL_CHAR));
}
