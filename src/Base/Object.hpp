#ifndef __NEUTRON_BASE_OBJECT_HPP__
#define __NEUTRON_BASE_OBJECT_HPP__

#include <string>
#include "BasicObject.hpp"

namespace ntk
{
    /// @brief 对象类，有虚函数表
    class alignas(1) Object : public BasicObject
    {
    public:
        /// @brief 自身类型
        using SelfType = Object;
        /// @brief 父类类型
        using ParentType = BasicObject;

    public:
        constexpr Object() noexcept = default;
        constexpr Object(const SelfType &from) noexcept = default;
        ~Object() noexcept = default;

    public:
        constexpr SelfType &operator=(const SelfType &from) noexcept = default;

    public:
        /// @brief 转换为字符串
        /// @return 转换后的结果，默认为地址
        virtual std::string as_string() const;
    };
} // namespace ntk

#endif
