#ifndef __NEUTRON_UTILS_COUNTDOWNTIMER_HPP__
#define __NEUTRON_UTILS_COUNTDOWNTIMER_HPP__

// 我并发了解的不多，所以这里没有加锁，不建议使用
#warning Not recommended

#include "../../Base/Object.hpp"
#include "Time.hpp"

namespace ntk
{
    namespace Utils
    {
        /// @brief 倒计时器
        class CountdownTimer : public Object
        {
        private:
            /// @brief 倒计时的开始时间
            Time m_starting_time;

            /// @brief 倒计时的时长
            Time m_duration;

            /// @brief 剩余时间
            Time m_time_remaining;

            /// @brief 倒计时器是否已经开始
            bool m_is_started;

        public:
            CountdownTimer();
            CountdownTimer(const CountdownTimer &from);
            ~CountdownTimer();

        public:
            CountdownTimer &operator=(const CountdownTimer &from);

        public:
            /// @brief 获取开始时间（如果已经开始）
            /// @return 倒计时开始时间，如果尚未开始则返回0
            const Time &get_starting_time() const;

            /// @brief 获取倒计时时长
            /// @return 倒计时时长
            const Time &get_duration() const;

            /// @brief 获取剩余时间（如果已经开始）
            /// @return 剩余时间，未开始则返回0
            const Time &get_time_remaining() const;

            /// @brief 获取是否已经开始
            /// @return 是否已经开始
            bool is_started() const;

        public:
            /// @brief 设置倒计时时长，这会终止当前倒计时（如果已经开始）
            /// @param duration 倒计时时长
            /// @return 本对象
            CountdownTimer &set_duration(const Time &duration);

            /// @brief 开始倒计时
            /// @return 本对象
            CountdownTimer &start();

            /// @brief 停止倒计时
            /// @return 本对象
            CountdownTimer &stop();

            /// @brief 重新开始倒计时
            /// @return 本对象
            CountdownTimer &restart();

            /// @brief 重置倒计时器
            /// @return 本对象
            CountdownTimer &reset();

            /// @brief 倒计时器运行函数
            virtual void run();

        public:
            /// @brief 当开始时调用
            virtual void onStarted();

            /// @brief 当停止时调用
            virtual void onStoped();

            /// @brief 当重新启动时调用
            virtual void onRestarted();

            /// @brief 当倒计时结束时调用
            virtual void onTimeUp();

            /// @brief 当每次循环时调用
            /// @param delta_time 距上一次调用的时间
            virtual void onLoop(const Time& delta_time);
        };
    } // namespace Utils

} // namespace ntk

#endif