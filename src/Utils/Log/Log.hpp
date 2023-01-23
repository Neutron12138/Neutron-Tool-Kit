#ifndef __NEUTRON_UTILS_LOG_HPP__
#define __NEUTRON_UTILS_LOG_HPP__

#include <vector>
#include <iostream>
#include "BasicLog.hpp"

namespace ntk
{
    namespace Utils
    {
        using Log = BasicLog<String, LogItem<String>, std::wostream, std::vector<LogItem<String>>, StringStream>;
    } // namespace Utils

} // namespace ntk

#endif