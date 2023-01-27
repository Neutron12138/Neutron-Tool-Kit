#ifndef __NEUTRON_UTILS_TIME_CPP__
#define __NEUTRON_UTILS_TIME_CPP__

#include "Time.hpp"

namespace ntk
{
    namespace Utils
    {
        Time::Time(clock_t clocks) : m_clocks(clocks) {}

        Time::Time(float seconds)
        {
            m_clocks = static_cast<clock_t>(seconds * static_cast<float>(CLOCKS_PER_SEC));
        }

        bool Time::operator==(const Time &another) const
        {
            return m_clocks == another.m_clocks;
        }

        bool Time::operator>(const Time &another) const
        {
            return m_clocks > another.m_clocks;
        }

        bool Time::operator>=(const Time &another) const
        {
            return (*this == another) || (*this > another);
        }

        bool Time::operator<(const Time &another) const
        {
            return m_clocks < another.m_clocks;
        }

        bool Time::operator<=(const Time &another) const
        {
            return (*this == another) || (*this < another);
        }

        Time Time::operator+(const Time &another) const
        {
            return Time(m_clocks + another.m_clocks);
        }

        Time Time::operator-(const Time &another) const
        {
            return Time(m_clocks - another.m_clocks);
        }

        Time Time::operator*(const Time &another) const
        {
            return Time(m_clocks * another.m_clocks);
        }

        Time Time::operator/(const Time &another) const
        {
            return Time(m_clocks / another.m_clocks);
        }

        Time Time::operator%(const Time &another) const
        {
            return Time(m_clocks % another.m_clocks);
        }

        Time &Time::operator+=(const Time &another)
        {
            *this = *this + another;
            return *this;
        }

        Time &Time::operator-=(const Time &another)
        {
            *this = *this - another;
            return *this;
        }

        Time &Time::operator*=(const Time &another)
        {
            *this = *this * another;
            return *this;
        }

        Time &Time::operator/=(const Time &another)
        {
            *this = *this / another;
            return *this;
        }

        Time &Time::operator%=(const Time &another)
        {
            *this = *this % another;
            return *this;
        }

        Time::operator clock_t() const
        {
            return as_clocks();
        }

        Time::operator float() const
        {
            return as_seconds();
        }

        clock_t Time::as_clocks() const
        {
            return m_clocks;
        }

        long Time::as_milliseconds() const
        {
            return static_cast<long>(static_cast<float>(m_clocks) / static_cast<float>(CLOCKS_PER_SEC) * 1000.0f);
        }

        float Time::as_seconds() const
        {
            return static_cast<float>(m_clocks) / static_cast<float>(CLOCKS_PER_SEC);
        }

        Time get_current_time()
        {
            return Time(clock());
        }
    } // namespace Utils

} // namespace ntk

#endif