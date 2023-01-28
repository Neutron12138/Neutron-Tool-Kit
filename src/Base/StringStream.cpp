#ifndef __NEUTRON_BASE_STRINGSTREAM_CPP__
#define __NEUTRON_BASE_STRINGSTREAM_CPP__

#include <sstream>
#include "StringStream.hpp"

namespace ntk
{
    BasicStringStream<std::char_traits<wchar_t>, std::allocator<wchar_t>>::BasicStringStream(const typename BasicStringStream<std::char_traits<wchar_t>, std::allocator<wchar_t>>::StdStringType &str,
                                                                                             std::ios_base::openmode mode) : BasicStringStream<std::char_traits<wchar_t>, std::allocator<wchar_t>>::ParentType(BasicStringStream<std::char_traits<wchar_t>, std::allocator<wchar_t>>::StdWStringType(), mode) { *this << str; }
    BasicStringStream<std::char_traits<wchar_t>, std::allocator<wchar_t>>::BasicStringStream(const typename BasicStringStream<std::char_traits<wchar_t>, std::allocator<wchar_t>>::StdWStringType &wstr,
                                                                                             std::ios_base::openmode mode) : BasicStringStream<std::char_traits<wchar_t>, std::allocator<wchar_t>>::ParentType(wstr, mode) {}

    typename BasicStringStream<std::char_traits<wchar_t>, std::allocator<wchar_t>>::StringType BasicStringStream<std::char_traits<wchar_t>, std::allocator<wchar_t>>::to_string() const
    {
        typename BasicStringStream<std::char_traits<wchar_t>, std::allocator<wchar_t>>::StdWStringType string = BasicStringStream<std::char_traits<wchar_t>, std::allocator<wchar_t>>::ParentType::str();
        typename BasicStringStream<std::char_traits<wchar_t>, std::allocator<wchar_t>>::StringType result(string);
        return result;
    }
} // namespace ntk

#endif