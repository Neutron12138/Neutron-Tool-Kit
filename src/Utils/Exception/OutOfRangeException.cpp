#ifndef __NEUTRON_UTILS_OUTOFRANGEEXCEPTION_CPP__
#define __NEUTRON_UTILS_OUTOFRANGEEXCEPTION_CPP__

#include <sstream>
#include "OutOfRangeException.hpp"

namespace ntk
{
    namespace Utils
    {
        OutOfRangeException::OutOfRangeException(const std::string &why, const std::string &where) : Exception("out of range", why, where) {}

        OutOfRangeException::operator std::out_of_range()
        {
            std::stringstream sstr;
            sstr << *this;
            return std::out_of_range(sstr.str());
        }
    } // namespace Utils

} // namespace ntk

#endif