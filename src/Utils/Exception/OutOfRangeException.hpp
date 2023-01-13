#ifndef __NEUTRON_UTILS_OUTOFRANGEEXCEPTION_HPP__
#define __NEUTRON_UTILS_OUTOFRANGEEXCEPTION_HPP__

#include "../../Base/Exception.hpp"

namespace ntk
{
    namespace Utils
    {
        /// @brief 越界访问异常
        class OutOfRangeException : public Exception
        {
        public:
            OutOfRangeException();
            OutOfRangeException(const std::string &why, const std::string &where);
            OutOfRangeException(const OutOfRangeException &from);
            ~OutOfRangeException();

        public:
            OutOfRangeException &operator=(const OutOfRangeException &from);
        };
    } // namespace Utils

} // namespace ntk

#endif