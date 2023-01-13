#ifndef __NEUTRON_INSTANCES_HPP__
#define __NEUTRON_INSTANCES_HPP__

#include <glm/glm.hpp>
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

        /// @brief 单位矩阵2*2
        static const glm::mat2 IdentityMatrix2 = glm::mat2(1.0f);
        /// @brief 单位矩阵3*3
        static const glm::mat3 IdentityMatrix3 = glm::mat3(1.0f);
        /// @brief 单位矩阵4*4
        static const glm::mat4 IdentityMatrix4 = glm::mat4(1.0f);
    } // namespace Instance

} // namespace ntk

#endif