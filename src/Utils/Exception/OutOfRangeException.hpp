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
            OutOfRangeException() = default;
            OutOfRangeException(const std::string &why, const std::string &where);
            OutOfRangeException(const OutOfRangeException &from) = default;
            ~OutOfRangeException() = default;

        public:
            OutOfRangeException &operator=(const OutOfRangeException &from) = default;
            operator std::out_of_range();
        };
    } // namespace Utils

} // namespace ntk

#endif