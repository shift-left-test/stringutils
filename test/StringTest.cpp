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


class StringTest : public ::testing::Test {
 protected:
  template <typename T>
  void checkStartsWith(const std::basic_string<T> &text,
                       const T *prefix,
                       const T *suffix,
                       const std::basic_string<T> &blank) {
    EXPECT_TRUE(snap::string::startsWith(text, text));
    EXPECT_TRUE(snap::string::startsWith(text, prefix));
    EXPECT_TRUE(snap::string::startsWith(text, blank));
    EXPECT_TRUE(snap::string::startsWith(blank, blank));
    EXPECT_FALSE(snap::string::startsWith(prefix, text));
    EXPECT_FALSE(snap::string::startsWith(text, suffix));
    EXPECT_FALSE(snap::string::startsWith(blank, text));
  }

  template <typename T>
  void checkEndsWith(const std::basic_string<T> &text,
                     const T *prefix,
                     const T *suffix,
                     const std::basic_string<T> &blank) {
    EXPECT_TRUE(snap::string::endsWith(text, text));
    EXPECT_TRUE(snap::string::endsWith(text, suffix));
    EXPECT_TRUE(snap::string::endsWith(text, blank));
    EXPECT_TRUE(snap::string::endsWith(blank, blank));
    EXPECT_FALSE(snap::string::endsWith(prefix, text));
    EXPECT_FALSE(snap::string::endsWith(text, prefix));
    EXPECT_FALSE(snap::string::endsWith(blank, text));
  }

  template <typename T>
  void checkTransform(const std::basic_string<T> &uppercase,
                      const T *lowercase) {
    EXPECT_EQ(uppercase, snap::string::transform(uppercase, ::toupper));
    EXPECT_EQ(uppercase, snap::string::transform(lowercase, ::toupper));
  }

  template <typename T>
  void checkUppercase(const std::basic_string<T> &uppercase,
                      const T *lowercase,
                      const T *blank) {
    EXPECT_EQ(uppercase, snap::string::uppercase(uppercase));
    EXPECT_EQ(uppercase, snap::string::uppercase(lowercase));
    EXPECT_EQ(blank, snap::string::uppercase(blank));
  }

  template <typename T>
  void checkLowercase(const std::basic_string<T> &uppercase,
                      const T *lowercase,
                      const T *blank) {
    EXPECT_EQ(lowercase, snap::string::lowercase(uppercase));
    EXPECT_EQ(lowercase, snap::string::lowercase(lowercase));
    EXPECT_EQ(blank, snap::string::lowercase(blank));
  }

  template <typename T>
  void checkLstrip(const std::basic_string<T> &rawText,
                   const T *text,
                   const T *space,
                   const std::basic_string<T> &blank) {
    EXPECT_EQ(text, snap::string::lstrip(rawText));
    EXPECT_EQ(text, snap::string::lstrip(text));
    EXPECT_EQ(blank, snap::string::lstrip(space));
    EXPECT_EQ(blank, snap::string::lstrip(blank));
  }

  template <typename T>
  void checkLstripWithChar(const std::basic_string<T> &rawText,
                           const T *text,
                           const T space,
                           const T blank) {
    EXPECT_EQ(text, snap::string::lstrip(rawText, space));
    EXPECT_EQ(text, snap::string::lstrip(text, space));
    EXPECT_EQ(rawText, snap::string::lstrip(rawText, blank));
  }

  template <typename T>
  void checkRstrip(const std::basic_string<T> &rawText,
                   const T *text,
                   const T *space,
                   const std::basic_string<T> &blank) {
    EXPECT_EQ(text, snap::string::rstrip(rawText));
    EXPECT_EQ(text, snap::string::rstrip(text));
    EXPECT_EQ(blank, snap::string::rstrip(space));
    EXPECT_EQ(blank, snap::string::rstrip(blank));
  }

  template <typename T>
  void checkRstripWithChar(const std::basic_string<T> &rawText,
                           const T *text,
                           const T space,
                           const T blank) {
    EXPECT_EQ(text, snap::string::rstrip(rawText, space));
    EXPECT_EQ(text, snap::string::rstrip(text, space));
    EXPECT_EQ(rawText, snap::string::rstrip(rawText, blank));
  }

