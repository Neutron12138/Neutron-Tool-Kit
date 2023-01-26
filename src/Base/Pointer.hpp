#ifndef __NEUTRON_BASE_POINTER_HPP__
#define __NEUTRON_BASE_POINTER_HPP__

#include "Object.hpp"

namespace ntk
{
    /// @brief 基础指针类型
    /// @tparam m_DataType 数据类型
    template <typename m_DataType>
    class Pointer : public Object
    {
    public:
        using DataType = m_DataType;
        using SelfType = Pointer<DataType>;

    public:
        Pointer() = default;
        Pointer(const SelfType &from) = default;
        ~Pointer() = default;

    public:
        SelfType &operator=(const SelfType &from) = default;
        virtual DataType &operator*() const;
        virtual DataType *operator->() const;

    public:
        /// @brief 获取指针
        /// @return 指针
        virtual DataType *get() const = 0;

        /// @brief 是否为空指针
        /// @return 是否为空指针
        virtual bool is_nullptr() const;
    };
} // namespace ntk

#endif