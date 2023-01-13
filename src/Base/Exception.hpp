#ifndef __NEUTRON_BASE_EXCEPTION_HPP__
#define __NEUTRON_BASE_EXCEPTION_HPP__

// 这个异常类可能不会被用到，因为NTK一般不抛出异常，而是输出日志

#include <string>
#include <iostream>
#include "Object.hpp"

namespace ntk
{
    /// @brief 基础异常类
    class Exception : public Object
    {
    protected:
        std::string m_what;
        std::string m_why;
        std::string m_where;

    public:
        Exception();
        Exception(const std::string &what, const std::string &why, const std::string &where);
        Exception(const Exception &from);
        ~Exception();

    public:
        Exception &operator=(const Exception &from);

    public:
        /// @brief 获取发生了什么异常
        /// @return 异常说明
        virtual const std::string &what() const;

        /// @brief 获取为什么发生异常
        /// @return 异常原因
        virtual const std::string &why() const;

        /// @brief 获取发生异常的位置在哪（在哪个文件，哪个函数）
        /// @return 异常位置
        virtual const std::string &where() const;
    };

    std::ostream &operator<<(std::ostream &os,const Exception& exception);
} // namespace ntk

#endif