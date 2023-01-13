#ifndef __NEUTRON_UTILS_OUTOFRANGEEXCEPTION_CPP__
#define __NEUTRON_UTILS_OUTOFRANGEEXCEPTION_CPP__

#include "OutOfRangeException.hpp"

namespace ntk
{
    namespace Utils
    {
        OutOfRangeException::OutOfRangeException() : Exception() {}
        OutOfRangeException::OutOfRangeException(const std::string &why, const std::string &where) : Exception("out of range", why, where) {}
        OutOfRangeException::OutOfRangeException(const OutOfRangeException &from) { *this = from; }
        OutOfRangeException::~OutOfRangeException() {}

        OutOfRangeException &OutOfRangeException::operator=(const OutOfRangeException &from)
        {
            Exception::operator=(from);
            return *this;
        }
    } // namespace Utils

} // namespace ntk

#endif