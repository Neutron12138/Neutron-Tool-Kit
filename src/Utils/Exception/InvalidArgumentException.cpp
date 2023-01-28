#ifndef __NEUTRON_UTILS_INVALIDARGUMENTEXCEPTION_CPP__
#define __NEUTRON_UTILS_INVALIDARGUMENTEXCEPTION_CPP__

#include "InvalidArgumentException.hpp"

namespace ntk
{
    namespace Utils
    {
        InvalidArgumentException::InvalidArgumentException(const std::string &why, const std::string &where) : Exception("invalid argument", why, where) {}
    } // namespace Utils

} // namespace ntk

#endif