#ifndef __NEUTRON_BASE_EXCEPTION_CPP__
#define __NEUTRON_BASE_EXCEPTION_CPP__

#include <sstream>
#include <stdexcept>
#include "Exception.hpp"

namespace ntk
{
    Exception::Exception(const std::string &what, const std::string &why, const std::string &where) : m_what(what), m_why(why), m_where(where) {}

    const std::string &Exception::what() const
    {
        return m_what;
    }

    const std::string &Exception::why() const
    {
        return m_why;
    }

    const std::string &Exception::where() const
    {
        return m_where;
    }

    std::ostream &operator<<(std::ostream &os, const Exception &exception)
    {
        os << "Exception:" << std::endl
           << "what:" << exception.what() << std::endl
           << "why:" << exception.why() << std::endl
           << "where:" << exception.where() << std::endl;
        return os;
    }
} // namespace ntk

#endif