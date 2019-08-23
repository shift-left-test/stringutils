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

template <typename T>
inline bool startsWith(const std::basic_string<T> &haystack,
                       const std::basic_string<T> &needle) {
  return std::equal(needle.begin(), needle.end(), haystack.begin());
}

template <typename T>
inline bool startsWith(const T *haystack, const std::basic_string<T> &needle) {
  return startsWith(std::basic_string<T>(haystack), needle);
}

template <typename T>
inline bool startsWith(const std::basic_string<T> &haystack, const T *needle) {
  return startsWith(haystack, std::basic_string<T>(needle));
}

template <typename T>
inline bool startsWith(const T *haystack, const T *needle) {
  return startsWith(std::basic_string<T>(haystack),
                    std::basic_string<T>(needle));
}

template <typename T>
inline bool endsWith(const std::basic_string<T> &haystack,
                     const std::basic_string<T> &needle) {
  return std::equal(needle.rbegin(), needle.rend(), haystack.rbegin());
}

template <typename T>
inline bool endsWith(const T *haystack, const std::basic_string<T> &needle) {
  return endsWith(std::basic_string<T>(haystack), needle);
}

template <typename T>
inline bool endsWith(const std::basic_string<T> &haystack, const T *needle) {
  return endsWith(haystack, std::basic_string<T>(needle));
}

template <typename T>
inline bool endsWith(const T *haystack, const T *needle) {
  return endsWith(std::basic_string<T>(haystack),
                  std::basic_string<T>(needle));
}

template <typename T, class UnaryPredicate>
inline std::basic_string<T> transform(std::basic_string<T> s,
                                      UnaryPredicate pred) {
  std::transform(s.begin(), s.end(), s.begin(), pred);
  return s;
}

template <typename T, class UnaryPredicate>
inline std::basic_string<T> transform(const T *s,
                                      UnaryPredicate pred) {
  return transform(std::basic_string<T>(s), pred);
}

template <typename T>
inline std::basic_string<T> uppercase(const std::basic_string<T> &s) {
  return transform(s, ::toupper);
}

template <typename T>
inline std::basic_string<T> uppercase(const T *s) {
  return uppercase(std::basic_string<T>(s));
}

template <typename T>
inline std::basic_string<T> lowercase(const std::basic_string<T> &s) {
  return transform(s, ::tolower);
}

template <typename T>
inline std::basic_string<T> lowercase(const T *s) {
  return lowercase(std::basic_string<T>(s));
}

template <typename T>
inline std::basic_string<T> lstrip(const std::basic_string<T> &s) {
  auto first = std::find_if_not(s.begin(), s.end(), ::isspace);
  auto last = s.end();
  return std::basic_string<T>(first, last);
}

template <typename T>
inline std::basic_string<T> lstrip(const T *s) {
  return lstrip(std::basic_string<T>(s));
}

template <typename T>
inline std::basic_string<T> lstrip(const std::basic_string<T> &s, const T ch) {
  auto first = std::find_if_not(s.begin(), s.end(), [&](T c) {
      return ch == c;
    });
  auto last = s.end();
  return std::basic_string<T>(first, last);
}

template <typename T>
inline std::basic_string<T> lstrip(const T *s, const T ch) {
  return lstrip(std::basic_string<T>(s), ch);
}

template <typename T>
inline std::basic_string<T> rstrip(const std::basic_string<T> &s) {
  auto first = s.begin();
  auto last = std::find_if_not(s.rbegin(), s.rend(), ::isspace).base();
  return std::basic_string<T>(first, last);
}

template <typename T>
inline std::basic_string<T> rstrip(const T *s) {
  return rstrip(std::basic_string<T>(s));
}

template <typename T>
inline std::basic_string<T> rstrip(const std::basic_string<T> &s, const T ch) {
  auto first = s.begin();
  auto last = std::find_if_not(s.rbegin(), s.rend(), [&](T c) {
      return ch == c;
    }).base();
  return std::basic_string<T>(first, last);
}

template <typename T>
inline std::basic_string<T> rstrip(const T *s, const T ch) {
  return rstrip(std::basic_string<T>(s), ch);
}

template <typename T>
inline std::basic_string<T> strip(const std::basic_string<T> &s) {
  return lstrip(rstrip(s));
}

template <typename T>
inline std::basic_string<T> strip(const T *s) {
  return lstrip(rstrip(std::basic_string<T>(s)));
}

template <typename T>
inline std::basic_string<T> strip(const std::basic_string<T> &s, const T ch) {
  return lstrip(rstrip(s, ch), ch);
}

template <typename T>
inline std::basic_string<T> strip(const T *s, const T ch) {
  return strip(std::basic_string<T>(s), ch);
}

template <typename T>
inline bool contains(const std::basic_string<T> &haystack,
                     const std::basic_string<T> &needle) {
  return haystack.find(needle) != std::string::npos;
}

template <typename T>
inline bool contains(const T *haystack, const std::basic_string<T> &needle) {
  return contains(std::basic_string<T>(haystack), needle);
}

template <typename T>
inline bool contains(const std::basic_string<T> &haystack, const T *needle) {
  return contains(haystack, std::basic_string<T>(needle));
}

template <typename T>
inline bool contains(const T *haystack, const T *needle) {
  return contains(std::basic_string<T>(haystack), std::basic_string<T>(needle));
}

}  // namespace string

}  // namespace snap

#endif  // INCLUDE_SNAP_STRING_HPP_
