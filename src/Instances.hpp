#ifndef __NEUTRON_INSTANCES_HPP__
#define __NEUTRON_INSTANCES_HPP__

#include <glm/glm.hpp>
#include "Utils/Log/Log.hpp"
#include "Utils/String/StringUtils.hpp"
#include "Utils/Time/Time.hpp"

namespace ntk
{
    /// @brief 静态实例
    namespace Instance
    {
        /// @brief 日志输出器，默认输出到std::cout
        static Utils::Log log;

        /// @brief 字符串工具
        static Utils::StringUtils string_utils;

        /// @brief 单位矩阵2*2
        static glm::mat2 const IdentityMatrix2 = glm::mat2(1.0f);
        /// @brief 单位矩阵3*3
        static glm::mat3 const IdentityMatrix3 = glm::mat3(1.0f);
        /// @brief 单位矩阵4*4
        static glm::mat4 const IdentityMatrix4 = glm::mat4(1.0f);

        /// @brief 0秒
        static Utils::Time const ZeroSecond=Utils::Time(static_cast<clock_t>(0));
        /// @brief 1秒
        static Utils::Time const OneSecond=Utils::Time(static_cast<clock_t>(CLOCKS_PER_SEC));

        
    } // namespace Instance

} // namespace ntk

#endif