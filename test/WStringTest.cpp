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

class WStringTest : public ::testing::Test {
 protected:
  constexpr static const wchar_t *SOURCE = L"hello world";
  constexpr static const wchar_t *PREFIX = L"hello";
  constexpr static const wchar_t *SUFFIX = L"world";
  constexpr static const wchar_t *EMPTY = L"";
  constexpr static const wchar_t *UPPERCASE = L"HELLO WORLD";
  constexpr static const wchar_t *LOWERCASE = L"hello world";
};

TEST_F(WStringTest, testStartsWithReturnTrueWhenValidInputGiven) {
  EXPECT_TRUE(snap::string::startsWith(SOURCE, SOURCE));
  EXPECT_TRUE(snap::string::startsWith(SOURCE, PREFIX));
  EXPECT_TRUE(snap::string::startsWith(SOURCE, EMPTY));
  EXPECT_TRUE(snap::string::startsWith(EMPTY, EMPTY));
}

TEST_F(WStringTest, testStartsWithReturnFalseWhenInvalidInputGiven) {
  EXPECT_FALSE(snap::string::startsWith(SUFFIX, SOURCE));
  EXPECT_FALSE(snap::string::startsWith(SOURCE, SUFFIX));
  EXPECT_FALSE(snap::string::startsWith(EMPTY, SOURCE));
}

TEST_F(WStringTest, testEndsWithReturnTrueWhenValidInputGiven) {
  EXPECT_TRUE(snap::string::endsWith(SOURCE, SOURCE));
  EXPECT_TRUE(snap::string::endsWith(SOURCE, SUFFIX));
  EXPECT_TRUE(snap::string::endsWith(SOURCE, EMPTY));
  EXPECT_TRUE(snap::string::endsWith(EMPTY, EMPTY));
}

TEST_F(WStringTest, testEndsWithReturnFalseWhenInvalidInputGiven) {
  EXPECT_FALSE(snap::string::endsWith(PREFIX, SOURCE));
  EXPECT_FALSE(snap::string::endsWith(SOURCE, PREFIX));
  EXPECT_FALSE(snap::string::endsWith(EMPTY, SOURCE));
}

TEST_F(WStringTest, testUppercaseReturnUppercasedInput) {
  EXPECT_EQ(std::wstring(UPPERCASE), snap::string::uppercase(LOWERCASE));
  EXPECT_EQ(std::wstring(UPPERCASE), snap::string::uppercase(UPPERCASE));
}

TEST_F(WStringTest, testLowercaseReturnLowercasedInput) {
  EXPECT_EQ(std::wstring(LOWERCASE), snap::string::lowercase(UPPERCASE));
  EXPECT_EQ(std::wstring(LOWERCASE), snap::string::lowercase(LOWERCASE));
}
