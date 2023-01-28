#ifndef __NEUTRON_BASE_BASICSTRINGSTREAM_HPP__
#define __NEUTRON_BASE_BASICSTRINGSTREAM_HPP__

#include <sstream>
#include "Object.hpp"
#include "BasicString.hpp"

namespace ntk
{
    /// @brief 字符串流对象，继承自std::basic_stringstream。其中_CharT为wchar_t
    /// @tparam m_TraitsType 字符特性类型，默认为std::char_traits<wchar_t>
    /// @tparam m_AllocatorType 分配器类型，默认为std::allocator<wchar_t>
    template <typename m_TraitsType, typename m_AllocatorType>
    class BasicStringStream : public Object, public std::basic_stringstream<wchar_t, m_TraitsType, m_AllocatorType>
    {
    public:
        /// @brief 字符类型
        using CharType = wchar_t;
        /// @brief 字符特性类型
        using TraitsType = m_TraitsType;
        /// @brief 分配器类型
        using AllocatorType = m_AllocatorType;
        /// @brief STL单字节字符串类型
        using StdStringType = std::basic_string<char, TraitsType, AllocatorType>;
        /// @brief STL宽字符字符串类型
        using StdWStringType = std::basic_string<wchar_t, TraitsType, AllocatorType>;
        /// @brief STL单字节字符串流类型
        using StdStringStreamType = std::basic_stringstream<char, TraitsType, AllocatorType>;
        /// @brief STL宽字符字符串流类型
        using StdWStringStreamType = std::basic_stringstream<wchar_t, TraitsType, AllocatorType>;
        /// @brief 字符串对象类型
        using StringType = BasicString<TraitsType, AllocatorType>;
        /// @brief 本对象类型的STL父级类型
        using ParentType = StdWStringStreamType;
        /// @brief 本对象类型
        using SelfType = BasicStringStream<TraitsType, AllocatorType>;

    public:
        BasicStringStream() = default;
        BasicStringStream(const StdStringType &str,
                          std::ios_base::openmode mode = std::ios_base::in | std::ios_base::out);
        BasicStringStream(const StdWStringType &wstr,
                          std::ios_base::openmode mode = std::ios_base::in | std::ios_base::out);
        BasicStringStream(const SelfType &from) = delete;
        ~BasicStringStream() = default;

    public:
        SelfType &operator=(const SelfType &from) = delete;

    public:
        /// @brief 把本对象转换为字符串
        /// @return 字符串
        StringType to_string() const;
    };
} // namespace ntk

#endif