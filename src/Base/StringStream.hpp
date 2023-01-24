#ifndef __NEUTRON_BASE_STRINGSTREAM_HPP__
#define __NEUTRON_BASE_STRINGSTREAM_HPP__

#include "Object.hpp"
#include "String.hpp"
#include "BasicStringStream.hpp"

namespace ntk
{
    /// @brief 字符串流对象，为STL特化
    template <>
    class BasicStringStream<std::char_traits<wchar_t>, std::allocator<wchar_t>> : public Object, public std::wstringstream
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
        /// @brief STL单字节字符串流类型
        using StdStringStreamType = std::stringstream;
        /// @brief STL宽字符字符串流类型
        using StdWStringStreamType = std::wstringstream;
        /// @brief 字符串对象类型
        using StringType = String;
        /// @brief 本对象类型的STL父级类型
        using ParentType = StdWStringStreamType;
        /// @brief 本对象类型
        using SelfType = BasicStringStream<TraitsType, AllocatorType>;

    public:
        BasicStringStream();
        BasicStringStream(const StdStringType &str,
                          std::ios_base::openmode mode = std::ios_base::in | std::ios_base::out);
        BasicStringStream(const StdWStringType &wstr,
                          std::ios_base::openmode mode = std::ios_base::in | std::ios_base::out);
        BasicStringStream(const SelfType &from) = delete;
        ~BasicStringStream();

    public:
        SelfType &operator=(const SelfType &from) = delete;

    public:
        /// @brief 把本对象转换为字符串
        /// @return 字符串
        StringType to_string() const;
    };

    using StringStream = BasicStringStream<std::char_traits<wchar_t>, std::allocator<wchar_t>>;
} // namespace ntk

#endif