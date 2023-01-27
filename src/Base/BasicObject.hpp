#ifndef __NEUTRON_BASE_BASICOBJECT_HPP__
#define __NEUTRON_BASE_BASICOBJECT_HPP__

namespace ntk
{
    /// @brief 基础对象类，所有NTK对象的基类
    class alignas(1) BasicObject
    {
    public:
        /// @brief 自身类型
        using SelfType = BasicObject;

    public:
        constexpr BasicObject() noexcept = default;
        constexpr BasicObject(const SelfType &from) noexcept = default;
        ~BasicObject() noexcept = default;

    public:
        constexpr SelfType &operator=(const SelfType &from) noexcept = default;
    };
} // namespace ntk

#endif