#ifndef __NEUTRON_INSTANCES_HPP__
#define __NEUTRON_INSTANCES_HPP__

#include "Utils/Log/Log.hpp"
#include "Utils/String/StringUtils.hpp"

namespace ntk
{
    /// @brief 静态实例
    namespace Instance
    {
        /// @brief 日志输出器，默认输出到std::cout
        static Utils::Log log;

        /// @brief 字符串工具
        static Utils::StringUtils string_utils;
    } // namespace Instance

} // namespace ntk

#endif