  template <typename T>
  void checkStrip(const std::basic_string<T> &rawText,
                  const T *text,
                  const T *space,
                  const std::basic_string<T> &blank) {
    EXPECT_EQ(text, snap::string::strip(rawText));
    EXPECT_EQ(text, snap::string::strip(text));
    EXPECT_EQ(blank, snap::string::strip(space));
    EXPECT_EQ(blank, snap::string::strip(blank));
  }

  template <typename T>
  void checkStripWithChar(const std::basic_string<T> &rawText,
                          const T *text,
                          const T space,
                          const T blank) {
    EXPECT_EQ(text, snap::string::strip(rawText, space));
    EXPECT_EQ(text, snap::string::strip(text, space));
    EXPECT_EQ(rawText, snap::string::strip(rawText, blank));
  }

  template <typename T>
  void checkLtrim(const std::basic_string<T> &rawText,
                  const T *text,
                  const T *space,
                  const std::basic_string<T> &blank) {
    EXPECT_EQ(text, snap::string::ltrim(rawText));
    EXPECT_EQ(text, snap::string::ltrim(text));
    EXPECT_EQ(blank, snap::string::ltrim(space));
    EXPECT_EQ(blank, snap::string::ltrim(blank));
  }

  template <typename T>
  void checkLtrimWithChar(const std::basic_string<T> &rawText,
                          const T *text,
                          const T space,
                          const T blank) {
    EXPECT_EQ(text, snap::string::ltrim(rawText, space));
    EXPECT_EQ(text, snap::string::ltrim(text, space));
    EXPECT_EQ(rawText, snap::string::ltrim(rawText, blank));
  }

  template <typename T>
  void checkRtrim(const std::basic_string<T> &rawText,
                  const T *text,
                  const T *space,
                  const std::basic_string<T> &blank) {
    EXPECT_EQ(text, snap::string::rtrim(rawText));
    EXPECT_EQ(text, snap::string::rtrim(text));
    EXPECT_EQ(blank, snap::string::rtrim(space));
    EXPECT_EQ(blank, snap::string::rtrim(blank));
  }

  template <typename T>
  void checkRtrimWithChar(const std::basic_string<T> &rawText,
                          const T *text,
                          const T space,
                          const T blank) {
    EXPECT_EQ(text, snap::string::rtrim(rawText, space));
    EXPECT_EQ(text, snap::string::rtrim(text, space));
    EXPECT_EQ(rawText, snap::string::rtrim(rawText, blank));
  }

  template <typename T>
  void checkTrim(const std::basic_string<T> &rawText,
                 const T *text,
                 const T *space,
                 const std::basic_string<T> &blank) {
    EXPECT_EQ(text, snap::string::trim(rawText));
    EXPECT_EQ(text, snap::string::trim(text));
    EXPECT_EQ(blank, snap::string::trim(space));
    EXPECT_EQ(blank, snap::string::trim(blank));
  }

  template <typename T>
  void checkTrimWithChar(const std::basic_string<T> &rawText,
                         const T *text,
                         const T space,
                         const T blank) {
    EXPECT_EQ(text, snap::string::trim(rawText, space));
    EXPECT_EQ(text, snap::string::trim(text, space));
    EXPECT_EQ(rawText, snap::string::trim(rawText, blank));
  }

  template <typename T>
  void checkContains(const std::basic_string<T> &text,
                     const std::basic_string<T> &capitalized,
                     const T *prefix,
                     const T *suffix,
                     const T *space,
                     const T *blank,
                     const T *weird) {
    EXPECT_TRUE(snap::string::contains(text, text));
    EXPECT_TRUE(snap::string::contains(text, prefix));
    EXPECT_TRUE(snap::string::contains(text, suffix));
    EXPECT_TRUE(snap::string::contains(text, blank));
    EXPECT_FALSE(snap::string::contains(text, capitalized));
    EXPECT_FALSE(snap::string::contains(prefix, text));
    EXPECT_FALSE(snap::string::contains(suffix, text));
    EXPECT_FALSE(snap::string::contains(prefix, suffix));
    EXPECT_FALSE(snap::string::contains(text, weird));
  }

