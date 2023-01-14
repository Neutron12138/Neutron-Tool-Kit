#ifndef __NEUTRON_BASE_OBJECT_HPP__
#define __NEUTRON_BASE_OBJECT_HPP__

#include <string>

namespace ntk
{
    /// @brief 对象类
    class Object
    {
    public:
        Object();
        Object(const Object &from);
        ~Object();

    public:
        Object &operator=(const Object &from);

    public:
        /// @brief 转换为字符串
        /// @return 转换后的结果，默认为地址
        virtual std::string as_string() const;
    };
} // namespace ntk

#endif
