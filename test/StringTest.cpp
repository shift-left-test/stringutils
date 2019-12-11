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
#include "util/string.hpp"


class StringTest : public ::testing::Test {
 protected:
  template <typename T>
  void checkStartsWith(const std::basic_string<T> &text,
                       const T *prefix,
                       const T *suffix,
                       const std::basic_string<T> &blank) {
    EXPECT_TRUE(util::string::startsWith(text, text));
    EXPECT_TRUE(util::string::startsWith(text, prefix));
    EXPECT_TRUE(util::string::startsWith(text, blank));
    EXPECT_TRUE(util::string::startsWith(blank, blank));
    EXPECT_FALSE(util::string::startsWith(prefix, text));
    EXPECT_FALSE(util::string::startsWith(text, suffix));
    EXPECT_FALSE(util::string::startsWith(blank, text));
  }

  template <typename T>
  void checkEndsWith(const std::basic_string<T> &text,
                     const T *prefix,
                     const T *suffix,
                     const std::basic_string<T> &blank) {
    EXPECT_TRUE(util::string::endsWith(text, text));
    EXPECT_TRUE(util::string::endsWith(text, suffix));
    EXPECT_TRUE(util::string::endsWith(text, blank));
    EXPECT_TRUE(util::string::endsWith(blank, blank));
    EXPECT_FALSE(util::string::endsWith(prefix, text));
    EXPECT_FALSE(util::string::endsWith(text, prefix));
    EXPECT_FALSE(util::string::endsWith(blank, text));
  }

  template <typename T>
  void checkTransform(const std::basic_string<T> &uppercase,
                      const T *lowercase) {
    EXPECT_EQ(uppercase, util::string::transform(uppercase, ::toupper));
    EXPECT_EQ(uppercase, util::string::transform(lowercase, ::toupper));
  }

  template <typename T>
  void checkUppercase(const std::basic_string<T> &uppercase,
                      const T *lowercase,
                      const T *blank) {
    EXPECT_EQ(uppercase, util::string::uppercase(uppercase));
    EXPECT_EQ(uppercase, util::string::uppercase(lowercase));
    EXPECT_EQ(blank, util::string::uppercase(blank));
  }

  template <typename T>
  void checkLowercase(const std::basic_string<T> &uppercase,
                      const T *lowercase,
                      const T *blank) {
    EXPECT_EQ(lowercase, util::string::lowercase(uppercase));
    EXPECT_EQ(lowercase, util::string::lowercase(lowercase));
    EXPECT_EQ(blank, util::string::lowercase(blank));
  }

  template <typename T>
  void checkLtrim(const std::basic_string<T> &rawText,
                   const T *text,
                   const T *space,
                   const std::basic_string<T> &blank) {
    EXPECT_EQ(text, util::string::ltrim(rawText));
    EXPECT_EQ(text, util::string::ltrim(text));
    EXPECT_EQ(blank, util::string::ltrim(space));
    EXPECT_EQ(blank, util::string::ltrim(blank));
  }

  template <typename T>
  void checkLtrimWithChar(const std::basic_string<T> &rawText,
                           const T *text,
                           const T space,
                           const T blank) {
    EXPECT_EQ(text, util::string::ltrim(rawText, space));
    EXPECT_EQ(text, util::string::ltrim(text, space));
    EXPECT_EQ(rawText, util::string::ltrim(rawText, blank));
  }

  template <typename T>
  void checkRtrim(const std::basic_string<T> &rawText,
                   const T *text,
                   const T *space,
                   const std::basic_string<T> &blank) {
    EXPECT_EQ(text, util::string::rtrim(rawText));
    EXPECT_EQ(text, util::string::rtrim(text));
    EXPECT_EQ(blank, util::string::rtrim(space));
    EXPECT_EQ(blank, util::string::rtrim(blank));
  }

  template <typename T>
  void checkRtrimWithChar(const std::basic_string<T> &rawText,
                           const T *text,
                           const T space,
                           const T blank) {
    EXPECT_EQ(text, util::string::rtrim(rawText, space));
    EXPECT_EQ(text, util::string::rtrim(text, space));
    EXPECT_EQ(rawText, util::string::rtrim(rawText, blank));
  }

