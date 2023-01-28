#ifndef __NEUTRON_UTILS_MATHSCONSTANTS_HPP__
#define __NEUTRON_UTILS_MATHSCONSTANTS_HPP__

#include "../../Base/BasicObject.hpp"

namespace ntk
{
    namespace Utils
    {
        /// @brief 数学常量命名空间
        namespace MathsConstants
        {
            /// @brief 圆周率（180度）
            static float const PI = 3.14159f;

            /// @brief 1/2倍圆周率（90度）
            static float const PI_HALF = 0.5f * PI;

            /// @brief 3/2倍圆周率（270度）
            static float const PI_THREE_QUARTER = 0.75f * PI;

            /// @brief 2倍圆周率（360度）
            static float const PI_DOUBLE = 2.0f * PI;

            /// @brief 自然常数
            static float const E = 2.71828f;

            /// @brief 更准确的数值，小数点后15位，用双精度数（double）记录
            namespace exact
            {
                /// @brief 圆周率（180度）
                static double const ePI = 3.141592653589793;

                /// @brief 1/2倍圆周率（90度）
                static double const ePI_HALF = 0.5 * PI;

                /// @brief 3/4倍圆周率（270度）
                static double const ePI_THREE_QUARTER = 0.75 * PI;

                /// @brief 2倍圆周率（360度）
                static double const ePI_DOUBLE = 2.0 * PI;

                /// @brief 自然常数
                static double const eE = 2.718281828459045;
            } // namespace exact

        } // namespace MathsConstants

    } // namespace Utils

} // namespace ntk

#endif