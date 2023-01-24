#ifndef __NEUTRON_GRAPHICS_DRAWTYPE_HPP__
#define __NEUTRON_GRAPHICS_DRAWTYPE_HPP__

#include "../GL.hpp"

namespace ntk
{
    namespace Graphics
    {
        /// @brief 绘制类型
        namespace DrawType
        {
            /// @brief 绘制类型
            enum DrawType
            {
                /// @brief 以glDrawArrays()绘制
                Arrays = 0,

                /// @brief 以glDrawElements()绘制
                Elements,

                /// @brief 以glDrawArraysInstanced()绘制
                ArraysInstanced,

                /// @brief 以glDrawElementsInstanced()绘制
                ElementsInstanced,

                /// @brief 总数
                Count,
            };
        } // namespace DrawType

    } // namespace Graphics

} // namespace ntk

#endif