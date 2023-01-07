#ifndef __NEUTRON_WINDOW_EVENTENUM_HPP__
#define __NEUTRON_WINDOW_EVENTENUM_HPP__

namespace ntk
{
    namespace Window
    {
        /// @brief 事件枚举
        namespace EventEnum
        {
            /// @brief 鼠标按键枚举
            enum MouseButton
            {
                /// @brief 鼠标左键
                LEFT,

                /// @brief 鼠标滚轮
                MIDDLE,

                /// @brief 鼠标右键
                RIGHT,

                /// @brief 按键总数
                MBCount,
            };
        } // namespace EventEnum

    } // namespace Window

} // namespace ntk

#endif