  template <typename T>
  void checkTrim(const std::basic_string<T> &rawText,
                  const T *text,
                  const T *space,
                  const std::basic_string<T> &blank) {
    EXPECT_EQ(text, util::string::trim(rawText));
    EXPECT_EQ(text, util::string::trim(text));
    EXPECT_EQ(blank, util::string::trim(space));
    EXPECT_EQ(blank, util::string::trim(blank));
  }

  template <typename T>
  void checkTrimWithChar(const std::basic_string<T> &rawText,
                          const T *text,
                          const T space,
                          const T blank) {
    EXPECT_EQ(text, util::string::trim(rawText, space));
    EXPECT_EQ(text, util::string::trim(text, space));
    EXPECT_EQ(rawText, util::string::trim(rawText, blank));
  }

  template <typename T>
  void checkContains(const std::basic_string<T> &text,
                     const std::basic_string<T> &capitalized,
                     const T *prefix,
                     const T *suffix,
                     const T *space,
                     const T *blank,
                     const T *weird) {
    EXPECT_TRUE(util::string::contains(text, text));
    EXPECT_TRUE(util::string::contains(text, prefix));
    EXPECT_TRUE(util::string::contains(text, suffix));
    EXPECT_TRUE(util::string::contains(text, blank));
    EXPECT_FALSE(util::string::contains(text, capitalized));
    EXPECT_FALSE(util::string::contains(prefix, text));
    EXPECT_FALSE(util::string::contains(suffix, text));
    EXPECT_FALSE(util::string::contains(prefix, suffix));
    EXPECT_FALSE(util::string::contains(text, weird));
  }

  template <typename T>
  void checkReplaceWithChar(const std::basic_string<T> &rawText,
                            const T *text,
                            const T space,
                            const T delim) {
    EXPECT_EQ(text, util::string::replace(rawText, delim, space));
    EXPECT_EQ(text, util::string::replace(text, delim, space));
    EXPECT_EQ(rawText, util::string::replace(text, space, delim));
    EXPECT_EQ(rawText, util::string::replace(rawText, space, delim));
  }

  template <typename T>
  void checkReplaceWithString(const std::basic_string<T> &rawText,
                              const T *text,
                              const T *space,
                              const T *delim,
                              const T *blank) {
    EXPECT_EQ(text, util::string::replace(rawText, delim, space));
    EXPECT_EQ(text, util::string::replace(text, delim, space));
    EXPECT_EQ(rawText, util::string::replace(text, space, delim));
    EXPECT_EQ(rawText, util::string::replace(rawText, space, delim));
    EXPECT_EQ(blank, util::string::replace(blank, space, delim));
    EXPECT_EQ(rawText, util::string::replace(rawText, blank, space));
  }
};

TEST_F(StringTest, testStartsWithForString) {
  const std::string TEXT = "hello world";
  const char *PREFIX = "hello";
  const char *SUFFIX = "world";
  const std::string BLANK = "";
  checkStartsWith(TEXT, PREFIX, SUFFIX, BLANK);
}

TEST_F(StringTest, testStartsWithForU8String) {
  const std::string TEXT = u8"hello world";
  const char *PREFIX = u8"hello";
  const char *SUFFIX = u8"world";
  const std::string BLANK = u8"";
  checkStartsWith(TEXT, PREFIX, SUFFIX, BLANK);
}

TEST_F(StringTest, testStartsWithForWString) {
  const std::wstring TEXT = L"hello world";
  const wchar_t *PREFIX = L"hello";
  const wchar_t *SUFFIX = L"world";
  const std::wstring BLANK = L"";
  checkStartsWith(TEXT, PREFIX, SUFFIX, BLANK);
}

TEST_F(StringTest, testEndsWithForString) {
  const std::string TEXT = "hello world";
  const char *PREFIX = "hello";
  const char *SUFFIX = "world";
  const std::string BLANK = "";
  checkEndsWith(TEXT, PREFIX, SUFFIX, BLANK);
}

TEST_F(StringTest, testEndsWithForU8String) {
  const std::string TEXT = u8"hello world";
  const char *PREFIX = u8"hello";
  const char *SUFFIX = u8"world";
  const std::string BLANK = u8"";
  checkEndsWith(TEXT, PREFIX, SUFFIX, BLANK);
}

TEST_F(StringTest, testEndsWithForWString) {
  const std::wstring TEXT = L"hello world";
  const wchar_t *PREFIX = L"hello";
  const wchar_t *SUFFIX = L"world";
  const std::wstring BLANK = L"";
  checkEndsWith(TEXT, PREFIX, SUFFIX, BLANK);
}

