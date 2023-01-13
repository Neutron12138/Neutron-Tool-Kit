#ifndef __NEUTRON_BASE_STRINGSTREAM_HPP__
#define __NEUTRON_BASE_STRINGSTREAM_HPP__

#include <sstream>
#include "Object.hpp"
#include "String.hpp"

namespace ntk
{
    /// @brief 字符串流对象，继承自std::basic_stringstream。其中_CharT为wchar_t
    /// @tparam m_TraitsType 字符特性类型，默认为std::char_traits<wchar_t>
    /// @tparam m_AllocatorType 分配器类型，默认为std::allocator<wchar_t>
    template <typename m_TraitsType = std::char_traits<wchar_t>, typename m_AllocatorType = std::allocator<wchar_t>>
    class StringStream : public Object, public std::basic_stringstream<wchar_t, m_TraitsType, m_AllocatorType>
    {
    public:
        using CharType = wchar_t;
        using TraitsType = m_TraitsType;
        using AllocatorType = m_AllocatorType;
        using StringType = String<TraitsType, AllocatorType>;
        using ParentType = std::basic_stringstream<CharType, TraitsType, AllocatorType>;
        using SelfType = StringStream<TraitsType, AllocatorType>;

    public:
        StringStream();
        StringStream(const std::basic_string<CharType, TraitsType, AllocatorType> &str,
                     std::ios_base::openmode mode = std::ios_base::in | std::ios_base::out);
        ~StringStream();
    };
} // namespace ntk

#endif