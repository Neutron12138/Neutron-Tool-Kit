#ifndef __NEUTRON_BASE_EXCEPTION_CPP__
#define __NEUTRON_BASE_EXCEPTION_CPP__

#include "Exception.hpp"

namespace ntk
{
    Exception::Exception() {}
    Exception::Exception(const Exception &from) {}
    Exception::~Exception() {}

    Exception &Exception::operator=(const Exception &from)
    {
        return *this;
    }
} // namespace ntk

#endif