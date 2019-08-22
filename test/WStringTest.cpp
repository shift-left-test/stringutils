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
#include <cctype>
#include <string>
#include "snap/string.hpp"

class WStringTest : public ::testing::Test {
 protected:
  static constexpr const wchar_t *EMPTY = L"";
  static constexpr const wchar_t *hello_world = L"hello world";
  static constexpr const wchar_t *HELLO_WORLD = L"HELLO WORLD";
  static constexpr const wchar_t *HELLO = L"HELLO";
  static constexpr const wchar_t *WORLD = L"WORLD";
  static constexpr const wchar_t NULL_CHAR = L'\0';
  static constexpr const wchar_t SPACE_CHAR = L' ';
};

constexpr const wchar_t *WStringTest::EMPTY;
constexpr const wchar_t *WStringTest::hello_world;
constexpr const wchar_t *WStringTest::HELLO_WORLD;
constexpr const wchar_t *WStringTest::HELLO;
constexpr const wchar_t *WStringTest::WORLD;
constexpr const wchar_t WStringTest::NULL_CHAR;
constexpr const wchar_t WStringTest::SPACE_CHAR;


TEST_F(WStringTest, testStartsWithReturnTrueWhenValidInputGiven) {
  EXPECT_TRUE(snap::string::startsWith(HELLO_WORLD, HELLO_WORLD));
  EXPECT_TRUE(snap::string::startsWith(HELLO_WORLD, HELLO));
  EXPECT_TRUE(snap::string::startsWith(HELLO_WORLD, EMPTY));
  EXPECT_TRUE(snap::string::startsWith(EMPTY, EMPTY));
}

TEST_F(WStringTest, testStartsWithReturnFalseWhenInvalidInputGiven) {
  EXPECT_FALSE(snap::string::startsWith(WORLD, HELLO_WORLD));
  EXPECT_FALSE(snap::string::startsWith(HELLO_WORLD, WORLD));
  EXPECT_FALSE(snap::string::startsWith(EMPTY, HELLO_WORLD));
}

TEST_F(WStringTest, testEndsWithReturnTrueWhenValidInputGiven) {
  EXPECT_TRUE(snap::string::endsWith(HELLO_WORLD, HELLO_WORLD));
  EXPECT_TRUE(snap::string::endsWith(HELLO_WORLD, WORLD));
  EXPECT_TRUE(snap::string::endsWith(HELLO_WORLD, EMPTY));
  EXPECT_TRUE(snap::string::endsWith(EMPTY, EMPTY));
}

TEST_F(WStringTest, testEndsWithReturnFalseWhenInvalidInputGiven) {
  EXPECT_FALSE(snap::string::endsWith(HELLO, HELLO_WORLD));
  EXPECT_FALSE(snap::string::endsWith(HELLO_WORLD, HELLO));
  EXPECT_FALSE(snap::string::endsWith(EMPTY, HELLO_WORLD));
}

TEST_F(WStringTest, testTransformReturnsConvertedString) {
  EXPECT_EQ(HELLO_WORLD, snap::string::transform(hello_world, ::toupper));
  EXPECT_EQ(HELLO_WORLD, snap::string::transform(HELLO_WORLD, ::toupper));
}

TEST_F(WStringTest, testUppercaseReturnUppercasedInput) {
  EXPECT_EQ(HELLO_WORLD, snap::string::uppercase(hello_world));
  EXPECT_EQ(HELLO_WORLD, snap::string::uppercase(HELLO_WORLD));
}

TEST_F(WStringTest, testLowercaseReturnLowercasedInput) {
  EXPECT_EQ(hello_world, snap::string::lowercase(HELLO_WORLD));
  EXPECT_EQ(hello_world, snap::string::lowercase(hello_world));
}

TEST_F(WStringTest, testLstripRemovesLeadingWhitespaces) {
  EXPECT_EQ(HELLO, snap::string::lstrip(HELLO));
  EXPECT_EQ(HELLO, snap::string::lstrip(L"  \t\r HELLO"));
  EXPECT_EQ(EMPTY, snap::string::lstrip(EMPTY));
}

TEST_F(WStringTest, testLstripWithCharRemovesTheLeadingChars) {
  EXPECT_EQ(HELLO, snap::string::lstrip(L" HELLO", SPACE_CHAR));
  EXPECT_EQ(HELLO, snap::string::lstrip(L"   HELLO", SPACE_CHAR));
  EXPECT_EQ(HELLO, snap::string::lstrip(HELLO, SPACE_CHAR));
  EXPECT_EQ(L" HELLO", snap::string::lstrip(L" HELLO", NULL_CHAR));
}

TEST_F(WStringTest, testRstripRemovesTrailingWhitespaces) {
  EXPECT_EQ(HELLO, snap::string::rstrip(HELLO));
  EXPECT_EQ(HELLO, snap::string::rstrip(L"HELLO  \r\t  "));
  EXPECT_EQ(EMPTY, snap::string::rstrip(EMPTY));
}

TEST_F(WStringTest, testRstripWithCharRemovesTheTrailingChars) {
  EXPECT_EQ(HELLO, snap::string::rstrip(L"HELLO ", SPACE_CHAR));
  EXPECT_EQ(HELLO, snap::string::rstrip(L"HELLO   ", SPACE_CHAR));
  EXPECT_EQ(HELLO, snap::string::rstrip(HELLO, SPACE_CHAR));
  EXPECT_EQ(L"HELLO ", snap::string::rstrip(L"HELLO ", NULL_CHAR));
}

TEST_F(WStringTest, testStripRemovesLeadingAndTrailingSpaces) {
  EXPECT_EQ(HELLO, snap::string::strip(HELLO));
  EXPECT_EQ(HELLO, snap::string::strip(L"  HELLO  "));
  EXPECT_EQ(EMPTY, snap::string::strip(EMPTY));
}

TEST_F(WStringTest, testStripWithCharsRemovesLeadingAndTrailingChars) {
  EXPECT_EQ(HELLO, snap::string::strip(HELLO, SPACE_CHAR));
  EXPECT_EQ(HELLO, snap::string::strip(L"  HELLO  ", SPACE_CHAR));
  EXPECT_EQ(L" HELLO ", snap::string::strip(L" HELLO ", NULL_CHAR));
  EXPECT_EQ(EMPTY, snap::string::strip(EMPTY, SPACE_CHAR));
  EXPECT_EQ(EMPTY, snap::string::strip(EMPTY, NULL_CHAR));
}
