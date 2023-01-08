#ifndef __NEUTRON_UTILS_TIME_HPP__
#define __NEUTRON_UTILS_TIME_HPP__

#include <ctime>
#include "../../Base/Object.hpp"

namespace ntk
{
    namespace Utils
    {
        /// @brief 时间类
        class Time : public Object
        {
        private:
            clock_t m_clocks;

        public:
            Time();
            Time(clock_t clocks);
            Time(const Time &from);
            ~Time();

        public:
            Time &operator=(const Time &from);
            bool operator==(const Time &another);
            bool operator>(const Time &another);
            bool operator>=(const Time &another);
            bool operator<(const Time &another);
            bool operator<=(const Time &another);
            Time operator+(const Time &another);
            Time operator-(const Time &another);
            Time operator*(const Time &another);
            Time operator/(const Time &another);
            Time operator%(const Time &another);
            Time &operator+=(const Time &another);
            Time &operator-=(const Time &another);
            Time &operator*=(const Time &another);
            Time &operator/=(const Time &another);
            Time &operator%=(const Time &another);
            operator clock_t() const;

        public:
            /// @brief 转换为clock_t
            /// @return 转换结果
            clock_t as_clocks() const;

            /// @brief 转换为毫秒
            /// @return 转换结果
            long as_millisecond() const;

            /// @brief 转换为秒
            /// @return 转换结果
            float as_seconds() const;
        };

        /// @brief 0秒
        static const Time ZeroSecond(0);

        /// @brief 1秒
        static const Time OneSecond(CLOCKS_PER_SEC);

        /// @brief 获取当前时间
        /// @return 当前时间
        Time getCurrentTime();
    } // namespace Utils

} // namespace ntk

#endif