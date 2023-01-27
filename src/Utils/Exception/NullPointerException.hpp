#ifndef __NEUTRON_UTILS_NULLPOINTEREXCEPTION_HPP__
#define __NEUTRON_UTILS_NULLPOINTEREXCEPTION_HPP__

#include "../../Base/Exception.hpp"

namespace ntk
{
    namespace Utils
    {
        /// @brief 空指针异常
        class NullPointerException : public Exception
        {
        public:
            NullPointerException() = default;
            NullPointerException(const std::string &where);
            NullPointerException(const NullPointerException &from) = default;
            ~NullPointerException() = default;

        public:
            NullPointerException &operator=(const NullPointerException &from) = default;
        };
    } // namespace Utils

} // namespace ntk

#endif