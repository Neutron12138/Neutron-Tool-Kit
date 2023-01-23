#ifndef __NEUTRON_UTILS_TIME_CPP__
#define __NEUTRON_UTILS_TIME_CPP__

#include "Time.hpp"

namespace ntk
{
    namespace Utils
    {
        Time::Time() : m_clocks(0) {}
        Time::Time(clock_t clocks) : m_clocks(clocks) {}
        Time::Time(const Time &from) { *this = from; }
        Time::~Time() {}

        Time &Time::operator=(const Time &from)
        {
            m_clocks = from.m_clocks;
            return *this;
        }

        bool Time::operator==(const Time &another)
        {
            return m_clocks == another.m_clocks;
        }

        bool Time::operator>(const Time &another)
        {
            return m_clocks > another.m_clocks;
        }

        bool Time::operator>=(const Time &another)
        {
            return (*this == another) || (*this > another);
        }

        bool Time::operator<(const Time &another)
        {
            return m_clocks < another.m_clocks;
        }

        bool Time::operator<=(const Time &another)
        {
            return (*this == another) || (*this < another);
        }

        Time Time::operator+(const Time &another)
        {
            return Time(m_clocks + another.m_clocks);
        }

        Time Time::operator-(const Time &another)
        {
            return Time(m_clocks - another.m_clocks);
        }

        Time Time::operator*(const Time &another)
        {
            return Time(m_clocks * another.m_clocks);
        }

        Time Time::operator/(const Time &another)
        {
            return Time(m_clocks / another.m_clocks);
        }

        Time Time::operator%(const Time &another)
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
            return m_clocks;
        }

        clock_t Time::as_clocks() const
        {
            return m_clocks;
        }

        long Time::as_millisecond() const
        {
            // 因为CLOCKS_PER_SEC是1000
            // 所以直接返回m_clocks就行
            return m_clocks;
        }

        float Time::as_seconds() const
        {
            return static_cast<float>(m_clocks) / static_cast<float>(CLOCKS_PER_SEC);
        }

        Time getCurrentTime()
        {
            return Time(clock());
        }
    } // namespace Utils

} // namespace ntk

#endif