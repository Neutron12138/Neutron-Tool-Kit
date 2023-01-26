#ifndef __NEUTRON_BASE_STRING_HPP__
#define __NEUTRON_BASE_STRING_HPP__

#include "BasicString.hpp"

namespace ntk
{
    /// @brief 字符串对象，为STL特化
    template <>
    class BasicString<std::char_traits<wchar_t>, std::allocator<wchar_t>> : public Object, public std::wstring
    {
    public:
        /// @brief 字符类型
        using CharType = wchar_t;
        /// @brief 字符特性类型
        using TraitsType = std::char_traits<wchar_t>;
        /// @brief 分配器类型
        using AllocatorType = std::allocator<wchar_t>;
        /// @brief STL单字节字符串类型
        using StdStringType = std::string;
        /// @brief STL宽字符字符串类型
        using StdWStringType = std::wstring;
        /// @brief 本对象类型的STL父级类型
        using ParentType = StdWStringType;
        /// @brief 本对象类型
        using SelfType = BasicString<TraitsType, AllocatorType>;

    public:
        BasicString();
        BasicString(const char *str);
        BasicString(const wchar_t *wstr);
        BasicString(const StdStringType &str);
        BasicString(const StdWStringType &wstr);
        BasicString(const SelfType &from);
        ~BasicString();

    public:
        SelfType &operator=(const char *str);
        SelfType &operator=(const wchar_t *wstr);
        SelfType &operator=(const StdStringType &str);
        SelfType &operator=(const StdWStringType &wstr);
        SelfType &operator=(const SelfType &from);

        operator StdStringType() const;
        operator StdWStringType() const;

    public:
        /// @brief 把本对象转换为单字节字符串
        /// @return 单字节字符串
        StdStringType to_string() const;

        /// @brief 把宽字符字符串转换为单字节字符串
        /// @param wstr 宽字符字符串
        /// @return 单字节字符串
        virtual StdStringType to_string(const StdWStringType &wstr) const;

        /// @brief 把单字节字符串转换为宽字符字符串
        /// @param str 单字节字符串
        /// @return 宽字符字符串
        virtual StdWStringType to_wstring(const StdStringType &str) const;
    };

    using String = BasicString<std::char_traits<wchar_t>, std::allocator<wchar_t>>;

    template <typename m_TraitsType, typename m_AllocatorType>
    std::ostream &operator<<(std::ostream &os, const String &str);
    template <typename m_TraitsType, typename m_AllocatorType>
    std::wostream &operator<<(std::wostream &os, const String &str);
} // namespace ntk

#endif