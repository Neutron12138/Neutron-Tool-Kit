#ifndef __NEUTRON_BASE_TYPE_HPP__
#define __NEUTRON_BASE_TYPE_HPP__

// 数据类型的头文件

#include <cstdint>

#include <windows.h>

#include <string>

namespace ntk
{
#ifdef UNICODE
    /// @brief 宽字符型字符串
    using String = std::wstring;
    /// @brief 宽字符型字符串流
    using StringStream = std::wstringstream;
#else
    /// @brief 普通字符串
    using String = std::string;
    /// @brief 普通字符串流
    using StringStream = std::stringstream;
#endif
} // namespace ntk

#endif