TEST_F(StringTest, testTransformForString) {
  const std::string UPPERCASE = "HELLO WORLD";
  const char *LOWERCASE = "hello world";
  checkTransform(UPPERCASE, LOWERCASE);
}

TEST_F(StringTest, testTransformForU8String) {
  const std::string UPPERCASE = u8"HELLO WORLD";
  const char *LOWERCASE = u8"hello world";
  checkTransform(UPPERCASE, LOWERCASE);
}

TEST_F(StringTest, testTransformForWString) {
  const std::wstring UPPERCASE = L"HELLO WORLD";
  const wchar_t *LOWERCASE = L"hello world";
  checkTransform(UPPERCASE, LOWERCASE);
}

TEST_F(StringTest, testUppercaseForString) {
  const std::string UPPERCASE = "HELLO WORLD";
  const char *LOWERCASE = "hello world";
  const char *BLANK = "";
  checkUppercase(UPPERCASE, LOWERCASE, BLANK);
}

TEST_F(StringTest, testUppercaseForU8String) {
  const std::string UPPERCASE = u8"HELLO WORLD";
  const char *LOWERCASE = u8"hello world";
  const char *BLANK = u8"";
  checkUppercase(UPPERCASE, LOWERCASE, BLANK);
}

TEST_F(StringTest, testUppercaseForWString) {
  const std::wstring UPPERCASE = L"HELLO WORLD";
  const wchar_t *LOWERCASE = L"hello world";
  const wchar_t *BLANK = L"";
  checkUppercase(UPPERCASE, LOWERCASE, BLANK);
}

TEST_F(StringTest, testLowercaseForString) {
  const std::string UPPERCASE = "HELLO WORLD";
  const char *LOWERCASE = "hello world";
  const char *BLANK = "";
  checkLowercase(UPPERCASE, LOWERCASE, BLANK);
}

TEST_F(StringTest, testLowercaseForU8String) {
  const std::string UPPERCASE = u8"HELLO WORLD";
  const char *LOWERCASE = u8"hello world";
  const char *BLANK = u8"";
  checkLowercase(UPPERCASE, LOWERCASE, BLANK);
}

TEST_F(StringTest, testLowercaseForWString) {
  const std::wstring UPPERCASE = L"HELLO WORLD";
  const wchar_t *LOWERCASE = L"hello world";
  const wchar_t *BLANK = L"";
  checkLowercase(UPPERCASE, LOWERCASE, BLANK);
}

TEST_F(StringTest, testLtrimForString) {
  const std::string RAW_TEXT = " \t\r 테스트";
  const char *TEXT = "테스트";
  const char *SPACE = " ";
  const std::string BLANK = "";
  checkLtrim(RAW_TEXT, TEXT, SPACE, BLANK);
}

TEST_F(StringTest, testLtrimForU8String) {
  const std::string RAW_TEXT = u8" \t\r hello";
  const char *TEXT = u8"hello";
  const char *SPACE = u8" ";
  const std::string BLANK = u8"";
  checkLtrim(RAW_TEXT, TEXT, SPACE, BLANK);
}

TEST_F(StringTest, testLtrimForWString) {
  const std::wstring RAW_TEXT = L" \t\r hello";
  const wchar_t *TEXT = L"hello";
  const wchar_t *SPACE = L" ";
  const std::wstring BLANK = L"";
  checkLtrim(RAW_TEXT, TEXT, SPACE, BLANK);
}

TEST_F(StringTest, testLtrimWithCharForString) {
  const std::string RAW_TEXT = "  hello";
  const char *TEXT = "hello";
  const char SPACE = ' ';
  const char BLANK = '\0';
  checkLtrimWithChar(RAW_TEXT, TEXT, SPACE, BLANK);
}

TEST_F(StringTest, testLtrimWithCharForU8String) {
  const std::string RAW_TEXT = u8"  hello";
  const char *TEXT = u8"hello";
  const char SPACE = ' ';
  const char BLANK = '\0';
  checkLtrimWithChar(RAW_TEXT, TEXT, SPACE, BLANK);
}

