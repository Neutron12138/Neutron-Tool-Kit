#ifndef __NEUTRON_UTILS_COUNTDOWNTIMER_CPP__
#define __NEUTRON_UTILS_COUNTDOWNTIMER_CPP__

#include <future>
#include "CountdownTimer.hpp"

namespace ntk
{
    namespace Utils
    {
        CountdownTimer::CountdownTimer() : m_starting_time(0), m_duration(0), m_time_remaining(0), m_is_started(false) {}
        CountdownTimer::CountdownTimer(const CountdownTimer &from) { *this = from; }
        CountdownTimer::~CountdownTimer() {}

        CountdownTimer &CountdownTimer::operator=(const CountdownTimer &from)
        {
            m_starting_time = from.m_starting_time;
            m_duration = from.m_duration;
            m_time_remaining = from.m_time_remaining;
            m_is_started = from.m_is_started;
            return *this;
        }

        const Time &CountdownTimer::get_starting_time() const
        {
            if (m_is_started)
                return m_starting_time;
            else
                return ZeroSecond;
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
                return ZeroSecond;
        }

        bool CountdownTimer::is_started() const
        {
            return m_is_started;
        }

        CountdownTimer &CountdownTimer::set_duration(const Time &duration)
        {
            reset();
            m_duration = duration;
            return *this;
        }

        CountdownTimer &CountdownTimer::start()
        {
            m_is_started = true;
            m_starting_time = getCurrentTime();
            m_time_remaining = m_duration;
            // 防止倒计时阻塞主线程
            std::future<void> thread = std::async(std::launch::async, &run, this);
            onStarted();
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
            m_starting_time = ZeroSecond;
            m_duration = ZeroSecond;
            m_time_remaining = ZeroSecond;
            m_is_started = false;
            return *this;
        }

        void CountdownTimer::run()
        {
            Time last_time = getCurrentTime();
            while (m_is_started && m_time_remaining.as_clocks() > 0)
            {
                Time current_time = getCurrentTime();
                Time delta_time = current_time - last_time;
                m_time_remaining -= delta_time;
                onLoop(delta_time);
                last_time = current_time;
            }
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