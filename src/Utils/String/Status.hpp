#ifndef __NEUTRON_UTILS_SUSTATUS_HPP__
#define __NEUTRON_UTILS_SUSTATUS_HPP__

namespace ntk
{
    namespace Utils
    {
        /// @brief StringUtils类的的状态枚举的命名空间
        namespace StringUtilsStatus
        {
            /// @brief 状态枚举
            enum Status
            {
                /// @brief 失败
                FAILURE,

                /// @brief 成功
                SUCCESS,

                /// @brief 还未被调用
                NOT_CALLED,

                /// @brief 状态总数
                COUNT,
            };
        } // namespace StringUtilsStatus

    } // namespace Utils

} // namespace ntk

#endif