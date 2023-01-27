#ifndef __NEUTRON_UTILS_INVALIDARGUMENTEXCEPTION_HPP__
#define __NEUTRON_UTILS_INVALIDARGUMENTEXCEPTION_HPP__

#include "../../Base/Exception.hpp"

namespace ntk
{
    namespace Utils
    {
        /// @brief 无效参数异常
        class InvalidArgumentException : public Exception
        {
        public:
            using SelfType = InvalidArgumentException;

        public:
            InvalidArgumentException() = default;
            InvalidArgumentException(const std::string &why, const std::string &where);
            InvalidArgumentException(const SelfType &from) = default;
            ~InvalidArgumentException() = default;

        public:
            SelfType &operator=(const SelfType &from) = default;
        };
    } // namespace Utils

} // namespace ntk

#endif