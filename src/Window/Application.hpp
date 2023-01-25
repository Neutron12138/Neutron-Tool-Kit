#ifndef __NEUTRON_WINDOW_APPLICATION_HPP__
#define __NEUTRON_WINDOW_APPLICATION_HPP__

#include <glm/glm.hpp>
#include "../Base/Object.hpp"
#include "../Base/Type.hpp"
#include "../Utils/Time/Timer.hpp"

namespace ntk
{
    namespace Window
    {
        class Application : public Object
        {
        protected:
            /// @brief 是否正在运行
            bool m_is_running;

            /// @brief 退出码
            int m_exit_code;

            /// @brief 计时器
            Utils::Timer m_timer;

        public:
            Application();
            Application(const Application &from);
            ~Application();

        public:
            Application &operator=(const Application &from);

        public:
            /// @brief 运行
            /// @return 返回值
            virtual int run() = 0;

            /// @brief 获取鼠标位置
            /// @return 鼠标的位置
            virtual glm::ivec2 get_mouse_position() = 0;

            /// @brief 退出程序
            /// @param code 退出码
            virtual void quit(int code = EXIT_SUCCESS);

        public:
            /// @brief 获取是否正在运行
            /// @return 是否正在运行
            bool is_running() const;

            /// @brief 获取退出码，请在结束后调用，否则为0
            /// @return 退出码
            int get_exit_code() const;

            const Utils::Timer& get_timer() const;

        public:
            /// @brief 当创建时调用
            virtual void onCreated();

            /// @brief 当窗口显示时调用
            virtual void onDisplay();

            /// @brief 当窗口销毁时调用
            virtual void onDestroyed();

            /// @brief 当窗口更改大小时调用
            /// @param new_size 窗口更改后的大小
            virtual void onResized(const glm::uvec2& new_size);

            /// @brief 当按键被按下时调用
            virtual void onKeyPressed(uint8_t key);
        };
    } // namespace Window

} // namespace ntk

#endif