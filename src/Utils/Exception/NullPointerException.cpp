#ifndef __NEUTRON_UTILS_NULLPOINTEREXCEPTION_CPP__
#define __NEUTRON_UTILS_NULLPOINTEREXCEPTION_CPP__

#include "NullPointerException.hpp"

namespace ntk
{
    namespace Utils
    {
        NullPointerException::NullPointerException(const std::string &where) : Exception("null pointer", "You tried to access a null pointer", where) {}
    } // namespace Utils

} // namespace ntk

#endif