TEST_F(StringTest, testLtrimWithCharForWString) {
  const std::wstring RAW_TEXT = L"  hello";
  const wchar_t *TEXT = L"hello";
  const wchar_t SPACE = L' ';
  const wchar_t BLANK = L'\0';
  checkLtrimWithChar(RAW_TEXT, TEXT, SPACE, BLANK);
}

TEST_F(StringTest, testRtrimForString) {
  const std::string RAW_TEXT = "hello \r\t ";
  const char *TEXT = "hello";
  const char *SPACE = " ";
  const std::string BLANK = "";
  checkRtrim(RAW_TEXT, TEXT, SPACE, BLANK);
}

TEST_F(StringTest, testRtrimForU8String) {
  const std::string RAW_TEXT = u8"hello \r\t ";
  const char *TEXT = u8"hello";
  const char *SPACE = u8" ";
  const std::string BLANK = u8"";
  checkRtrim(RAW_TEXT, TEXT, SPACE, BLANK);
}

TEST_F(StringTest, testRtrimForWString) {
  const std::wstring RAW_TEXT = L"hello \r\t ";
  const wchar_t *TEXT = L"hello";
  const wchar_t *SPACE = L" ";
  const std::wstring BLANK = L"";
  checkRtrim(RAW_TEXT, TEXT, SPACE, BLANK);
}

TEST_F(StringTest, testRtrimWithCharForString) {
  const std::string RAW_TEXT = "hello  ";
  const char *TEXT = "hello";
  const char SPACE = ' ';
  const char BLANK = '\0';
  checkRtrimWithChar(RAW_TEXT, TEXT, SPACE, BLANK);
}

TEST_F(StringTest, testRtrimWithCharForU8String) {
  const std::string RAW_TEXT = u8"hello  ";
  const char *TEXT = u8"hello";
  const char SPACE = ' ';
  const char BLANK = '\0';
  checkRtrimWithChar(RAW_TEXT, TEXT, SPACE, BLANK);
}

TEST_F(StringTest, testRtrimWithCharForWString) {
  const std::wstring RAW_TEXT = L"hello  ";
  const wchar_t *TEXT = L"hello";
  const wchar_t SPACE = L' ';
  const wchar_t BLANK = L'\0';
  checkRtrimWithChar(RAW_TEXT, TEXT, SPACE, BLANK);
}

TEST_F(StringTest, testTrimForString) {
  const std::string RAW_TEXT = "  hello  ";
  const char *TEXT = "hello";
  const char *SPACE = " ";
  const std::string BLANK = "";
  checkTrim(RAW_TEXT, TEXT, SPACE, BLANK);
}

TEST_F(StringTest, testTrimForU8String) {
  const std::string RAW_TEXT = u8"  hello  ";
  const char *TEXT = u8"hello";
  const char *SPACE = u8" ";
  const std::string BLANK = u8"";
  checkTrim(RAW_TEXT, TEXT, SPACE, BLANK);
}

TEST_F(StringTest, testTrimForWString) {
  const std::wstring RAW_TEXT = L"  hello  ";
  const wchar_t *TEXT = L"hello";
  const wchar_t *SPACE = L" ";
  const std::wstring BLANK = L"";
  checkTrim(RAW_TEXT, TEXT, SPACE, BLANK);
}

TEST_F(StringTest, testTrimWithCharForString) {
  const std::string RAW_TEXT = "  hello  ";
  const char *TEXT = "hello";
  const char SPACE = ' ';
  const char BLANK = '\0';
  checkTrimWithChar(RAW_TEXT, TEXT, SPACE, BLANK);
}

TEST_F(StringTest, testTrimWithCharForU8String) {
  const std::string RAW_TEXT = u8"  hello  ";
  const char *TEXT = u8"hello";
  const char SPACE = ' ';
  const char BLANK = '\0';
  checkTrimWithChar(RAW_TEXT, TEXT, SPACE, BLANK);
}

TEST_F(StringTest, testTrimWithCharForWString) {
  const std::wstring RAW_TEXT = L"  hello  ";
  const wchar_t *TEXT = L"hello";
  const wchar_t SPACE = L' ';
  const wchar_t BLANK = L'\0';
  checkTrimWithChar(RAW_TEXT, TEXT, SPACE, BLANK);
}

TEST_F(StringTest, testContainsForString) {
  const std::string TEXT = "hello world";
  const std::string CAPITALIZED = "HELLO WORLD";
  const char *PREFIX = "hello";
  const char *SUFFIX = "world";
  const char *SPACE = " ";
  const char *BLANK = "";
  const char *WEIRD = "?";
  checkContains(TEXT, CAPITALIZED, PREFIX, SUFFIX, SPACE, BLANK, WEIRD);
}

