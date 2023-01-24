#ifndef __NEUTRON_BASE_BASICDELETER_HPP__
#define __NEUTRON_BASE_BASICDELETER_HPP__

#include "Object.hpp"

namespace ntk
{
    /// @brief 基础删除器
    /// @tparam m_DataType 指针类型
    template <typename m_DataType>
    class BasicDeleter : public Object
    {
    public:
        using DataType = m_DataType;
        using SelfType = BasicDeleter<DataType>;

    public:
        BasicDeleter() = default;
        BasicDeleter(const SelfType &from) = default;
        ~BasicDeleter() = default;

    public:
        BasicDeleter &operator=(const SelfType &from) = default;
        virtual void operator()(DataType *ptr) const;
    };

    /// @brief 基础删除器，数组特化型
    /// @tparam m_DataType 指针类型
    template <typename m_DataType>
    class BasicDeleter<m_DataType[]> : public Object
    {
    public:
        using DataType = m_DataType;
        using SelfType = BasicDeleter<DataType[]>;

    public:
        BasicDeleter() = default;
        BasicDeleter(const SelfType &from) = default;
        ~BasicDeleter() = default;

    public:
        BasicDeleter &operator=(const SelfType &from) = default;
        virtual void operator()(DataType *ptr) const;
    };
} // namespace ntk

#endif