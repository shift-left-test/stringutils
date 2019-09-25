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
#include <cstddef>
#include <cwchar>
#include <algorithm>
#include <memory>
#include <sstream>
#include <string>
#include <vector>

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

template <typename T, typename UnaryPredicate>
inline std::basic_string<T> ltrim(const std::basic_string<T> &s,
                                  UnaryPredicate pred) {
  auto first = std::find_if_not(s.begin(), s.end(), pred);
  auto last = s.end();
  return std::basic_string<T>(first, last);
}

template <typename T, typename UnaryPredicate>
inline std::basic_string<T> ltrim(const T* s, UnaryPredicate pred) {
  return ltrim(std::basic_string<T>(s), pred);
}

template <typename T>
inline std::basic_string<T> ltrim(const std::basic_string<T> &s) {
  return ltrim(s, [](unsigned char c) { return std::isspace(c); });
}

template <typename T>
inline std::basic_string<T> ltrim(const T* s) {
  return ltrim(std::basic_string<T>(s));
}

template <typename T>
inline std::basic_string<T> ltrim(const std::basic_string<T> &s, const T ch) {
  return ltrim(s, [&](const T c) { return ch == c; });
}

template <typename T>
inline std::basic_string<T> ltrim(const T *s, const T ch) {
  return ltrim(std::basic_string<T>(s), ch);
}

template <typename T, typename UnaryPredicate>
inline std::basic_string<T> rtrim(const std::basic_string<T> &s,
                                  UnaryPredicate pred) {
  auto first = s.begin();
  auto last = std::find_if_not(s.rbegin(), s.rend(), pred).base();
  return std::basic_string<T>(first, last);
}

template <typename T, typename UnaryPredicate>
inline std::basic_string<T> rtrim(const T *s, UnaryPredicate pred) {
  return rtrim(std::basic_string<T>(s), pred);
}

template <typename T>
inline std::basic_string<T> rtrim(const std::basic_string<T> &s) {
  return rtrim(s, [](unsigned char c) { return std::isspace(c); });
}

template <typename T>
inline std::basic_string<T> rtrim(const T *s) {
  return rtrim(std::basic_string<T>(s));
}

template <typename T>
inline std::basic_string<T> rtrim(const std::basic_string<T> &s, const T ch) {
  return rtrim(s, [&](unsigned char c) { return ch == c; });
}

template <typename T>
inline std::basic_string<T> rtrim(const T *s, const T ch) {
  return rtrim(std::basic_string<T>(s), ch);
}

template <typename T, typename UnaryPredicate>
inline std::basic_string<T> trim(const std::basic_string<T> &s,
                                 UnaryPredicate pred) {
  return ltrim(rtrim(s, pred), pred);
}

template <typename T, typename UnaryPredicate>
inline std::basic_string<T> trim(const T *s, UnaryPredicate pred) {
  return trim(std::basic_string<T>(s), pred);
}

template <typename T>
inline std::basic_string<T> trim(const std::basic_string<T> &s) {
  return trim(s, [](unsigned char c) { return std::isspace(c); });
}

template <typename T>
inline std::basic_string<T> trim(const T *s) {
  return trim(std::basic_string<T>(s));
}

template <typename T>
inline std::basic_string<T> trim(const std::basic_string<T> &s, const T ch) {
  return trim(s, [&](unsigned char c) { return ch == c; });
}

template <typename T>
inline std::basic_string<T> trim(const T *s, const T ch) {
  return trim(std::basic_string<T>(s), ch);
}

template <typename T, typename UnaryPredicate>
inline std::basic_string<T> lstrip(const std::basic_string<T> &s,
                                   UnaryPredicate pred) {
  return ltrim(s, pred);
}

template <typename T, typename UnaryPredicate>
inline std::basic_string<T> lstrip(const T* s, UnaryPredicate pred) {
  return ltrim(s, pred);
}

template <typename T>
inline std::basic_string<T> lstrip(const std::basic_string<T> &s) {
  return ltrim(s);
}

template <typename T>
inline std::basic_string<T> lstrip(const T* s) {
  return ltrim(s);
}

template <typename T>
inline std::basic_string<T> lstrip(const std::basic_string<T> &s, const T ch) {
  return ltrim(s, ch);
}

template <typename T>
inline std::basic_string<T> lstrip(const T *s, const T ch) {
  return ltrim(s, ch);
}

template <typename T, typename UnaryPredicate>
inline std::basic_string<T> rstrip(const std::basic_string<T> &s,
                                   UnaryPredicate pred) {
  return rtrim(s, pred);
}

template <typename T, typename UnaryPredicate>
inline std::basic_string<T> rstrip(const T *s, UnaryPredicate pred) {
  return rtrim(s, pred);
}

template <typename T>
inline std::basic_string<T> rstrip(const std::basic_string<T> &s) {
  return rtrim(s);
}

template <typename T>
inline std::basic_string<T> rstrip(const T *s) {
  return rtrim(s);
}

template <typename T>
inline std::basic_string<T> rstrip(const std::basic_string<T> &s, const T ch) {
  return rtrim(s, ch);
}

template <typename T>
inline std::basic_string<T> rstrip(const T *s, const T ch) {
  return rtrim(s, ch);
}

template <typename T, typename UnaryPredicate>
inline std::basic_string<T> strip(const std::basic_string<T> &s,
                                  UnaryPredicate pred) {
  return trim(s, pred);
}