TEST_F(StringTest, testContainsForU8String) {
  const std::string TEXT = u8"hello world";
  const std::string CAPITALIZED = u8"HELLO WORLD";
  const char *PREFIX = u8"hello";
  const char *SUFFIX = u8"world";
  const char *SPACE = u8" ";
  const char *BLANK = u8"";
  const char *WEIRD = u8"?";
  checkContains(TEXT, CAPITALIZED, PREFIX, SUFFIX, SPACE, BLANK, WEIRD);
}

TEST_F(StringTest, testContainsForWString) {
  const std::wstring TEXT = L"hello world";
  const std::wstring CAPITALIZED = L"HELLO WORLD";
  const wchar_t *PREFIX = L"hello";
  const wchar_t *SUFFIX = L"world";
  const wchar_t *SPACE = L" ";
  const wchar_t *BLANK = L"";
  const wchar_t *WEIRD = L"?";
  checkContains(TEXT, CAPITALIZED, PREFIX, SUFFIX, SPACE, BLANK, WEIRD);
}

TEST_F(StringTest, replaceWithCharForString) {
  const std::string RAW_TEXT = "hello_world";
  const char *TEXT = "hello world";
  const char SPACE = ' ';
  const char DELIM = '_';
  checkReplaceWithChar(RAW_TEXT, TEXT, SPACE, DELIM);
}

TEST_F(StringTest, replaceWithCharForU8String) {
  const std::string RAW_TEXT = u8"hello_world";
  const char *TEXT = u8"hello world";
  const char SPACE = ' ';
  const char DELIM = '_';
  checkReplaceWithChar(RAW_TEXT, TEXT, SPACE, DELIM);
}

TEST_F(StringTest, replaceWithCharForWString) {
  const std::wstring RAW_TEXT = L"hello_world";
  const wchar_t *TEXT = L"hello world";
  const wchar_t SPACE = L' ';
  const wchar_t DELIM = L'_';
  checkReplaceWithChar(RAW_TEXT, TEXT, SPACE, DELIM);
}

TEST_F(StringTest, replaceWithStringForString) {
  const std::string RAW_TEXT = " hello__world ";
  const char *TEXT = " hello  world ";
  const char *SPACE = "  ";
  const char *DELIM = "__";
  const char *BLANK = "";
  checkReplaceWithString(RAW_TEXT, TEXT, SPACE, DELIM, BLANK);
}

TEST_F(StringTest, replaceWithStringForU8String) {
  const std::string RAW_TEXT = u8" hello__world ";
  const char *TEXT = u8" hello  world ";
  const char *SPACE = u8"  ";
  const char *DELIM = u8"__";
  const char *BLANK = u8"";
  checkReplaceWithString(RAW_TEXT, TEXT, SPACE, DELIM, BLANK);
}

TEST_F(StringTest, replaceWithStringForWString) {
  const std::wstring RAW_TEXT = L" hello__world ";
  const wchar_t *TEXT = L" hello  world ";
  const wchar_t *SPACE = L"  ";
  const wchar_t *DELIM = L"__";
  const wchar_t *BLANK = L"";
  checkReplaceWithString(RAW_TEXT, TEXT, SPACE, DELIM, BLANK);
}

TEST_F(StringTest, formatWithArgsForString) {
  const char *FORMAT = "%s %s";
  const std::string ARG1 = "hello";
  const char *ARG2 = "world";
  const char *EXPECTED = "hello world";
  EXPECT_EQ(EXPECTED, util::string::format(FORMAT, ARG1, ARG2));
}

TEST_F(StringTest, formatWithArgsForU8String) {
  const char *FORMAT = u8"%s %s";
  const std::string ARG1 = u8"hello";
  const char *ARG2 = u8"world";
  const char *EXPECTED = u8"hello world";
  EXPECT_EQ(EXPECTED, util::string::format(FORMAT, ARG1, ARG2));
}

TEST_F(StringTest, formatWithArgsForWString) {
  const wchar_t *FORMAT = L"%S %S";
  const std::wstring ARG1 = L"hello";
  const wchar_t *ARG2 = L"world";
  const wchar_t *EXPECTED = L"hello world";
  EXPECT_EQ(EXPECTED, util::string::format(FORMAT, ARG1, ARG2));
}

