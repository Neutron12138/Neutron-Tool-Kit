#ifndef __NEUTRON_UTILS_COLORCHANNELENUM_HPP__
#define __NEUTRON_UTILS_COLORCHANNELENUM_HPP__

#include <stb/stb_image.h>

namespace ntk
{
    namespace Utils
    {
        /// @brief 色彩通道类型枚举的命名空间
        namespace ColorChannel
        {
            /// @brief 色彩通道类型枚举
            enum ColorChannel
            {
                /// @brief 灰度
                GREY = 0,

                /// @brief 灰度、透明
                GA,

                /// @brief 红、绿、蓝
                RGB,

                /// @brief 红、绿、蓝、透明
                RGBA,

                /// @brief 其他类型
                OTHER,

                /// @brief 未知
                UNKNOWN,

                /// @brief 色彩通道类型总数
                COUNT,
            };
        } // namespace ColorChannelEnum

    } // namespace Utils

} // namespace ntk

#endif