template <typename T, typename UnaryPredicate>
inline std::basic_string<T> strip(const T *s, UnaryPredicate pred) {
  return trim(s, pred);
}

template <typename T>
inline std::basic_string<T> strip(const std::basic_string<T> &s) {
  return trim(s);
}

template <typename T>
inline std::basic_string<T> strip(const T *s) {
  return trim(s);
}

template <typename T>
inline std::basic_string<T> strip(const std::basic_string<T> &s, const T ch) {
  return trim(s, ch);
}

template <typename T>
inline std::basic_string<T> strip(const T *s, const T ch) {
  return trim(s, ch);
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

template <typename T>
inline std::basic_string<T> replace(std::basic_string<T> s,
                                    const T from, const T to) {
  std::replace(s.begin(), s.end(), from, to);
  return s;
}

template <typename T>
inline std::basic_string<T> replace(const T *s, const T from, const T to) {
  return replace(std::basic_string<T>(s), from, to);
}

template <typename T>
inline std::basic_string<T> replace(std::basic_string<T> s,
                                    const std::basic_string<T> &from,
                                    const std::basic_string<T> &to) {
  if (from.empty()) {
    return s;
  }
  std::size_t position = 0;
  while ((position = s.find(from, position)) != std::string::npos) {
    s.replace(position, from.length(), to);
    position += to.length();
  }
  return s;
}

template <typename T>
inline std::basic_string<T> replace(const T *s,
                                    const std::basic_string<T> &from,
                                    const std::basic_string<T> &to) {
  return replace(std::basic_string<T>(s), from, to);
}

template <typename T>
inline std::basic_string<T> replace(std::basic_string<T> s,
                                    const T *from,
                                    const std::basic_string<T> &to) {
  return replace(s, std::basic_string<T>(from), to);
}

template <typename T>
inline std::basic_string<T> replace(std::basic_string<T> s,
                                    const std::basic_string<T> &from,
                                    const T *to) {
  return replace(s, from, std::basic_string<T>(to));
}

template <typename T>
inline std::basic_string<T> replace(const T *s,
                                    const T *from,
                                    const std::basic_string<T> &to) {
  return replace(std::basic_string<T>(s), std::basic_string<T>(from), to);
}

template <typename T>
inline std::basic_string<T> replace(const T *s,
                                    const std::basic_string<T> &from,
                                    const T *to) {
  return replace(std::basic_string<T>(s), from, std::basic_string<T>(to));
}

template <typename T>
inline std::basic_string<T> replace(std::basic_string<T> s,
                                    const T *from,
                                    const T *to) {
  return replace(s, std::basic_string<T>(from), std::basic_string<T>(to));
}

template <typename T>
inline std::basic_string<T> replace(const T *s,
                                    const T *from,
                                    const T *to) {
  return replace(std::basic_string<T>(s),
                 std::basic_string<T>(from),
                 std::basic_string<T>(to));
}


namespace internal {

template <typename T>
inline T to_const(const T& data) {
  return data;
}

template <typename T>
inline const T * to_const(const std::basic_string<T> &data) {
  return data.c_str();
}

}  // namespace internal

template <typename ... Args>
inline std::basic_string<char> format(const char *fmt, const Args& ... args) {
  std::size_t size = std::snprintf(nullptr, 0, fmt,
                                   internal::to_const(args) ...) + 1;
  std::unique_ptr<char[]> buf(new char[size]);
  std::snprintf(buf.get(), size, fmt, internal::to_const(args) ...);
  return std::basic_string<char>(buf.get(), size - 1);
}

template <typename ... Args>
inline std::basic_string<char> format(const std::basic_string<char> &fmt,
                                      const Args& ... args) {
  return format(fmt.c_str(), args ...);
}

template <typename ... Args>
inline std::basic_string<wchar_t> format(const wchar_t *fmt,
                                         const Args& ... args) {
  // Used a fixed size buffer, since unable to predict the required size
  wchar_t buf[65535] = {};
  std::swprintf(buf, sizeof(buf), fmt, internal::to_const(args) ...);
  return std::basic_string<wchar_t>(buf);
}

template <typename ... Args>
inline std::basic_string<wchar_t> format(const std::basic_string<wchar_t> &fmt,
                                         const Args& ... args) {
  return format(fmt.c_str(), args ...);
}

template <typename T>
inline std::vector<std::basic_string<T>> split(const std::basic_string<T> &s,
                                               const T delim = ' ') {
  std::vector<std::basic_string<T>> tokens;
  std::basic_istringstream<T> ss;
  ss.str(s);
  std::basic_string<T> token;
  while (std::getline(ss, token, delim)) {
    tokens.emplace_back(token);
  }
  return tokens;
}

template <typename T>
inline std::vector<std::basic_string<T>> split(const T *s,
                                               const T delim = ' ') {
  return split(std::basic_string<T>(s), delim);
}

template <typename T>
inline std::basic_string<T>
join(const std::vector<std::basic_string<T>> &tokens,
     const std::basic_string<T> &delim) {
  std::basic_string<T> s;
  for (auto it = tokens.begin(); it != tokens.end(); it++) {
    s.append(*it);
    if (it != std::prev(tokens.end())) {
      s.append(delim);
    }
  }
  return s;
}

template <typename T>
inline std::basic_string<T>
join(const std::vector<std::basic_string<T>> &tokens, const T *delim) {
  return join(tokens, std::basic_string<T>(delim));
}

}  // namespace string

}  // namespace snap

#endif  // INCLUDE_SNAP_STRING_HPP_
