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

            /// @brief 绘制两帧之间所经过的时间
            Utils::Time m_delta_time;

            /// @brief 上次绘制的时间
            Utils::Time m_last_draw_time;

        public:
            Application();
            Application(const Application &from) = default;
            ~Application() = default;

        public:
            Application &operator=(const Application &from) = default;

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

            /// @brief 获取计时器
            /// @return 计时器
            const Utils::Timer &get_timer() const;

            /// @brief 获取绘制两帧之间所经过的时间
            /// @return 绘制两帧之间所经过的时间
            const Utils::Time& get_delta_time() const;

            /// @brief 获取上次绘制的时间
            /// @return 上次绘制的时间
            const Utils::Time& get_last_draw_time() const;

        public:
            /// @brief 当创建时调用
            virtual void onCreated();

            /// @brief 每帧绘制前（调用onDisplay()之前）被调用
            /// @param delta_time 距上一帧所经过的时间
            virtual void onProcess(const Utils::Time &delta_time);

            /// @brief 当窗口显示时调用
            virtual void onDisplay();

            /// @brief 每帧绘制后（调用onDisplay()之后）被调用，用于更新数据
            virtual void onUpdate();

            /// @brief 当窗口销毁时调用
            virtual void onDestroyed();

            /// @brief 当窗口更改大小时调用
            /// @param new_size 窗口更改后的大小
            virtual void onResized(const glm::uvec2 &new_size);

            /// @brief 当按键被按下时调用
            /// @param key 按键（同一个键可能会因为实现不同有不同的值）
            virtual void onKeyPressed(std::uint32_t key);

            /// @brief 当按键被释放时调用
            /// @param key 按键（同一个键可能会因为实现不同有不同的值）
            virtual void onKeyReleased(std::uint32_t key);

            /// @brief 当文本输入时调用
            /// @param unicode 字符统一码
            virtual void onTextEntered(std::uint32_t unicode);
        };
    } // namespace Window

} // namespace ntk

#endif