TEST_F(StringTest, splitForString) {
  const char *TEXT = "hello world";
  const char TOKEN = ' ';
  const char *FIRST = "hello";
  const char *SECOND = "world";

  auto actual = util::string::split(TEXT, TOKEN);
  ASSERT_EQ(2, actual.size());
  EXPECT_EQ(FIRST, actual[0]);
  EXPECT_EQ(SECOND, actual[1]);
}

TEST_F(StringTest, splitVariousStrings) {
  EXPECT_EQ(0, util::string::split("", ' ').size());
  EXPECT_EQ(0, util::string::split("\0", '\0').size());
  EXPECT_EQ(1, util::string::split(" ", '\0').size());
  EXPECT_EQ(1, util::string::split(" ", ' ').size());
  EXPECT_EQ(1, util::string::split("hello", ' ').size());
}

TEST_F(StringTest, splitForU8String) {
  const char *TEXT = u8"hello world";
  const char TOKEN = ' ';
  const char *FIRST = u8"hello";
  const char *SECOND = u8"world";

  auto actual = util::string::split(TEXT, TOKEN);
  ASSERT_EQ(2, actual.size());
  EXPECT_EQ(FIRST, actual[0]);
  EXPECT_EQ(SECOND, actual[1]);
}

TEST_F(StringTest, splitForWString) {
  const wchar_t *TEXT = L"hello world";
  const wchar_t TOKEN = ' ';
  const wchar_t *FIRST = L"hello";
  const wchar_t *SECOND = L"world";

  auto actual = util::string::split(TEXT, TOKEN);
  ASSERT_EQ(2, actual.size());
  EXPECT_EQ(FIRST, actual[0]);
  EXPECT_EQ(SECOND, actual[1]);
}

TEST_F(StringTest, joinVariousStrings) {
  EXPECT_EQ("", util::string::join({"", ""}, ""));
  EXPECT_EQ("\0", util::string::join({"", ""}, "\0"));
  EXPECT_EQ("", util::string::join({"\0", "\0"}, "\0"));
}

TEST_F(StringTest, joinForString) {
  const char *FIRST = "hello";
  const char *SECOND = "world";
  const char *DELIM = " ";
  const char *EXPECTED = "hello world";
  EXPECT_EQ(EXPECTED, util::string::join({FIRST, SECOND}, DELIM));
}

TEST_F(StringTest, joinForU8String) {
  const char *FIRST = u8"hello";
  const char *SECOND = u8"world";
  const char *DELIM = u8" ";
  const char *EXPECTED = u8"hello world";
  EXPECT_EQ(EXPECTED, util::string::join({FIRST, SECOND}, DELIM));
}

TEST_F(StringTest, joinForWString) {
  const wchar_t *FIRST = L"hello";
  const wchar_t *SECOND = L"world";
  const wchar_t *DELIM = L" ";
  const wchar_t *EXPECTED = L"hello world";
  EXPECT_EQ(EXPECTED, util::string::join({FIRST, SECOND}, DELIM));
}

TEST_F(StringTest, reverseStrings) {
  EXPECT_EQ("olleh", util::string::reverse("hello"));
  EXPECT_EQ(u8"olleh", util::string::reverse(u8"hello"));
  EXPECT_EQ(L"olleh", util::string::reverse(L"hello"));
}

TEST_F(StringTest, translateStrings) {
  EXPECT_EQ("h1ll2", util::string::translate("hello", "eolz", "12"));
  EXPECT_EQ("hello", util::string::translate("hello", "eolz", ""));
  EXPECT_EQ("hello", util::string::translate("hello", "", "12"));

  EXPECT_EQ(u8"h1ll2", util::string::translate(u8"hello", u8"eolz", u8"12"));
  EXPECT_EQ(u8"hello", util::string::translate(u8"hello", u8"eolz", u8""));
  EXPECT_EQ(u8"hello", util::string::translate(u8"hello", u8"", u8"12"));

  EXPECT_EQ(L"h1ll2", util::string::translate(L"hello", L"eolz", L"12"));
  EXPECT_EQ(L"hello", util::string::translate(L"hello", L"eolz", L""));
  EXPECT_EQ(L"hello", util::string::translate(L"hello", L"", L"12"));
}
