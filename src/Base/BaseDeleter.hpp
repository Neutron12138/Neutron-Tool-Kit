#ifndef __NEUTRON_BASE_BASEDELETER_HPP__
#define __NEUTRON_BASE_BASEDELETER_HPP__

#include "Object.hpp"

namespace ntk
{
    /// @brief 基础删除器
    /// @tparam m_DataType 指针类型
    template <typename m_DataType>
    class BaseDeleter : public Object
    {
    public:
        using DataType = m_DataType;
        using SelfType = BaseDeleter<DataType>;

    public:
        BaseDeleter();
        BaseDeleter(const SelfType &from);
        ~BaseDeleter();

    public:
        BaseDeleter &operator=(const SelfType &from);
        void operator()(DataType *ptr);
    };

    /// @brief 基础删除器，数组特化型
    /// @tparam m_DataType 指针类型
    template <typename m_DataType>
    class BaseDeleter<m_DataType[]> : public Object
    {
    public:
        using DataType = m_DataType;
        using SelfType = BaseDeleter<DataType[]>;

    public:
        BaseDeleter();
        BaseDeleter(const SelfType &from);
        ~BaseDeleter();

    public:
        BaseDeleter &operator=(const SelfType &from);
        void operator()(DataType *ptr);
    };
} // namespace ntk

#endif