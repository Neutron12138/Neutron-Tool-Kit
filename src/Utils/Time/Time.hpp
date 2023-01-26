#ifndef __NEUTRON_UTILS_TIME_HPP__
#define __NEUTRON_UTILS_TIME_HPP__

#include <ctime>
#include <future>
#include "../../Base/Object.hpp"

namespace ntk
{
    namespace Utils
    {
        /// @brief 时间类
        class Time : public Object
        {
        private:
            /// @brief 时刻数
            clock_t m_clocks = 0;

        public:
            constexpr Time() = default;
            explicit Time(clock_t clocks);
            explicit Time(float seconds);
            Time(const Time &from) = default;
            ~Time() = default;

        public:
            Time &operator=(const Time &from) = default;
            bool operator==(const Time &another) const;
            bool operator>(const Time &another) const;
            bool operator>=(const Time &another) const;
            bool operator<(const Time &another) const;
            bool operator<=(const Time &another) const;
            Time operator+(const Time &another) const;
            Time operator-(const Time &another) const;
            Time operator*(const Time &another) const;
            Time operator/(const Time &another) const;
            Time operator%(const Time &another) const;
            Time &operator+=(const Time &another);
            Time &operator-=(const Time &another);
            Time &operator*=(const Time &another);
            Time &operator/=(const Time &another);
            Time &operator%=(const Time &another);
            operator clock_t() const;
            operator float() const;

        public:
            /// @brief 转换为clock_t
            /// @return 转换结果
            clock_t as_clocks() const;

            /// @brief 转换为毫秒
            /// @return 转换结果
            long as_milliseconds() const;

            /// @brief 转换为秒
            /// @return 转换结果
            float as_seconds() const;
        };

        /// @brief 获取当前时间
        /// @return 当前时间
        Time get_current_time();
    } // namespace Utils

} // namespace ntk

#endif