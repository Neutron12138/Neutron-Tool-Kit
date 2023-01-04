#ifndef __NEUTRON_BASE_EXCEPTION_HPP__
#define __NEUTRON_BASE_EXCEPTION_HPP__

// 这个异常类可能不会被用到，因为NTK一般不抛出异常，而是输出日志

#include <string>
#include <exception>
#include "Object.hpp"

namespace ntk
{
    /// @brief 基础异常类
    class Exception : public Object, public std::exception
    {
    public:
        Exception();
        Exception(const Exception &from);
        ~Exception();

    public:
        Exception &operator=(const Exception &from);

    public:
        /// @brief 获取发生了什么异常
        /// @return 异常说明
        virtual const char *what() = 0;

        /// @brief 获取为什么发生此异常
        /// @return 异常原因
        virtual const char *why() = 0;

        /// @brief 获取发生异常的位置在哪（在哪个文件，哪个函数）
        /// @return 异常位置
        virtual const char *where() = 0;
    };
} // namespace ntk

#endif