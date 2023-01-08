#ifndef __NEUTRON_BASE_BASEDELETER_CPP__
#define __NEUTRON_BASE_BASEDELETER_CPP__

#include "BaseDeleter.hpp"

namespace ntk
{
    template <typename m_DataType>
    BaseDeleter<m_DataType>::BaseDeleter() {}
    template <typename m_DataType>
    BaseDeleter<m_DataType>::BaseDeleter(const BaseDeleter<m_DataType> &from) {}
    template <typename m_DataType>
    BaseDeleter<m_DataType>::~BaseDeleter() {}
    template <typename m_DataType>
    BaseDeleter<m_DataType> &BaseDeleter<m_DataType>::operator=(const BaseDeleter<m_DataType> &from) { return *this; }

    template <typename m_DataType>
    void BaseDeleter<m_DataType>::operator()(m_DataType *ptr)
    {
        delete ptr;
    }

    template <typename m_DataType>
    BaseDeleter<m_DataType[]>::BaseDeleter() {}
    template <typename m_DataType>
    BaseDeleter<m_DataType[]>::BaseDeleter(const BaseDeleter<m_DataType[]> &from) {}
    template <typename m_DataType>
    BaseDeleter<m_DataType[]>::~BaseDeleter() {}
    template <typename m_DataType>
    BaseDeleter<m_DataType[]> &BaseDeleter<m_DataType[]>::operator=(const BaseDeleter<m_DataType[]> &from) { return *this; }

    template <typename m_DataType>
    void BaseDeleter<m_DataType[]>::operator()(m_DataType *ptr)
    {
        delete[] ptr;
    }
} // namespace ntk

#endif