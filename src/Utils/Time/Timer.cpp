#ifndef __NEUTRON_UTILS_TIMER_CPP__
#define __NEUTRON_UTILS_TIMER_CPP__

#include "Timer.hpp"

namespace ntk
{
    namespace Utils
    {
        Timer::Timer() : m_total_time(0), m_starting_time(0), m_is_started(false), m_during_time(0) {}
        Timer::Timer(const Timer &from) { *this = from; }
        Timer::~Timer() {}

        Timer &Timer::operator=(const Timer &from)
        {
            m_total_time = from.m_total_time;
            m_starting_time = from.m_starting_time;
            m_is_started = from.m_is_started;
            m_during_time = from.m_during_time;
            return *this;
        }

        Timer &Timer::start()
        {
            if (!m_is_started)
            {
                m_is_started = true;
                m_starting_time = getCurrentTime();
            }
            return *this;
        }

        Timer &Timer::stop()
        {
            if (m_is_started)
            {
                m_is_started = false;
                Time current_time = getCurrentTime();
                m_during_time = current_time - m_starting_time;
                m_total_time += m_during_time;
            }
            return *this;
        }

        Timer &Timer::reset()
        {
            m_total_time = ZeroSecond;
            m_starting_time = ZeroSecond;
            m_is_started = false;
            m_during_time = ZeroSecond;
            return *this;
        }

        Time Timer::get_total_time()
        {
            return m_total_time;
        }

        Time Timer::get_starting_time()
        {
            return m_starting_time;
        }

        bool Timer::is_started()
        {
            return m_is_started;
        }

        Time Timer::get_during_time()
        {
            return m_during_time;
        }
    } // namespace Utils

} // namespace ntk

#endif