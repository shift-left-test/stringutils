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

}  // namespace string

}  // namespace snap

#endif  // INCLUDE_SNAP_STRING_HPP_
