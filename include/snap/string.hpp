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

#ifndef INCLUDE_SNAP_STRING_HPP_
#define INCLUDE_SNAP_STRING_HPP_

#include <cctype>
#include <algorithm>
#include <string>

namespace snap {

namespace string {

inline bool startsWith(const std::string &haystack,
                       const std::string &needle) {
  return std::equal(needle.begin(), needle.end(), haystack.begin());
}

inline bool startsWith(const std::wstring &haystack,
                       const std::wstring &needle) {
  return std::equal(needle.begin(), needle.end(), haystack.begin());
}

inline bool endsWith(const std::string &haystack,
                     const std::string &needle) {
  return std::equal(needle.rbegin(), needle.rend(), haystack.rbegin());
}

inline bool endsWith(const std::wstring &haystack,
                     const std::wstring &needle) {
  return std::equal(needle.rbegin(), needle.rend(), haystack.rbegin());
}

template <class UnaryPredicate>
inline std::string transform(std::string s, UnaryPredicate pred) {
  std::transform(s.begin(), s.end(), s.begin(), pred);
  return s;
}

template <class UnaryPredicate>
inline std::wstring transform(std::wstring s, UnaryPredicate pred) {
  std::transform(s.begin(), s.end(), s.begin(), pred);
  return s;
}

inline std::string uppercase(const std::string &s) {
  return transform(s, ::toupper);
}

inline std::wstring uppercase(const std::wstring &s) {
  return transform(s, ::toupper);
}

inline std::string lowercase(const std::string &s) {
  return transform(s, ::tolower);
}

inline std::wstring lowercase(const std::wstring &s) {
  return transform(s, ::tolower);
}

template <class UnaryPredicate>
inline std::string lstrip(const std::string &s, UnaryPredicate pred) {
  auto wsfront = std::find_if_not(s.begin(), s.end(), pred);
  auto wsback = s.end();
  return std::string(wsfront, wsback);
}

inline std::string lstrip(const std::string &s) {
  return lstrip(s, ::isspace);
}

inline std::string lstrip(const std::string &s, char ch) {
  return lstrip(s, [&](char c) {
      return ch == c;
    });
}

template <class UnaryPredicate>
inline std::wstring lstrip(const std::wstring &s, UnaryPredicate pred) {
  auto wsfront = std::find_if_not(s.begin(), s.end(), pred);
  auto wsback = s.end();
  return std::wstring(wsfront, wsback);
}

inline std::wstring lstrip(const std::wstring &s) {
  return lstrip(s, ::isspace);
}

inline std::wstring lstrip(const std::wstring &s, wchar_t ch) {
  return lstrip(s, [&](wchar_t c) {
      return ch == c;
    });
}

template <class UnaryPredicate>
inline std::string rstrip(const std::string &s, UnaryPredicate pred) {
  auto wsfront = s.begin();
  auto wsback = std::find_if_not(s.rbegin(), s.rend(), pred).base();
  return std::string(wsfront, wsback);
}

inline std::string rstrip(const std::string &s) {
  return rstrip(s, ::isspace);
}

inline std::string rstrip(const std::string &s, char ch) {
  return rstrip(s, [&](char c) {
      return ch == c;
    });
}

template <class UnaryPredicate>
inline std::wstring rstrip(const std::wstring &s, UnaryPredicate pred) {
  auto wsfront = s.begin();
  auto wsback = std::find_if_not(s.rbegin(), s.rend(), pred).base();
  return std::wstring(wsfront, wsback);
}

inline std::wstring rstrip(const std::wstring &s) {
  return rstrip(s, ::isspace);
}

inline std::wstring rstrip(const std::wstring &s, wchar_t ch) {
  return rstrip(s, [&](wchar_t c) {
      return ch == c;
    });
}

inline std::string strip(const std::string &s) {
  return lstrip(rstrip(s));
}

inline std::string strip(const std::string &s, char ch) {
  return lstrip(rstrip(s, ch), ch);
}

inline std::wstring strip(const std::wstring &s) {
  return lstrip(rstrip(s));
}

inline std::wstring strip(const std::wstring &s, wchar_t ch) {
  return lstrip(rstrip(s, ch), ch);
}

inline bool contains(const std::string &haystack, const std::string &needle) {
  return haystack.find(needle) != std::string::npos;
}

inline bool contains(const std::wstring &haystack, const std::wstring &needle) {
  return haystack.find(needle) != std::string::npos;
}

}  // namespace string

}  // namespace snap

#endif  // INCLUDE_SNAP_STRING_HPP_
