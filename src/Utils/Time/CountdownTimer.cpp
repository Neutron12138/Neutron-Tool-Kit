#ifndef __NEUTRON_UTILS_COUNTDOWNTIMER_CPP__
#define __NEUTRON_UTILS_COUNTDOWNTIMER_CPP__

#include <future>
#include "CountdownTimer.hpp"

namespace ntk
{
    namespace Utils
    {
        const Time &CountdownTimer::get_starting_time() const
        {
            if (m_is_started)
                return m_starting_time;
            else
                return Instance::ZeroSecond;
        }

        const Time &CountdownTimer::get_duration() const
        {
            return m_duration;
        }

        const Time &CountdownTimer::get_time_remaining() const
        {
            if (m_is_started)
                return m_time_remaining;
            else
                return Instance::ZeroSecond;
        }

        bool CountdownTimer::is_started() const
        {
            return m_is_started;
        }

        CountdownTimer::CountdownType CountdownTimer::get_countdown_type() const
        {
            return m_countdown_type;
        }

        CountdownTimer &CountdownTimer::set_duration(const Time &duration)
        {
            reset();
            m_duration = duration;
            return *this;
        }

        CountdownTimer &CountdownTimer::start(CountdownType countdown_type)
        {
            m_is_started = true;
            m_starting_time = get_current_time();
            m_time_remaining = m_duration;
            m_countdown_type = countdown_type;

            onStarted();

            if (m_countdown_type == CountdownType::Block)
                run();
            else
                m_thread = std::async(std::launch::async, &run, this);

            return *this;
        }

        CountdownTimer &CountdownTimer::stop()
        {
            m_is_started = false;
            onStoped();
            return *this;
        }

        CountdownTimer &CountdownTimer::restart()
        {
            start();
            onRestarted();
            return *this;
        }

        CountdownTimer &CountdownTimer::reset()
        {
            m_starting_time = Instance::ZeroSecond;
            m_duration = Instance::ZeroSecond;
            m_time_remaining = Instance::ZeroSecond;
            m_is_started = false;
            m_countdown_type = CountdownType::Unknown;
            return *this;
        }

        void CountdownTimer::run()
        {
            // 上次循环时间
            Time last_time = get_current_time();

            // 检查剩余时间是否大于0
            while (m_time_remaining.as_clocks() > 0)
            {
                if (!m_is_started)
                    return;

                // 获取当前时间
                const Time current_time = get_current_time();
                // 获取时间差
                const Time delta_time = current_time - last_time;
                // 减少剩余时间
                m_time_remaining -= delta_time;
                // 调用onLoop()
                onLoop(delta_time);
                // 更新上次循环时间
                last_time = current_time;
            }

            // 倒计时结束
            onTimeUp();
        }

        void CountdownTimer::onStarted() {}
        void CountdownTimer::onStoped() {}
        void CountdownTimer::onRestarted() {}
        void CountdownTimer::onTimeUp() {}
        void CountdownTimer::onLoop(const Time &delta_time) {}
    } // namespace Utils

} // namespace ntk

#endif