  template <typename T>
  void checkReplaceWithChar(const std::basic_string<T> &rawText,
                            const T *text,
                            const T space,
                            const T delim) {
    EXPECT_EQ(text, snap::string::replace(rawText, delim, space));
    EXPECT_EQ(text, snap::string::replace(text, delim, space));
    EXPECT_EQ(rawText, snap::string::replace(text, space, delim));
    EXPECT_EQ(rawText, snap::string::replace(rawText, space, delim));
  }

  template <typename T>
  void checkReplaceWithString(const std::basic_string<T> &rawText,
                              const T *text,
                              const T *space,
                              const T *delim,
                              const T *blank) {
    EXPECT_EQ(text, snap::string::replace(rawText, delim, space));
    EXPECT_EQ(text, snap::string::replace(text, delim, space));
    EXPECT_EQ(rawText, snap::string::replace(text, space, delim));
    EXPECT_EQ(rawText, snap::string::replace(rawText, space, delim));
    EXPECT_EQ(blank, snap::string::replace(blank, space, delim));
    EXPECT_EQ(rawText, snap::string::replace(rawText, blank, space));
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

TEST_F(StringTest, testStartsWithForU16String) {
  const std::u16string TEXT = u"hello world";
  const char16_t *PREFIX = u"hello";
  const char16_t *SUFFIX = u"world";
  const std::u16string BLANK = u"";
  checkStartsWith(TEXT, PREFIX, SUFFIX, BLANK);
}

TEST_F(StringTest, testStartsWithForU32String) {
  const std::u32string TEXT = U"hello world";
  const char32_t *PREFIX = U"hello";
  const char32_t *SUFFIX = U"world";
  const std::u32string BLANK = U"";
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

TEST_F(StringTest, testEndsWithForU16String) {
  const std::u16string TEXT = u"hello world";
  const char16_t *PREFIX = u"hello";
  const char16_t *SUFFIX = u"world";
  const std::u16string BLANK = u"";
  checkEndsWith(TEXT, PREFIX, SUFFIX, BLANK);
}

TEST_F(StringTest, testEndsWithForU32String) {
  const std::u32string TEXT = U"hello world";
  const char32_t *PREFIX = U"hello";
  const char32_t *SUFFIX = U"world";
  const std::u32string BLANK = U"";
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

TEST_F(StringTest, testTransformForU16String) {
  const std::u16string UPPERCASE = u"HELLO WORLD";
  const char16_t *LOWERCASE = u"hello world";
  checkTransform(UPPERCASE, LOWERCASE);
}

TEST_F(StringTest, testTransformForU32String) {
  const std::u32string UPPERCASE = U"HELLO WORLD";
  const char32_t *LOWERCASE = U"hello world";
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

TEST_F(StringTest, testUppercaseForU16String) {
  const std::u16string UPPERCASE = u"HELLO WORLD";
  const char16_t *LOWERCASE = u"hello world";
  const char16_t *BLANK = u"";
  checkUppercase(UPPERCASE, LOWERCASE, BLANK);
}

TEST_F(StringTest, testUppercaseForU32String) {
  const std::u32string UPPERCASE = U"HELLO WORLD";
  const char32_t *LOWERCASE = U"hello world";
  const char32_t *BLANK = U"";
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

TEST_F(StringTest, testLowercaseForU16String) {
  const std::u16string UPPERCASE = u"HELLO WORLD";
  const char16_t *LOWERCASE = u"hello world";
  const char16_t *BLANK = u"";
  checkLowercase(UPPERCASE, LOWERCASE, BLANK);
}

TEST_F(StringTest, testLowercaseForU32String) {
  const std::u32string UPPERCASE = U"HELLO WORLD";
  const char32_t *LOWERCASE = U"hello world";
  const char32_t *BLANK = U"";
  checkLowercase(UPPERCASE, LOWERCASE, BLANK);
}

TEST_F(StringTest, testLstripForString) {
  const std::string RAW_TEXT = " \t\r hello";
  const char *TEXT = "hello";
  const char *SPACE = " ";
  const std::string BLANK = "";
  checkLstrip(RAW_TEXT, TEXT, SPACE, BLANK);
}

TEST_F(StringTest, testLstripForU8String) {
  const std::string RAW_TEXT = u8" \t\r hello";
  const char *TEXT = u8"hello";
  const char *SPACE = u8" ";
  const std::string BLANK = u8"";
  checkLstrip(RAW_TEXT, TEXT, SPACE, BLANK);
}

TEST_F(StringTest, testLstripForWString) {
  const std::wstring RAW_TEXT = L" \t\r hello";
  const wchar_t *TEXT = L"hello";
  const wchar_t *SPACE = L" ";
  const std::wstring BLANK = L"";
  checkLstrip(RAW_TEXT, TEXT, SPACE, BLANK);
}

TEST_F(StringTest, testLstripForU16String) {
  const std::u16string RAW_TEXT = u" \t\r hello";
  const char16_t *TEXT = u"hello";
  const char16_t *SPACE = u" ";
  const std::u16string BLANK = u"";
  checkLstrip(RAW_TEXT, TEXT, SPACE, BLANK);
}

TEST_F(StringTest, testLstripForU32String) {
  const std::u32string RAW_TEXT = U" \t\r hello";
  const char32_t *TEXT = U"hello";
  const char32_t *SPACE = U" ";
  const std::u32string BLANK = U"";
  checkLstrip(RAW_TEXT, TEXT, SPACE, BLANK);
}

TEST_F(StringTest, testLstripWithCharForString) {
  const std::string RAW_TEXT = "  hello";
  const char *TEXT = "hello";
  const char SPACE = ' ';
  const char BLANK = '\0';
  checkLstripWithChar(RAW_TEXT, TEXT, SPACE, BLANK);
}

TEST_F(StringTest, testLstripWithCharForU8String) {
  const std::string RAW_TEXT = u8"  hello";
  const char *TEXT = u8"hello";
  const char SPACE = ' ';
  const char BLANK = '\0';
  checkLstripWithChar(RAW_TEXT, TEXT, SPACE, BLANK);
}

TEST_F(StringTest, testLstripWithCharForWString) {
  const std::wstring RAW_TEXT = L"  hello";
  const wchar_t *TEXT = L"hello";
  const wchar_t SPACE = L' ';
  const wchar_t BLANK = L'\0';
  checkLstripWithChar(RAW_TEXT, TEXT, SPACE, BLANK);
}

TEST_F(StringTest, testLstripWithCharForU16String) {
  const std::u16string RAW_TEXT = u"  hello";
  const char16_t *TEXT = u"hello";
  const char16_t SPACE = u' ';
  const char16_t BLANK = u'\0';
  checkLstripWithChar(RAW_TEXT, TEXT, SPACE, BLANK);
}

TEST_F(StringTest, testLStripWithCharForU32String) {
  const std::u32string RAW_TEXT = U"  hello";
  const char32_t *TEXT = U"hello";
  const char32_t SPACE = U' ';
  const char32_t BLANK = U'\0';
  checkLstripWithChar(RAW_TEXT, TEXT, SPACE, BLANK);
}

TEST_F(StringTest, testRstripForString) {
  const std::string RAW_TEXT = "hello \r\t ";
  const char *TEXT = "hello";
  const char *SPACE = " ";
  const std::string BLANK = "";
  checkRstrip(RAW_TEXT, TEXT, SPACE, BLANK);
}

TEST_F(StringTest, testRstripForU8String) {
  const std::string RAW_TEXT = u8"hello \r\t ";
  const char *TEXT = u8"hello";
  const char *SPACE = u8" ";
  const std::string BLANK = u8"";
  checkRstrip(RAW_TEXT, TEXT, SPACE, BLANK);
}

TEST_F(StringTest, testRstripForWString) {
  const std::wstring RAW_TEXT = L"hello \r\t ";
  const wchar_t *TEXT = L"hello";
  const wchar_t *SPACE = L" ";
  const std::wstring BLANK = L"";
  checkRstrip(RAW_TEXT, TEXT, SPACE, BLANK);
}

TEST_F(StringTest, testRstripForU16String) {
  const std::u16string RAW_TEXT = u"hello \r\t ";
  const char16_t *TEXT = u"hello";
  const char16_t *SPACE = u" ";
  const std::u16string BLANK = u"";
  checkRstrip(RAW_TEXT, TEXT, SPACE, BLANK);
}

TEST_F(StringTest, testRstripForU32String) {
  const std::u32string RAW_TEXT = U"hello \r\t ";
  const char32_t *TEXT = U"hello";
  const char32_t *SPACE = U" ";
  const std::u32string BLANK = U"";
  checkRstrip(RAW_TEXT, TEXT, SPACE, BLANK);
}

TEST_F(StringTest, testRstripWithCharForString) {
  const std::string RAW_TEXT = "hello  ";
  const char *TEXT = "hello";
  const char SPACE = ' ';
  const char BLANK = '\0';
  checkRstripWithChar(RAW_TEXT, TEXT, SPACE, BLANK);
}

TEST_F(StringTest, testRstripWithCharForU8String) {
  const std::string RAW_TEXT = u8"hello  ";
  const char *TEXT = u8"hello";
  const char SPACE = ' ';
  const char BLANK = '\0';
  checkRstripWithChar(RAW_TEXT, TEXT, SPACE, BLANK);
}

TEST_F(StringTest, testRstripWithCharForWString) {
  const std::wstring RAW_TEXT = L"hello  ";
  const wchar_t *TEXT = L"hello";
  const wchar_t SPACE = L' ';
  const wchar_t BLANK = L'\0';
  checkRstripWithChar(RAW_TEXT, TEXT, SPACE, BLANK);
}

TEST_F(StringTest, testRstripWithCharForU16String) {
  const std::u16string RAW_TEXT = u"hello  ";
  const char16_t *TEXT = u"hello";
  const char16_t SPACE = u' ';
  const char16_t BLANK = u'\0';
  checkRstripWithChar(RAW_TEXT, TEXT, SPACE, BLANK);
}

TEST_F(StringTest, testRstripWithCharForU32String) {
  const std::u32string RAW_TEXT = U"hello  ";
  const char32_t *TEXT = U"hello";
  const char32_t SPACE = U' ';
  const char32_t BLANK = U'\0';
  checkRstripWithChar(RAW_TEXT, TEXT, SPACE, BLANK);
}

TEST_F(StringTest, testStripForString) {
  const std::string RAW_TEXT = "  hello  ";
  const char *TEXT = "hello";
  const char *SPACE = " ";
  const std::string BLANK = "";
  checkStrip(RAW_TEXT, TEXT, SPACE, BLANK);
}

TEST_F(StringTest, testStripForU8String) {
  const std::string RAW_TEXT = u8"  hello  ";
  const char *TEXT = u8"hello";
  const char *SPACE = u8" ";
  const std::string BLANK = u8"";
  checkStrip(RAW_TEXT, TEXT, SPACE, BLANK);
}

TEST_F(StringTest, testStripForWString) {
  const std::wstring RAW_TEXT = L"  hello  ";
  const wchar_t *TEXT = L"hello";
  const wchar_t *SPACE = L" ";
  const std::wstring BLANK = L"";
  checkStrip(RAW_TEXT, TEXT, SPACE, BLANK);
}

TEST_F(StringTest, testStripForU16String) {
  const std::u16string RAW_TEXT = u"  hello  ";
  const char16_t *TEXT = u"hello";
  const char16_t *SPACE = u" ";
  const std::u16string BLANK = u"";
  checkStrip(RAW_TEXT, TEXT, SPACE, BLANK);
}

TEST_F(StringTest, testStripForU32String) {
  const std::u32string RAW_TEXT = U"  hello  ";
  const char32_t *TEXT = U"hello";
  const char32_t *SPACE = U" ";
  const std::u32string BLANK = U"";
  checkStrip(RAW_TEXT, TEXT, SPACE, BLANK);
}

TEST_F(StringTest, testStripWithCharForString) {
  const std::string RAW_TEXT = "  hello  ";
  const char *TEXT = "hello";
  const char SPACE = ' ';
  const char BLANK = '\0';
  checkStripWithChar(RAW_TEXT, TEXT, SPACE, BLANK);
}

TEST_F(StringTest, testStripWithCharForU8String) {
  const std::string RAW_TEXT = u8"  hello  ";
  const char *TEXT = u8"hello";
  const char SPACE = ' ';
  const char BLANK = '\0';
  checkStripWithChar(RAW_TEXT, TEXT, SPACE, BLANK);
}

TEST_F(StringTest, testStripWithCharForWString) {
  const std::wstring RAW_TEXT = L"  hello  ";
  const wchar_t *TEXT = L"hello";
  const wchar_t SPACE = L' ';
  const wchar_t BLANK = L'\0';
  checkStripWithChar(RAW_TEXT, TEXT, SPACE, BLANK);
}

TEST_F(StringTest, testStripWithCharForU16String) {
  const std::u16string RAW_TEXT = u"  hello  ";
  const char16_t *TEXT = u"hello";
  const char16_t SPACE = u' ';
  const char16_t BLANK = u'\0';
  checkStripWithChar(RAW_TEXT, TEXT, SPACE, BLANK);
}

TEST_F(StringTest, testStripWithCharForU32String) {
  const std::u32string RAW_TEXT = U"  hello  ";
  const char32_t *TEXT = U"hello";
  const char32_t SPACE = U' ';
  const char32_t BLANK = U'\0';
  checkStripWithChar(RAW_TEXT, TEXT, SPACE, BLANK);
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

TEST_F(StringTest, testContainsForU16String) {
  const std::u16string TEXT = u"hello world";
  const std::u16string CAPITALIZED = u"HELLO WORLD";
  const char16_t *PREFIX = u"hello";
  const char16_t *SUFFIX = u"world";
  const char16_t *SPACE = u" ";
  const char16_t *BLANK = u"";
  const char16_t *WEIRD = u"?";
  checkContains(TEXT, CAPITALIZED, PREFIX, SUFFIX, SPACE, BLANK, WEIRD);
}

TEST_F(StringTest, testContainsForU32String) {
  const std::u32string TEXT = U"hello world";
  const std::u32string CAPITALIZED = U"HELLO WORLD";
  const char32_t *PREFIX = U"hello";
  const char32_t *SUFFIX = U"world";
  const char32_t *SPACE = U" ";
  const char32_t *BLANK = U"";
  const char32_t *WEIRD = U"?";
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

TEST_F(StringTest, replaceWithCharForU16String) {
  const std::u16string RAW_TEXT = u"hello_world";
  const char16_t *TEXT = u"hello world";
  const char16_t SPACE = u' ';
  const char16_t DELIM = u'_';
  checkReplaceWithChar(RAW_TEXT, TEXT, SPACE, DELIM);
}

TEST_F(StringTest, replaceWithCharForU32String) {
  const std::u32string RAW_TEXT = U"hello_world";
  const char32_t *TEXT = U"hello world";
  const char32_t SPACE = U' ';
  const char32_t DELIM = U'_';
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

TEST_F(StringTest, replaceWithStringForU16String) {
  const std::u16string RAW_TEXT = u" hello__world ";
  const char16_t *TEXT = u" hello  world ";
  const char16_t *SPACE = u"  ";
  const char16_t *DELIM = u"__";
  const char16_t *BLANK = u"";
  checkReplaceWithString(RAW_TEXT, TEXT, SPACE, DELIM, BLANK);
}

TEST_F(StringTest, replaceWithStringForU32String) {
  const std::u32string RAW_TEXT = U" hello__world ";
  const char32_t *TEXT = U" hello  world ";
  const char32_t *SPACE = U"  ";
  const char32_t *DELIM = U"__";
  const char32_t *BLANK = U"";
  checkReplaceWithString(RAW_TEXT, TEXT, SPACE, DELIM, BLANK);
}

TEST_F(StringTest, formatWithArgsForString) {
  const char *FORMAT = "%s %s";
  const std::string ARG1 = "hello";
  const char *ARG2 = "world";
  const char *expected = "hello world";
  EXPECT_EQ(expected, snap::string::format(FORMAT, ARG1, ARG2));
}

TEST_F(StringTest, formatWithArgsForU8String) {
  const char *FORMAT = u8"%s %s";
  const std::string ARG1 = u8"hello";
  const char *ARG2 = u8"world";
  const char *expected = u8"hello world";
  EXPECT_EQ(expected, snap::string::format(FORMAT, ARG1, ARG2));
}

TEST_F(StringTest, formatWithArgsForWString) {
  const wchar_t *FORMAT = L"%S %S";
  const std::wstring ARG1 = L"hello";
  const wchar_t *ARG2 = L"world";
  const wchar_t *expected = L"hello world";
  EXPECT_EQ(expected, snap::string::format(FORMAT, ARG1, ARG2));
}
